import pywhatkit as kit
from datetime import datetime, timedelta
import time
import pyautogui

# Replace the following with the actual phone number and message
phone_number = ""  # Phone Number including the country code
message = "Hello, this is a test message sent using PyWhatKit!"

current_time = datetime.now()
send_time = current_time + timedelta(minutes=1) 

# Send the message
kit.sendwhatmsg(phone_number, message, send_time.hour, send_time.minute)
time.sleep(5)
pyautogui.press('enter')