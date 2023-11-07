import math
import math

# a. function to add two numbers
def add_numbers(num1, num2):
    return num1 + num2

# b. function to check if a string is palindrome
def is_palindrome(string):
    return string == string[::-1]

# c. function to calculate area of circle
def calculate_area(radius):
    return math.pi * radius ** 2


# a. function to add two numbers
def add_numbers(num1, num2):
    result = num1 + num2
    print(f"Adding {num1} and {num2}. Result: {result}")
    return result

# b. function to check if a string is palindrome
def is_palindrome(string):
    result = string == string[::-1]
    print(f"Checking if '{string}' is a palindrome. Result: {result}")
    return result

# c. function to calculate area of circle
def calculate_area(radius):
    result = math.pi * radius ** 2
    print(f"Calculating area of circle with radius {radius}. Result: {result}")
    return result

# d. function to convert temperature from Celsius to Fahrenheit and vice versa
def convert_temperature(temp, unit):
    if unit == 'C':
        result = (temp * 9/5) + 32
        print(f"Converting {temp} degrees Celsius to Fahrenheit. Result: {result}")
        return result
    elif unit == 'F':
        result = (temp - 32) * 5/9
        print(f"Converting {temp} degrees Fahrenheit to Celsius. Result: {result}")
        return result
    else:
        result = "Invalid unit. Please enter 'C' or 'F'."
        print(result)
        return result

# example usage
print("Result of adding 5 and 7:", add_numbers(5, 7)) # output: Adding 5 and 7. Result: 12
print("Is 'racecar' a palindrome?", is_palindrome('racecar')) # output: Checking if 'racecar' is a palindrome. Result: True
print("Area of circle with radius 5:", calculate_area(5)) # output: Calculating area of circle with radius 5. Result: 78.53981633974483
print("Converting 32 degrees Celsius to Fahrenheit:", convert_temperature(32, 'C')) # output: Converting 32 degrees Celsius to Fahrenheit. Result: 89.6
print("Converting 89.6 degrees Fahrenheit to Celsius:", convert_temperature(89.6, 'F')) # output: Converting 89.6 degrees Fahrenheit to Celsius. Result: 32.0
print("Converting 89.6 degrees Fahrenheit to Celsius:", convert_temperature(89.6, 'F')) # output: 32.0
print("Converting 100 degrees Kelvin to Celsius or Fahrenheit:", convert_temperature(100, 'K')) # output: Invalid unit. Please enter 'C' or 'F'.
