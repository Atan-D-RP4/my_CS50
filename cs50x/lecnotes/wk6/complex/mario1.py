# Prints a column of bricks, catching exceptions


def main():
    height = get_height()
    mario(height)


def mario(height):
    for i in range(height):
        print("#" * 4)


def get_height():
    while True:
        try:
            n = int(input("Height: "))
        except ValueError:
            print("Not an integer")
        else:
            if n > 0:
                return n


main()