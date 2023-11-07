'''
Inventory Management: In a retail store, use a list to keep track of product stock
levels, and implement functions to add, remove, and update items in the
inventory.
'''

items = {
    "Rice": 5,
    "Wheat": 10,
    "Biscuit": 12,
}

def add_item(item, quantity):
    items[item] = quantity

def remove_item(item):
    if item in items:
        del items[item]
    else:
        print(f"{item} not found in the inventory.")

def update_item(item, new_quantity):
    if item in items:
        items[item] = new_quantity
    else:
        print(f"{item} not found in the inventory.")

def main():
    while True:
        print(f"Choose an option:\n1: Add item\n2: Remove item\n3: Update item\n4: Exit\nCurrently the items are {items}")
        
        choice = input("Enter your choice: ")

        if choice == '1':
            item = input("Enter item to add: ")
            quantity = int(input("Enter item quantity to add: "))
            add_item(item, quantity)
            print(f"{item} added to inventory.")

        elif choice == '2':
            item = input("Enter item to remove: ")
            remove_item(item)
            print(f"{item} removed from inventory.")

        elif choice == '3':
            item = input("Enter item to update: ")
            new_quantity = int(input("Enter new item quantity: "))
            update_item(item, new_quantity)
            print(f"{item} quantity updated in the inventory.")

        elif choice == '4':
            break

        else:
            print("Not a valid option. Please choose 1, 2, 3, or 4.")

    print("Inventory Management System is closed.")

if __name__ == "__main__":
    main()

            
    