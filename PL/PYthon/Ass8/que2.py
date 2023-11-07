def swapWithTemp(x,y):
    print(f"Before Swaping:\nx={x}\ny={y}")
    z=x
    x=y
    y=z
    print(f"After Swaping:\nx={x}\ny={y}")
    
    
def swapWithOutTemp(x,y):
    print(f"Before Swaping:\nx={x}\ny={y}")
    x+=y
    y=x-y
    x=x-y
    print(f"After Swaping:\nx={x}\ny={y}")


swapWithTemp(1,2)
swapWithOutTemp(1,2)
