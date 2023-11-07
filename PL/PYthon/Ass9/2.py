start = int(input("Enter the starting number of the range: ")) 
end = int(input("Enter the ending number of the range: "))

print("Prime numbers between", start, "and", end, "are:")

while start <= end: 
    if start > 1: 
        for i in range(2, start): 
            if (start % i) == 0: break
            else: print(start) 
    start += 1
    


#b
num = int(input("Enter a number: ")) 
factorial = 1

for i in range(1, num + 1):
    factorial *= i

print("Factorial of", num, "is", factorial)

#c
terms = int(input("Enter the number of terms: "));
n1, n2 = 0, 1;
count = 0;

if terms <= 0: 
    print("Please enter a positive integer") 
elif terms == 1: 
    print("Fibonacci sequence upto", terms, "term:") 
    print(n1) 
else: 
    print("Fibonacci sequence:") 
    while count < terms: 
        print(n1) 
        nth = n1 + n2 
        n1 = n2 
        n2 = nth 
        count += 1
        
#d
sum = 0

for i in range(2, 101, 2): sum += i

print("Sum of all even numbers from 1 to 100 is", sum)
