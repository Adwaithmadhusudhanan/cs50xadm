a = input("Greeting: ")
a = a.strip().lower()
if a.startswith("hello"):
    print("$0")
elif a.startswith("h"):
    print("$20")
else:
    print("$100")
