import webbrowser
import requests

url = "https://www.boredapi.com/api/activity"

response = requests.get(url)

if response.status_code == 200:
    data_dict = response.json()
    print(data_dict)
else:
    print("Failed to fetch data")

