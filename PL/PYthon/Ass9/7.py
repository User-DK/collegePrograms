'''
Write a program that reads a text file and creates another file that is identical
except that every sequence of consecutive blank spaces is replaced by a
single space. (perform write operation on other file)
'''


# Open the input file in read mode
with open("input.txt", "r") as input_file:
    # Read the contents of the input file
    input_text = input_file.read()

# Replace consecutive spaces with a single space
output_text = " ".join(input_text.split())

# Open the output file in write mode
with open("output.txt", "w") as output_file:
    # Write the modified text to the output file
    output_file.write(output_text)



