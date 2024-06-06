s = input("Greeting: ").strip().lower().split()

print(s)

if s[0].replace(",", "") == "hello":
    print("$0")
elif [*s[0]][0] == "h":
    print("$20")
else:
    print("$100")
