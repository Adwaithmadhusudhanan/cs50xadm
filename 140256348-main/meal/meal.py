def main():
    user_time = input("What time is it? ")
    total_hours = convert(user_time)

    if 7.0 <= total_hours < 12.0:
        print("breakfast time")
    elif 12.0 <= total_hours < 17.0:
        print("lunch time")
    elif 17.0 <= total_hours < 22.0:
        print("dinner time")

def convert(time):
    hours, minutes = map(int, time.split(":"))
    total_hours = hours + minutes / 60.0
    return total_hours

if __name__ == "__main__":
    main()

