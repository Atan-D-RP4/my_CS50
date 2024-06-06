def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    digit_encountered = False
    s_len = len(s)
    if s_len < 2 or s_len > 6:
        return False
    for i in range(s_len):
        if i < 2:
            if not s[i].isalpha():
                return False
        else:
            if not digit_encountered and s[i] == "0":
                return False
            if s[i].isdigit():
                digit_encountered = True
        if digit_encountered and s[i].isalpha():
            return False
        if s[i] in [
            ".", ",", ":", ";", " ", "-", "_", "!",
            "?", "@", "#", "$", "%", "^", "&", "*",
            "(", ")", "[", "]", "{", "}", "<", ">",
            "`", "~", "+", "="]:
            return False
    return True

if __name__ == "__main__":
    main()
