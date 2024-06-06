
def snake_case(s):
    result = ""
    for c in s:
        if c.isupper():
            result += "_" + c.lower()
        else:
            result += c
    return result

def main():
    s = input("camelCase: ").strip()
    print(snake_case(s))

if __name__ == '__main__':
    main()
