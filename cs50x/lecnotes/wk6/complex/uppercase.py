# Uppercases string all at once

def main():
    before = input("Before: ")
    after = before.upper()
    print(f"After:  {after}")

# Uppercases string one character at a time
# Will not be executed since aux function is not called

def aux():
    before = input("Before: ")
    print("After:  ", end="")
    for c in before:
        print(c.upper(), end="")
    print()


main()