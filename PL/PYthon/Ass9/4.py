import random
import math

# a. function to calculate average, sum, and maximum value of a list of numbers
def calculate_stats(numbers):
    average = sum(numbers) / len(numbers)
    total_sum = sum(numbers)
    max_value = max(numbers)
    return average, total_sum, max_value

# b. function to generate a random number and ask the user to guess it
def guess_number():
    random_number = random.randint(1, 100)
    while True:
        guess = int(input("Guess the number (between 1 and 100): "))
        if guess == random_number:
            print("Congratulations! You guessed the number.")
            break
        elif guess < random_number:
            print("Too low. Try again.")
        else:
            print("Too high. Try again.")

# c. function to calculate the factorial of a number using recursion
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

# d. function to print all prime numbers up to a given number
def print_primes(n):
    primes = []
    for i in range(2, n+1):
        is_prime = True
        for j in range(2, int(math.sqrt(i))+1):
            if i % j == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(i)
    print("Prime numbers up to", n, "are:", primes)



# test the functions
numbers = [1, 2, 3, 4, 5]
print(f"Numbers Are {numbers}")
average, total_sum, max_value = calculate_stats(numbers)
print("The average of the numbers is:", average)
print("The sum of the numbers is:", total_sum)
print("The maximum value of the numbers is:", max_value)

guess_number()

n = 5
print("The factorial of", n, "is", factorial(n))

n = 20
print("The prime numbers up to", n, "are:")
print_primes(n)
