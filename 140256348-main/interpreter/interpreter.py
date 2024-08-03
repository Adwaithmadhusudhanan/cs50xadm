exp = input("Expression: ")
x,operator,z = exp.split(" ")
x = float(x)
z = float(z)
if operator == "+":
    print(x + z)
elif operator == "-":
    print(x - z)
elif operator == "*":
    print(x * z)
elif operator == "/":
    print(x / z)
else:
    print("Invalid operator")

