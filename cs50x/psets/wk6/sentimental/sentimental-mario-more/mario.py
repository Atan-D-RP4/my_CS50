# TODO

# Prints a Pattern
def main():
    height = get_height()
    for row in range(1, height + 1):
        print(" " * (height - row) + "#" * row + "  " + "#" * row)


# Gets Height from User Input
def get_height():
    while True:
        try:
            n = int(input("Height:"))
            if n > 0 and n <= 8:
                return n
        except ValueError:
            print("Not an Integer")


main()
