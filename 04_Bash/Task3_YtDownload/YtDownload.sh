#!/bin/bash

# Prompt user for the YouTube URL
read -p "Enter the YouTube URL: " url

# Download the video using youtube-dl
youtube-dl -f 'bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]/best' "$url"
