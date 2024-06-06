def main():
    while True:
        try:
            fuel = input("Fraction: ").strip().split("/")
            fuel = round(int(fuel[0]) / int(fuel[1]) * 100)
            if fuel > 100:
                continue
            if fuel <= 1:
                print("E")
            elif fuel >= 99:
                print("F")
            else:
                print(f"{fuel}%")
            break
        except ZeroDivisionError:
            continue
        except ValueError:
            continue

if __name__ == "__main__":
    main()
