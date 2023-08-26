import webbrowser
import requests

url = "https://api.ipify.org/?format=json"
webbrowser.open(url)
response = requests.get(url)
Ip_Address = ""
# if response.status_code == 200:
#     data_dict = response.json()
#     #print(data_dict)
#     Ip_Address = data_dict["ip"]
#     print(Ip_Address)
#     url2 = f"https://ipinfo.io/{Ip_Address}/geo"
#     webbrowser.open(url2)
#     response = requests.get(url2)
#     if response.status_code == 200:
#         data = response.json()
#         print(data)
# else:
#     print("Failed to fetch data")

def GetIp(DestinationLink):
    response = requests.get(DestinationLink)
    if response.status_code == 200:
        data_dict = response.json()
        Ip_Address = data_dict["ip"]
        print(Ip_Address)
    else:
        print("Failed to fetch data")

def GetLocation(Destination):
    response = requests.get(Destination)
    if response.status_code == 200:
        data_dict = response.json()
        print(data_dict)
    else:
        print("Failed to fetch data")

GetIp(url)
url2 = f"https://ipinfo.io/{Ip_Address}/geo"
GetLocation(url2)