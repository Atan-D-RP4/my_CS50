def main():
    s = input("Greeting: ").strip()
    print(f"${value(s)}")

def value(greeting):
    s = greeting.lower().split()
    if s[0].replace(",", "") == "hello":
        return 0
    elif [*s[0]][0] == "h":
        return 20
    else:
        return 100

if  __name__ == "__main__":
    main()
