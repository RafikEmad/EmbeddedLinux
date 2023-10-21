import re

address_pattern = r'\d+\s*,\s*[A-Za-z. ]+,\s*[A-Za-z, ]+'

addresses = [
    "22, St. Salah Salem, Giza",
    "123, Elm Street, New York",
    "3, Main St., Los Angeles",
    "5, Oak Avenue, San Francisco",
    "10, Park Ave, Washington, D.C.",
    "42, John St., Chicago",
    "7, 1st St., Boston",
    "15, High Street, London, UK",
    "14, Baker St., London, UK",
    "123 Elm Street, Invalid Address",
    "No Number, Invalid Address",
]

for address in addresses:
    if re.match(address_pattern, address):
        print("Valid address:", address)