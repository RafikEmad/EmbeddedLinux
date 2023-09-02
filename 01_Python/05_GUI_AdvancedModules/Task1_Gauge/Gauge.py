import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

def create_temperature_gauge(temperature):
    # Create a figure and axis
    fig, ax = plt.subplots(figsize=(6, 6))

    # Define the gauge circle
    circle = plt.Circle((0, 0), 0.7, color='lightgray', alpha=0.7)
    ax.add_artist(circle)

    # Define the colors for the gauge's sectors in reverse order
    colors = ['red', 'yellow', 'green']
    angles = [0, 60, 120, 180]  # Angles for the color transitions

    # Reverse temperature value to match color order
    reversed_temperature = 100 - temperature

    # Determine the color based on the reversed temperature
    for i in range(3):
        start_temp = (i - 1) * 40
        end_temp = i * 40
        if start_temp <= reversed_temperature <= end_temp:
            color = colors[i]
            break
    else:
        color = colors[-1]  # Default to the last color if temperature exceeds the thresholds

    # Draw colored sectors on the gauge
    for i in range(3):
        arc = patches.Arc((0, 0), 1.4, 1.4, theta1=angles[i], theta2=angles[i+1], color=colors[i], lw=15)
        ax.add_artist(arc)

    # Draw the arrow with its center at the center of the arc
    arrow_length = 0.6
    arrow_angle = -30 + (210 - (-30)) * (reversed_temperature / 100.0)
    arrow_x = arrow_length * np.cos(np.radians(arrow_angle))
    arrow_y = arrow_length * np.sin(np.radians(arrow_angle))
    ax.arrow(0, 0, arrow_x, arrow_y, head_width=0.05, head_length=0.1, fc='blue', ec='blue')

    # Set the axis limits and labels
    ax.set_xlim(-1, 1)
    ax.set_ylim(-1, 1)
    ax.set_aspect('equal', 'box')
    ax.set_xticks([])
    ax.set_yticks([])
    ax.text(0, -1.2, f'Temperature: {temperature}°C', fontsize=12, ha='center')

    plt.show()

# Example usage:
temperature = 75  # Temperature value to be displayed on the gauge

create_temperature_gauge(temperature)
