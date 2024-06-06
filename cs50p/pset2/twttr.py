def main():
    s = input("Input: ").strip()
    print("Output: ", end="")
    for i in range(len(s)):
        if s[i].lower() not in "aeiou":
            print(s[i], end="")
    print()

if __name__ == '__main__':
    main()
