import tkinter as tk
import csv
import time

class CSVViewer:
    def __init__(self, master, csv_filename):
        self.master = master
        self.master.title("CSV Viewer")

        self.temp_label = tk.Label(master, text="Temperature")
        self.temp_label.pack()

        self.temp_value = tk.StringVar()
        self.temp_box = tk.Entry(master, textvariable=self.temp_value, state="readonly")
        self.temp_box.pack()

        self.humidity_label = tk.Label(master, text="Humidity")
        self.humidity_label.pack()

        self.humidity_value = tk.StringVar()
        self.humidity_box = tk.Entry(master, textvariable=self.humidity_value, state="readonly")
        self.humidity_box.pack()

        self.csv_filename = csv_filename
        self.update_data()

    def calculate_averages(self):
        try:
            with open(self.csv_filename, "r") as file:
                csv_reader = csv.DictReader(file)
                num_rows = 0
                total_temp = 0
                total_humidity = 0

                for row in csv_reader:
                    try:
                        total_temp += float(row.get("Temperature(°C)", 0))
                        total_humidity += float(row.get("Humidity(%)", 0))
                        num_rows += 1
                    except ValueError:
                        pass

                if num_rows > 0:
                    average_temp = total_temp / num_rows
                    average_humidity = total_humidity / num_rows
                    return average_temp, average_humidity
                else:
                    return None, None

        except FileNotFoundError:
            return None, None

    def update_data(self):
        average_temp, average_humidity = self.calculate_averages()

        if average_temp is not None:
            self.temp_value.set(f"{average_temp:.2f} °C")
        else:
            self.temp_value.set("N/A")

        if average_humidity is not None:
            self.humidity_value.set(f"{average_humidity:.2f}%")
        else:
            self.humidity_value.set("N/A")

        # Schedule the next update after 10 seconds
        self.master.after(10000, self.update_data)

if __name__ == "__main__":
    root = tk.Tk()
    csv_filename = "sensor_data.csv"
    app = CSVViewer(root, csv_filename)
    root.mainloop()
