import random

def main():
    while True:
        try:
            n = int(input("Level: ").strip())
        except ValueError:
            continue
        if not n or n < 1:
            continue
        break
    num = random.randint(1, n)
    while True:
        try:
            guess = int(input("Guess: ").strip())
        except ValueError:
            continue
        if guess == num:
            print("Just right!")
            break
        elif guess < num:
            print("Too small!")
        else:
            print("Too large!")

if __name__ == "__main__":
    main()
