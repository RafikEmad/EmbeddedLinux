import FavWebsites

my_set = {
    "Facebook",
    "Youtube",
    "Google",
    "Chess",
    "Linkedin"
}
set_string = ", ".join(my_set)
URL = input(f"Select one the following favourite websites to open\n {set_string}\n")

if (URL.lower()=="Facebook".lower()):
    FavWebsites.firefox(FavWebsites.facebook_link)
elif (URL.lower()=="Youtube".lower()):
    FavWebsites.firefox(FavWebsites.youtube_link)
elif (URL.lower()=="Google".lower()):
    FavWebsites.firefox(FavWebsites.goole_link)
elif (URL.lower()=="Chess".lower()):
    FavWebsites.firefox(FavWebsites.chess_link)
elif (URL.lower()=="Linkedin".lower()):
    FavWebsites.firefox(FavWebsites.linkedin_link)
else:
    print("Given Url not in your Favourites")