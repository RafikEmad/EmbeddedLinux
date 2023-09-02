import tkinter as tk
import tkinter.font as font

def turn_on_led():
    led_canvas.itemconfig(led, fill='red')
    status_label.config(text="LED Status: On")

def turn_off_led():
    led_canvas.itemconfig(led, fill='gray')
    status_label.config(text="LED Status: Off")

# Create the main application window
app = tk.Tk()
app.title("LED Control")

# Set the window size to 500x500
app.geometry("500x500")

# Create a canvas to display the LED
led_canvas = tk.Canvas(app, width=200, height=200)
led = led_canvas.create_oval(50, 50, 150, 150, fill='gray')  # Initially gray
led_canvas.pack()

# Create "LED On" button
on_button = tk.Button(app, text="LED On", command=turn_on_led)
on_button.pack()

# Create "LED Off" button
off_button = tk.Button(app, text="LED Off", command=turn_off_led)
off_button.pack()

# Create a label to display LED status
status_label = tk.Label(app, text="LED Status: Off", font=font.Font(size=18))
status_label.pack()

app.mainloop()
