import tkinter as tk
import math

def calculate_factorial():
    try:
        n = int(entry.get())
        if n < 0:
            result_label.config(text="Factorial is undefined for negative numbers.")
        else:
            factorial = math.factorial(n)
            result_label.config(text=f"{n}! = {factorial}")
    except ValueError:
        result_label.config(text="Please enter a valid integer.")

# Create the main application window
app = tk.Tk()
app.title("Factorial Calculator")

# Create a label and entry for user input
input_label = tk.Label(app, text="Enter an integer N:")
input_label.pack()

entry = tk.Entry(app)
entry.pack()

# Create a button to calculate the factorial
calculate_button = tk.Button(app, text="Calculate Factorial", command=calculate_factorial)
calculate_button.pack()

# Create a label to display the result
result_label = tk.Label(app, text="")
result_label.pack()

app.mainloop()
