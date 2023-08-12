import calendar

# Input year and month
year = int(input("Enter the year: "))
month = int(input("Enter the month: "))

# Create a TextCalendar object
cal = calendar.TextCalendar(calendar.SUNDAY)  # You can change the starting day if needed

# Print the calendar for the specified month and year
print(cal.formatmonth(year, month))