import speech_recognition as sr
import datetime
import requests
from bs4 import BeautifulSoup
import googlemaps

# Initialize the recognizer
recognizer = sr.Recognizer()

# Initialize the Google Maps API client (you'll need an API key)
gmaps = googlemaps.Client(key='YOUR_API_KEY')

# Function to capture voice input and convert it to text
def get_voice_input():
    with sr.Microphone() as source:
        print("Listening...")
        try:
            audio = recognizer.listen(source, timeout=5)
            text = recognizer.recognize_google(audio)
            return text
        except sr.WaitTimeoutError:
            return "Timeout: No speech detected."
        except sr.UnknownValueError:
            return "Sorry, I could not understand what you said."
        except sr.RequestError as e:
            return f"Error with the speech recognition service: {e}"

# Function to generate a text-based response
def get_response(user_input):
    user_input = user_input.lower()

    if "hello" in user_input:
        return "Hello! How can I assist you?"
    elif "how are you" in user_input:
        return "I'm just a text-based assistant, but I'm here to help."
    elif "bye" in user_input:
        return "Goodbye! Have a great day!"
    elif "time" in user_input:
        current_time = datetime.datetime.now().strftime("%H:%M:%S")
        return f"The current time is {current_time}."
    elif "search" in user_input:
        # Extract the search query from the user input
        query = user_input.replace("search", "").strip()
        if query:
            search_results = perform_search(query)
            return search_results
        else:
            return "Please provide a search query."
    elif "guide to" in user_input:
        place_name = user_input.replace("guide to", "").strip()
        if place_name:
            guide = get_guide_to_place(place_name)
            return guide
        else:
            return "Please specify a place for the guide."
    else:
        return "I'm a simple text-based assistant. How can I assist you?"

# Function to perform a web search and return search results
def perform_search(query):
    search_url = f"https://www.google.com/search?q={query}"
    
    try:
        response = requests.get(search_url)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        search_results = soup.find_all("div", class_="tF2Cxc")
        if search_results:
            return search_results[0].get_text()
        else:
            return "No search results found."
    except requests.exceptions.RequestException as e:
        return f"Error performing the search: {e}"

# Function to get a guide to a place using Google Maps API
def get_guide_to_place(place_name):
    try:
        # Perform a geocode request to get the place details
        geocode_result = gmaps.geocode(place_name)

        if geocode_result:
            place_details = geocode_result[0]
            formatted_address = place_details.get("formatted_address", "Address not found.")
            place_type = place_details.get("types", [])
            place_type_str = ", ".join(place_type)
            
            return f"Here's a guide to {place_name}:\nType: {place_type_str}\nAddress: {formatted_address}"
        else:
            return "Place not found."
    except googlemaps.exceptions.ApiError as e:
        return f"Error getting place details: {e}"

# Main loop for voice interaction
while True:
    user_input = get_voice_input()
    print("You said:", user_input)

    response = get_response(user_input)
    print("Assistant:", response)

    if "exit" in user_input.lower():
        break

# End the program
print("Assistant: Goodbye!")
