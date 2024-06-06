def main():
    amount = 0
    while amount < 50:
        if amount < 50:
            print(f"Amount Due: {50 - amount}")
        else:
            break
        coin = int(input("Insert coin: "))
        if coin not in [5, 10, 25]:
            continue
        amount += coin
    print(f"Change Owed: {amount - 50}")


if __name__ == '__main__':
    main()
