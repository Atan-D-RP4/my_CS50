def main():
    s = input("Input: ").strip()
    print("Output: " + shorten(s))

def shorten(s):
    res = ""
    for i in range(len(s)):
        if s[i] not in "aeiou" and s[i] not in "AEIOU":
            res += s[i]
    return res

if __name__ == '__main__':
    main()
