# Implements linear search for names using `in`. This is the "Pythonic" way.

import sys

def main():
    # A list of names
    names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

    # Ask for name
    name = input("Name: ")

    # Search for name
    if name in names:
        print("Found")
        sys.exit(0)

    print("Not found")
    sys.exit(1)


def aux():
# Implements linear search for names using loop.
# Will not execute as aux() function is not called.

    # A list of names
    names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

    # Ask for name
    name = input("Name: ")

    # Search for name
    for n in names:
        if name == n:
            print("Found")
            sys.exit(0)

    print("Not found")
    sys.exit(1)


main()