# Three ways to print a command-line arguement

from sys import argv

# Prints a command-line argument

def c_analog():
    if len(argv) == 2:
        print(f"hello, {argv[1]}")
    else:
        print("hello, world")

# Printing command-line arguments, indexing into argv

def better_way():
for i in range(len(argv)):
    print(argv[i])

# Printing command-line arguments, the pythonic way
def main():
    for arg in argv:
        print(arg)


main()
