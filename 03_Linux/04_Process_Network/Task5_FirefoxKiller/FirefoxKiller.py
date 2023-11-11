import subprocess

# Specify the process name to be terminated
process_name = "firefox"

# Use the subprocess module to run the pkill command
try:
    subprocess.run(["pkill", "-f", process_name], check=True)
    print("Terminated successfully")
except subprocess.CalledProcessError as e:
    print(f"Error terminating process. Exit code: {e.returncode}")
