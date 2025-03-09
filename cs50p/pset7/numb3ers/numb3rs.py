import re
import sys


def main():
    print(validate(input("IPv4 Address: ")))


def validate(ip):
    ip = ip.strip().split(".")
    if len(ip) != 4:
        return False
    for i in ip:
        if not re.match(r"^\d+$", i):
            return False
        if not 0 <= int(i) <= 255:
            return False
    return True


if __name__ == "__main__":
    main()
