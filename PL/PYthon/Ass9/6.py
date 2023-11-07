'''
Write a Python program to create GUI based student registration system
using tkinter.
a. Create 4 labels and corresponding textboxes for accepting Name,
address, Mobile number and email id.
b. Create radio button for accepting gender of student.
c. Use list box for accepting student’s state (add 5 state names)
d. Add checkbutton to select hostel requirement.
e. Display all the details on console and in Messagebox.
'''

from tkinter import *
from tkinter import messagebox

def show_details():
    name = a1.get()
    address = a2.get()
    mobile = a3.get()
    email = a4.get()
    gender = gender_var.get()
    state = states.curselection()
    hostel_req = hostel_var.get()
    
    state_names = ["California", "Texas", "New York", "Florida", "Illinois"]
    selected_states = [state_names[i] for i in state]
    
    details = f"Name: {name}\nAddress: {address}\nMobile Number: {mobile}\nEmail: {email}\nGender: {gender}\nState: {selected_states}\nHostel Required: {hostel_req}"
    
    print(details)
    messagebox.showinfo("Details", details)

master=Tk()
Label(master,text="Name").grid(row=0)
Label(master, text="Address").grid(row=2)
Label(master, text="Mobile Number").grid(row=4)
Label(master, text="Email id").grid(row=6)

a1=Entry(master)
a1.grid(row=0,column=2)

a2=Entry(master)
a2.grid(row=2,column=2)

a3=Entry(master)
a3.grid(row=4,column=2)

a4=Entry(master)
a4.grid(row=6,column=2)

gender_var = IntVar()
gender1 = Radiobutton(master, text='male', value=1, variable=gender_var)
gender1.grid(row=8, sticky=W)

gender2 = Radiobutton(master, text='female', value=2, variable=gender_var)
gender2.grid(row=10, sticky=W)

gender3 = Radiobutton(master, text='other', value=3, variable=gender_var)  
gender3.grid(row=12, sticky=W)

states = Listbox(master, selectmode=MULTIPLE)
states.grid(row=14)
states.insert(1, "California")
states.insert(2, "Texas")
states.insert(3, "New York")
states.insert(4, "Florida")
states.insert(5, "Illinois")

hostel_var = BooleanVar()
hostel = Checkbutton(master, text="Hostel", variable=hostel_var)
hostel.grid(row=16, sticky=W)

Button(master, text='Show Details', command=show_details).grid(row=18, column=2, sticky=W, pady=4)

mainloop()
