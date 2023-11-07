
def is_leap_year(year):
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False
    
year = int(input("Enter the Year: "))
output = is_leap_year(year)
if output == True:
    print(f"The year {year} is a Leap Year")
else:
    print(f"The year {year} is not a Leap Year")
