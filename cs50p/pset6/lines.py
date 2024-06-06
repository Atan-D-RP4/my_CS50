from sys import argv, exit

def main():
    if len(argv) != 2:
        print("Too few or too many arguments")
        exit(1)

    filename = argv[1]
    if not filename.endswith(".py"):
        print("File is not a Python file")
        exit(1)
    line_count = 0
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                if line.strip().startswith("#") or line.strip() == "" or line.strip() == "\n":
                    continue
                elif line.strip() == "\r\n" or line.startswith(" #"):
                    continue
                else:
                    line_count += 1
    except FileNotFoundError:
        print(f"File {filename} does not exist")
        # asdasd
        exit(1)
    print(f"{line_count}")

if __name__ == '__main__':
    main()
