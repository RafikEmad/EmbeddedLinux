import webbrowser

facebook_link = "https://www.facebook.com/"
youtube_link = "https://www.youtube.com/"
goole_link = "https://www.google.com/"
chess_link = "https://www.chess.com/"
linkedin_link = "https://www.linkedin.com/"

def firefox(WebsiteName):
    webbrowser.open(WebsiteName)
    # if (WebsiteName.lower()=="Facebook".lower()):
    #     webbrowser.open(facebook_link)
    # elif (WebsiteName.lower()=="Youtube".lower()):
    #     webbrowser.open(youtube_link)
    # elif (WebsiteName.lower()=="Google".lower()):
    #     webbrowser.open(goole_link)
    # elif (WebsiteName.lower()=="Chess".lower()):
    #     webbrowser.open(chess_link)
    # elif (WebsiteName.lower()=="Linkedin".lower()):
    #     webbrowser.open(linkedin_link)
    # else:
    #     print("Given Url not in your Favourites")
