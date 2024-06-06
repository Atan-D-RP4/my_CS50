def main():
    time = input("What Time is it? ").strip()
    time = convert(time)

    if time <= 8 and time >= 7:
        print("breakfast time")
    elif time <= 13 and time >= 12:
        print("lunch time")
    elif time <= 19 and time >= 18:
        print("dinner time")


def convert(time):
    # time = "12:30 AM"
    time = time.split(":")
    hour = int(time[0])
    minute = int(time[1][:2])
    am_pm = time[1][3:]
    time_float = hour + minute/60
    if am_pm == "PM":
        time_float += 12
    return time_float


if __name__ == "__main__":
    main()


