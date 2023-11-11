# Task 1: Crontab Entry For Uptime Logging (Every Monday 1pm)
```
0 13 * * 1 uptime >> /home/rafik/Desktop/EmbeddedLinux/03_Linux/04_Process_Network/Task1_Uptime/LapUptime.log
```
# Task 2: Crontab Entry For Email Report (Every Sunday 9am)
```
0 9 * * 7 /usr/bin/python3 /home/rafik/Desktop/EmbeddedLinux/03_Linux/04_Process_Network/Task2_UptimeReport/UptimeReport.py
```

# Task 3: Crontab Entry For Battery Notification every 30min
```
*/30 * * * * /home/rafik/Desktop/EmbeddedLinux/03_Linux/04_Process_Network/Task3_BatteryReport/check_battery.sh
```