import emoji

def main():
    s = input("Input: ").strip()
    print(emoji.emojize(s, language='alias'))


if __name__ == '__main__':
    main()
