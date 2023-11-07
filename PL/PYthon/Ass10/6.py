
filename = input("Enter the file name: ")

with open(filename, 'r') as file:
    word_count = 0
    for line in file:
        word_count += len(line.split())
        
print("The number of words in the file is:", word_count)
