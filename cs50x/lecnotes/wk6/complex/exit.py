# Exits with explicit value, importing sys

import sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)


# Some additional info about the sys.exit() function

# The main difference is that sys.exit() terminates the entire program,
# whereas return and break are used for different purposes within functions or loops, respectively.

# You typically use sys.exit() in situations where you want to exit the program completely from any part of the code.
# For example, you might use it if an error occurs, and you want to stop the program execution immediately without proceeding further.
# Additionally, sys.exit() can be used in command-line scripts or programs where you want to explicitly exit the entire program.