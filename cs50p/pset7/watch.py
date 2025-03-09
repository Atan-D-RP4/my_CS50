import re
import sys


def main():
    print("Out: ", parse(input("HTML: ")))


def parse(s):
    s = s.strip()
    if not s.startswith("<iframe"):
        return None
    if not s.find("youtube.com") != -1:
        return None
    src = re.search(r'src="([^"]+)"', s).group(1)
    src = src.replace("embed/", "")
    src = src.replace("youtube.com", "youtu.be")
    if src.find("www.") != -1:
        src = src.replace("www.", "")
    if src.startswith("http://"):
        src = src.replace("http://", "https://")
    return src

if __name__ == "__main__":
    main()
