attendee_list = []

def register_attendee(name):
    attendee_list.append(name)
    print(f"Registered: {name}")

def check_in_attendee(name):
    if name in attendee_list:
        print(f"Checked in: {name}")
    else:
        print(f"{name} not found in the attendee list.")

def generate_attendee_list():
    if attendee_list:
        print("Attendee List:")
        for i, attendee in enumerate(attendee_list, start=1):
            print(f"{i}. {attendee}")
    else:
        print("No attendees registered.")

while True:
    print("\nEvent Registration System")
    print("1. Register Attendee")
    print("2. Check in Attendee")
    print("3. Generate Attendee List")
    print("4. Exit")

    choice = input("Enter your choice (1/2/3/4): ")

    if choice == '1':
        name = input("Enter attendee's name: ")
        register_attendee(name)
    
    elif choice == '2':
        name = input("Enter attendee's name to check in: ")
        check_in_attendee(name)
    
    elif choice == '3':
        generate_attendee_list()
    
    elif choice == '4':
        print("Event Registration System is closed.")
        break
    
    else:
        print("Invalid choice. Please select a valid option (1/2/3/4).")
