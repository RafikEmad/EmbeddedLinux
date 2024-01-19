#!/bin/bash

# Set the paths
cpp_program="./readings"
python_script="averagegui.py"
csv_file="sensor_data.csv"

# Function to run C++ program
run_cpp_program() {
    echo "Running C++ program..."
    ./${cpp_program}
}

# Function to run Python script
run_python_script() {
    echo "Running Python script..."
    python3 ${python_script}
}

# Function to copy CSV file to PC using scp
copy_csv_to_pc() {
    echo "Copying CSV file to PC..."
    scp ${csv_file} rafik@192.168.1.109:/home/rafik/Desktop/EmbeddedLinux/05_RaspberryPi/receivedcsv
}

# Main script
run_cpp_program
run_python_script

# Infinite loop to copy CSV file to PC every 1 minute
while true; do
    copy_csv_to_pc
    sleep 60
done
