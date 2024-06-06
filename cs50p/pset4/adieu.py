def main():
    names = []
    while True:
        try:
            name = input().strip()
            if name:
                names.append(name)
        except EOFError:
            print()
            break

    print("Adieu, adieu, to", end=" ")

    for name in names:
        if len(names) == 1:
            print(name)
        elif name == names[-1] and len(names) > 1:
            print("and", name)
        elif name == names[-2] and len(names) == 2:
            print(name, end=" ")
        else:
            print(name, end=", ")

if __name__ == "__main__":
    main()
