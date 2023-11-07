'''
To-Do List Application: Create a to-do list application where users can add,
remove, and update tasks using a list.
'''


tasks = []

def add(task):
    tasks.append(task)
    print(f"Task '{task}' added to the to-do list.")

def remove(task):
    if task in tasks:
        tasks.remove(task)
        print(f"Task '{task}' removed from the to-do list.")
    else:
        print(f"Task '{task}' not found in the to-do list.")

def update(old_task, new_task):
    if old_task in tasks:
        index = tasks.index(old_task)
        tasks[index] = new_task
        print(f"Task '{old_task}' updated to '{new_task}'.")
    else:
        print(f"Task '{old_task}' not found in the to-do list.")

def display():
    if tasks:
        print("To-Do List:")
        for i, task in enumerate(tasks, start=1):
            print(f"{i}. {task}")
    else:
        print("To-Do List is empty.")

while True:
    print("\nTo-Do List Application")
    print("1. Add Task")
    print("2. Remove Task")
    print("3. Update Task")
    print("4. Display Tasks")
    print("5. Exit")
    
    choice = input("Enter your choice (1/2/3/4/5): ")
    
    if choice == '1':
        task = input("Enter the task to add: ")
        add(task)
    
    elif choice == '2':
        task = input("Enter the task to remove: ")
        remove(task)
    
    elif choice == '3':
        old_task = input("Enter the task to update: ")
        new_task = input("Enter the new task: ")
        update(old_task, new_task)
    
    elif choice == '4':
        display()
    
    elif choice == '5':
        print("To-Do List Application is closed.")
        break
    
    else:
        print("Invalid choice. Please select a valid option (1/2/3/4/5).")
