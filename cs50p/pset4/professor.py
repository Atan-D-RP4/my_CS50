import random

def main():
    level = get_level()
    score = 0
    for i in range(10):
        tries = 1
        nums = generate_integer(level)
        while True:
            if tries > 3:
                print(" + ".join(map(str, nums)) + " = " + str(sum(nums)))
                break
            print(" + ".join(map(str, nums)), end=" = ")
            answer = sum(nums)
            user_answer = input().strip()
            tries += 1
            if answer == int(user_answer):
                score += 1
                break
            else:
                print("EEE")
    print(f"Score: {score}")

def get_level():
    while True:
        level = input("Level: ").strip()
        if level not in ["1", "2", "3"]:
            continue
        return int(level)


def generate_integer(level):
    nums = []
    for _ in range(2):
        if level == 1:
            nums.append(random.randint(0, 9))
        elif level == 2:
            nums.append(random.randint(10, 99))
        else:
            nums.append(random.randint(100, 999))
    return nums

if __name__ == "__main__":

    main()

