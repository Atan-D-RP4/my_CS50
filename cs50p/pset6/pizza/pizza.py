import csv
import tabulate
from sys import argv, exit

def main():
    if len(argv) != 2:
        print("Too few or too many arguments")
        exit(1)

    file_path = argv[1]
    if not file_path.endswith(".csv"):
        print("File must be a CSV file")
        exit(1)

    table = []
    with open(file_path, "r") as file:
        reader = csv.reader(file)
        for row in reader:
            table.append(row)
    print(tabulate.tabulate(table, headers="firstrow", tablefmt="grid"))



if __name__ == '__main__':
    main()
