import validators

def main():
    mail = input("What's your email address? ").strip()
    if is_valid(mail):
        print("Valid")
    else:
        print("Invalid")

def is_valid(s: str):
    return validators.email(s)


if __name__ == "__main__":
    main()
