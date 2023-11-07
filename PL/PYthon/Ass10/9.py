
string = input("Enter a string: ")
vowels = 0
consonants = 0

for char in string:
    if char.isalpha():
        if char.lower() in ['a', 'e', 'i', 'o', 'u']:
            vowels += 1
        else:
            consonants += 1

print("Number of vowels:", vowels)
print("Number of consonants:", consonants)
