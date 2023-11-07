
# Multiplication table for numbers from 1 to 10
for i in range(1, 11):
    for j in range(1, 11):
        print(i * j, end="\t")
    print()




#ATM
balance = 0

def check_balance():
    print("Your balance is:", balance)

def withdraw(amount):
    global balance
    if amount <= balance:
        balance -= amount
        print("Withdrawal successful. Your new balance is:", balance)
    else:
        print("Error: Insufficient balance.")

def deposit(amount):
    global balance
    balance += amount
    print("Deposit successful. Your new balance is:", balance)

while True:
    print("Choose an option:")
    print("1. Check balance")
    print("2. Withdraw")
    print("3. Deposit")
    print("4. Quit")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        check_balance()
    elif choice == 2:
        amount = int(input("Enter amount to withdraw: "))
        withdraw(amount)
    elif choice == 3:
        amount = int(input("Enter amount to deposit: "))
        deposit(amount)
    elif choice == 4:
        print("Thank you for using our ATM. Goodbye!")
        break
    else:
        print("Invalid choice. Please try again.")




#C 
age = int(input("Enter your age: "))
grade = int(input("Enter your grade: "))
if age >= 18 and grade >= 12:
    print("Congratulations on being a senior in high school! Enjoy your last year.")
elif age >= 18:
    print("You are an adult now. Make sure to take responsibility for your actions.")
elif grade >= 12:
    print("You are a senior in high school. Make the most of it!")
else:
    print("You have a lot of life ahead of you. Enjoy the journey!")
