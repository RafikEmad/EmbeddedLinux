#!/bin/bash
DISPLAY=:1
export XAUTHORITY=/run/user/1000/gdm/Xauthority
export XDG_RUNTIME_DIR=/run/user/$(id -u)
# Run your Python script
source /home/rafik/Desktop/EmbeddedLinux/03_Linux/04_Process_Network/Task6_WhatsAppMessage/venv/bin/activate

# Ensure the virtual environment is activated before running the script
if [ -z "$VIRTUAL_ENV" ]; then
    echo "Error: Virtual environment is not activated."
    exit 1
fi

xvfb-run -a -n 1 python3 /home/rafik/Desktop/EmbeddedLinux/03_Linux/04_Process_Network/Task6_WhatsAppMessage/WhatsAppMsg.py
