import re
import sys


def main():
    time = convert(input("Hours: "))
    print(time)


def convert(s):
    regex = "([0-9]|1[0-2])(?::([0-5][0-9]))? ([AP]M)"
    if times := re.search(r"^" + regex + " to " + regex + "$", s):
        t = times.groups()
        return f"{time_convert(t[:3])} to {time_convert(t[3:])}"
    else:
        raise ValueError("Invalid time")

def time_convert(time: list[str]):
    if time[0] == "12":
        hours = "00" if time[2] == "AM" else time[0]
        minutes = "00" if time[1] == None else f"{int(time[1]):02}"
    else:
        hours = f"{(int(time[0]) + 12):02}" if time[2] == "PM" else f"{int(time[0]):02}"
        minutes = "00" if time[1] == None else f"{int(time[1]):02}"
    return f"{hours}:{minutes}"


if __name__ == "__main__":
    main()
