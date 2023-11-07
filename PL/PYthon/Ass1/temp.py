x=input("Celsius to Farenheit = y , farenheit to celsius = n")

if(x == 'y'):
    a=float(input("Enter Temp in Celsius: "))
    b=a*9/5+32
    print(f"{a} celsius in Fahrenheit is: {b}")
else:
    a=float(input("Enter Temp in Fahrenheit: "))
    b=(a-32)*5/9
    print(f"{a} celsius in Fahrenheit is: {b}")

