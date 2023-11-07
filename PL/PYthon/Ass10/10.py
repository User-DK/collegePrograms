
while True:
    # Take user input for operation
    operation = input("Enter an operation (+, -, *, /) or 'exit' to quit: ")

    # Check if user wants to exit
    if operation == "exit":
        break

    # Take user input for operands
    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))

    # Perform operation and display result
    if operation == "+":
        result = num1 + num2
        print(f"{num1} + {num2} = {result}")
    elif operation == "-":
        result = num1 - num2
        print(f"{num1} - {num2} = {result}")
    elif operation == "*":
        result = num1 * num2
        print(f"{num1} * {num2} = {result}")
    elif operation == "/":
        if num2 == 0:
            print("Error: Cannot divide by zero")
        else:
            result = num1 / num2
            print(f"{num1} / {num2} = {result}")
    else:
        print("Invalid operation")

