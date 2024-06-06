def main():
    items = {}
    while True:
        try:
            item = input().strip().upper()
            items[item] = items.get(item, 0) + 1
        except EOFError:
            print()
            break
    items = sorted(items.items())
    for item, count in items:
        print(f"{count} {item}")


if __name__ == "__main__":
    main()
