import csv
import tabulate
from sys import argv, exit

def main():
    if len(argv) != 3:
        print("Too few or too many arguments")
        exit(1)

    file_path = argv[1]
    if not file_path.endswith(".csv"):
        print("File must be a CSV file")
        exit(1)

    output_path = argv[2]
    if not output_path.endswith(".csv"):
        print("Output file must be a CSV file")
        exit(1)
    if output_path == file_path:
        print("Output file must be different from input file")
        exit(1)
    # create output file if it doesn't exist
    with open(output_path, "w") as out_file:
        pass

    table = []
    table.append(["first", "last", "house"])
    with open(file_path, "r") as in_file:
        reader = csv.reader(in_file)
        for row in reader:
            if row[0] == "name":
                continue
            name, house = row
            name = name.strip().split(" ")
            house = house.strip()
            first_name = name[-1].replace(" ", "")
            last_name = name[0].replace(",", "")
            table.append([first_name, last_name, house])
    with open(output_path, "w") as out_file:
        writer = csv.writer(out_file)
        writer.writerows(table)


if __name__ == '__main__':
    main()
