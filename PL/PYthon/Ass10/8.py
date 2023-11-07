
def find_min_max(numbers):
    min_num = numbers[0]
    max_num = numbers[0]
    for num in numbers:
        if num < min_num:
            min_num = num
        elif num > max_num:
            max_num = num
    return min_num, max_num

numbers = [5, 2, 8, 1, 9, 3]
print("The numbers are ", numbers)
min_num, max_num = find_min_max(numbers)
print("Smallest number:", min_num)
print("Largest number:", max_num)
