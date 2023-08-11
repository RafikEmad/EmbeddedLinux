#!/usr/bin/python3
def count_occurrences(list, number):
    count = 0
    for i in list:
        if i == number:
            count+=1
    return count

#take list of number from user
numbers = input("Enter a list of numbers separated by spaces: ").split()
#convert string to int
numbers = [int(number) for number in numbers]
#target to count No of occurrences
target = int(input("Enter the number you want to count: "))

result = count_occurrences(numbers, target)

print(f"The number {target} appears {result} times in the list.")