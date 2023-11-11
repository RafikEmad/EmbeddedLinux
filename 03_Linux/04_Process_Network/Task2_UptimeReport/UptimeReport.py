import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import subprocess

def get_uptime():
    # Run the 'uptime' command and capture the output
    uptime_output = subprocess.check_output(['uptime']).decode('utf-8')
    return uptime_output

def send_email(subject, body, to_address):
    # Your email and password (make sure to use an "App Password" if using Gmail)
    email = 'your_email@gmail.com'  # replace with your email
    password = 'your_app_password'  # replace with your app password

    # Create the MIME object
    message = MIMEMultipart()
    message['From'] = email
    message['To'] = to_address
    message['Subject'] = subject

    # Attach the body of the email
    message.attach(MIMEText(body, 'plain'))

    # Connect to the SMTP server
    with smtplib.SMTP('smtp.gmail.com', 587) as server:
        # Start TLS for security
        server.starttls()

        # Login to the email account
        server.login(email, password)

        # Send the email
        server.sendmail(email, to_address, message.as_string())

# Replace these values with your own
recipient_email = 'recipient@example.com'
email_subject = 'Uptime Report'

# Get the system uptime
uptime_info = get_uptime()

# Create the email body
email_body = f"Uptime Report:\n\n{uptime_info}"

# Send the email
send_email(email_subject, email_body, recipient_email)
