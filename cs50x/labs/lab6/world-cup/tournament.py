# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    try:
        with open(sys.argv[1], "r") as teams_csv:
            teams = list(csv.DictReader(teams_csv))
    except FileNotFoundError:
        print(f"{sys.argv[1]} Not Found")
        return 2

    counts = {"name": "wins"}

    for team in teams:
        team["rating"] = int(team["rating"])
        counts[team["team"]] = 0

    # TODO: Simulate N tournaments and keep track of win count
    for sims in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1
            print(f"Team {winner[0]['team']} Not Found In Dictionary File")

    # Print each team's chances of winning, according to simulation
    for team in counts:
        if str(counts[team]).isdigit():
            counts[team] = int(counts[team])

    for team, win_count in sorted(
        counts.items(),
        key=lambda x: int(x[1]) if str(x[1]).isdigit() else 0,
        reverse=True,
    ):
        if str(win_count).isdigit():
            print(f"{team}: {int(win_count) * 100 / N:.1f}% chance of winning")
        else:
            continue
    return 0


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winners = simulate_round(teams)
    for team in winners:
        if len(winners) > 1:
            winners = simulate_round(winners)
    return winners[0]["team"]


if __name__ == "__main__":
    main()
