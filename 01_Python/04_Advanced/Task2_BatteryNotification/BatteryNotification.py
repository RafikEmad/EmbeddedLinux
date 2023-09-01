from plyer import notification
import psutil
battery = psutil.sensors_battery()
percent = battery.percent
print(percent)
message = f"{percent}% Percent Remaining"
title = "Battery Percentage"
notification.notify(
    title=title,
    message=message,
    timeout=10
)