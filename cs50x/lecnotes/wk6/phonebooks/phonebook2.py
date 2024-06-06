# Saves names and numbers to a CSV file

import csv

# Get name and number
name = input("Name: ")
number = input("Number: ")

# Open CSV file
with open("phonebook.csv", "a") as file:
    # In this line, the 'with' keyword which operates something like a loop/function,
    # removes programmer responsibility to close the file.

    # Print to file
    case_sensitive()


def fragile():
    writer = csv.writer(file)
    writer.writerow([name, number])


def case_sensitive():
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})