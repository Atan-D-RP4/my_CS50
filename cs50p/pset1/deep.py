s = input("What is the Answer to the Great Question of Life, the Universe, and Everything? ").strip().lower()

s = s.replace("-", " ")

if s == "forty two" or s == "42":
    print("Yes")
else:
    print("No")
