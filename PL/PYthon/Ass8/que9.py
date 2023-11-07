dictionary = {
    "Humans": "many",
    "Brave": "few",
    "key": 1
}

print(dictionary)

if "Brave" in dictionary:
    print(dictionary.get("Brave"))
else:
    print(-1)

dictionary.update({"Hello": "World"})
print(dictionary)

dictionary.pop("Hello")
print(dictionary)

dict_copy = dictionary.copy()
print(dict_copy)

# Correction: Use len(dict_copy) instead of dict_copy.len()
print(len(dict_copy))

# Deleting both dictionaries
del dictionary
del dict_copy
