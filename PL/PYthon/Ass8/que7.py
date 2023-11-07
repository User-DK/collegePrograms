student_data = []

def add_student(name, score):
    student_data.append((name, score))
    print(f"Added: {name} - Test Score: {score}")

def calculate_average_score():
    if not student_data:
        print("No student data available.")
    else:
        total_score = sum(score for _, score in student_data)
        average_score = total_score / len(student_data)
        print(f"Average Test Score: {average_score:.2f}")

while True:
    print("\nStudent Grade Management System")
    print("1. Add Student")
    print("2. Calculate Average Score")
    print("3. Exit")

    choice = input("Enter your choice (1/2/3): ")

    if choice == '1':
        name = input("Enter student's name: ")
        score = float(input("Enter test score: "))
        add_student(name, score)
    
    elif choice == '2':
        calculate_average_score()
    
    elif choice == '3':
        print("Student Grade Management System is closed.")
        break
    
    else:
        print("Invalid choice. Please select a valid option (1/2/3).")
