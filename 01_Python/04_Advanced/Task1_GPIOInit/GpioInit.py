concatenated_pins = 0

# Ask the user for the status of each pin
for i in range(1, 9):
    pin_status = input(f"Enter Bit {i} mode 'in' or 'out'? ").strip().lower()
    
    # Validate the user input
    if pin_status not in ('in', 'out'):
        print("Invalid input. Please enter 'in' or 'out'.")
        break
    
    # Interpret "out" as 1 and "in" as 0, then update the concatenated_pins
    if pin_status == 'out':
        concatenated_pins |= (1 << (i - 1))

# Print the concatenated pins as an integer
print(f"Concatenated pins as an integer: {bin(concatenated_pins)}")
binary = bin(concatenated_pins)
Cmainfile = f"void Init_PORTA_DIR(void)\n{{\n   DDRA = {binary};\n}}"

c_file_name = "concatenated_pins.c"

with open(c_file_name, 'w') as c_file:
    c_file.write(Cmainfile)

print(f"Concatenated pins written to {c_file_name}")