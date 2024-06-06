def main():
    while True:
        try:
            fuel = input("Fraction: ").strip()
            fuel = convert(fuel)
            print(f"Fuel: {gauge(fuel)}")
        except ValueError or ZeroDivisionError:
            print("Invalid input. Please try again.")
            continue

def convert(fraction):
    fraction = fraction.split("/")
    if len(fraction) != 2:
        raise ValueError
    elif fraction[1] == "0":
        return ZeroDivisionError
    elif not fraction[0].isnumeric() or not fraction[1].isnumeric():
        raise ValueError
    elif int(fraction[0]) > int(fraction[1]):
        raise ValueError
    else:
        return round(int(fraction[0]) / int(fraction[1]) * 100)

def gauge(percentage):
    if percentage <= 1:
        return "E"
    elif percentage >= 99:
        return "F"
    else:
        return f"{percentage}%"

if __name__ == "__main__":
    main()
