import psutil
from plyer import notification

def get_battery_info():
    battery = psutil.sensors_battery()
    plugged = battery.power_plugged
    percent = battery.percent
    return plugged, percent

def notify_battery():
    plugged, percent = get_battery_info()

    if plugged:
        status = "Charging"
    else:
        status = "Not Charging"

    notification_title = f"Battery {status}"
    notification_message = f"Battery level: {percent}%"

    notification.notify(
        title=notification_title,
        message=notification_message,
        app_name="Battery Notification",
        timeout=10
    )

if __name__ == "__main__":
    notify_battery()
