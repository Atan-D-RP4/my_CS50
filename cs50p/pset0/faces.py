
def convert(s: str):
    s = s.split()
    for i in range(len(s)):
        if s[i] == ":)":
            s[i] = "🙂"
        elif s[i] == ":(":
            s[i] = "🙁"
    return " ".join(s)

def main():
    str = input().strip()
    print(convert(str))

if __name__ == "__main__":
    main()
