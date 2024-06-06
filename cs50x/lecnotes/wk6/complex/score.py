# Averages three numbers using a list and a loop

from cs50 import get_int

def main()
    # Get scores
    scores = []
    for i in range(3):
        score = get_int("Score: ")
        scores.append(score)

    # Print average
    average = sum(scores) / len(scores)
    print(f"Average: {average}")


# Averages three numbers using a list
# Will not execute as aux function is not called
def aux():
    # Scores
    scores = [72, 73, 33]

    # Print average
    average = sum(scores) / len(scores)
    print(f"Average: {average}")


main()