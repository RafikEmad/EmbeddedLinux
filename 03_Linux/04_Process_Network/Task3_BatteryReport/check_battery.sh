#!/bin/bash
DISPLAY=:1
export XAUTHORITY=/run/user/1000/gdm/Xauthority
export XDG_RUNTIME_DIR=/run/user/$(id -u)

# Get battery percentage
battery_percentage=$(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep "percentage:" | awk '{print $2}' | tr -d '%')

# Set the threshold for a "full" battery
full_threshold=90

# Check if the battery is full
if [ "$battery_percentage" -ge "$full_threshold" ]; then
    # Send a notification for a full battery
    notify-send "Battery Status" "Battery is at $battery_percentage%. Status: Full"
else
    # Send a notification for a non-full battery
    notify-send "Battery Status" "Battery is at $battery_percentage%. Status: Not Full"
fi
