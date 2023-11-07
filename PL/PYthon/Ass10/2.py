
n = int(input("Enter the value of N: "))
fibonacci_list = []

# Initializing the first two numbers of the Fibonacci sequence
a, b = 0, 1

# Generating the first N Fibonacci numbers using a while loop
while len(fibonacci_list) < n:
    fibonacci_list.append(b)
    a, b = b, a + b

print(fibonacci_list)
