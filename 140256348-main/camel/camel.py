a = input("camelCase: ")
snake = ''
for c in a:
    if c.isupper():
        snake += '_' + c.lower()
    else:
        snake += c
print("snake_case: " + snake)

