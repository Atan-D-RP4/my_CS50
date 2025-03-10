#include <cs50.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct {
  int winner;
  int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]); // Working
void record_preferences(int ranks[]);          //
void add_pairs(void);                          //
void sort_pairs(void);                         //
void lock_pairs(void);                         //
void print_winner(void);                       //
int compare(const void *lmnt1, const void *lmnt2);

int main(int argc, string argv[]) {
  // Check for invalid usage
  if (argc < 2) {
    printf("Usage: tideman [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX) {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++) {
    candidates[i] = argv[i + 1];
  }

  // Clear graph of locked in pairs
  for (int i = 0; i < candidate_count; i++) {
    for (int j = 0; j < candidate_count; j++) {
      locked[i][j] = false;
    }
  }

  pair_count = 0;
  int voter_count = get_int("Number of voters: ");

  // Query for votes
  for (int i = 0; i < voter_count; i++) {
    // ranks[i] is voter's ith preference
    int ranks[candidate_count];

    // Query for each rank
    for (int j = 0; j < candidate_count; j++) {
      string name = get_string("Rank %i: ", j + 1);

      if (!vote(j, name, ranks)) {
        printf("Invalid vote.\n");
        return 3;
      }
    }

    record_preferences(ranks);

    printf("\n");
  }

  add_pairs();
  sort_pairs();
  lock_pairs();
  print_winner();
  return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[]) {
  // TODO
  for (int i = 0; i < candidate_count; i++) {
    if (!strcmp(candidates[i], name)) {
      ranks[rank] = i;
      return true;
    }
  }
  return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[]) {
  // TODO
  for (int i = 0; i < candidate_count; i++) {
    for (int j = i + 1; j < candidate_count; j++) {
      ++preferences[ranks[i]][ranks[j]];
    }
  }
  return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void) {
  // TODO
  for (int i = 0; i < candidate_count; i++) {
    for (int j = 0; j < candidate_count; j++) {
      printf("%i ", preferences[i][j]);
      if (preferences[i][j] > preferences[j][i]) {
        pairs[pair_count].winner = i;
        pairs[pair_count++].loser = j;
      }
    }
    printf("\n");
  }
  return;
}

int compare(const void *lmnt1, const void *lmnt2) {
  pair f = *((pair *)lmnt1);
  pair s = *((pair *)lmnt2);
  int margin1 = preferences[f.winner][f.loser] - preferences[f.loser][f.winner];
  int margin2 = preferences[s.winner][s.loser] - preferences[s.loser][s.winner];
  return (margin2 - margin1);
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void) {
  // TODO

  printf("Unsorted Pairs: \n");
  for (int i = 0; i < pair_count; ++i) {
    printf("%s	->	%s\n", candidates[pairs[i].winner],
           candidates[pairs[i].loser]);
  }

  qsort(pairs, pair_count, sizeof(pair), compare);

  printf("Sorted Pairs: \n");
  for (int i = 0; i < pair_count; ++i) {
    printf("%s	->	%s\n", candidates[pairs[i].winner],
           candidates[pairs[i].loser]);
  }
  return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void) {
  // TODO
  for (int i = 0; i < pair_count; ++i) {
    int winner = pairs[i].winner;
    int loser = pairs[i].loser;
    locked[winner][loser] = true;
    if (locked[loser][winner]) {
      locked[winner][loser] = false;
    }

    bool is_cycle = false;
    for (int col = 0; col < pair_count; ++col) {
      if (locked[loser][col]) {
        for (int row = 0; row < pair_count; ++row) {
          if (locked[row][winner]) {
            is_cycle = true;
          }
        }
      }
    }

    if (is_cycle)
      locked[winner][loser] = false;
  }

  printf("Locked Pairs: \n");

  for (int i = 0; i < candidate_count; ++i) {
    for (int j = 0; j < candidate_count; ++j) {
      if (locked[i][j]) {
        printf("%s	->	%s\n", candidates[i], candidates[j]);
      }
    }
  }

  printf("Locked Pairs: \n");
  for (int i = 0; i < candidate_count; ++i) {
    for (int j = 0; j < candidate_count; ++j) {
      printf("%d ", locked[i][j]);
    }
    printf("\n");
  }

  return;
}

// Print the winner of the election
void print_winner(void) {
  // TODO
  // Check if there is a winner
  for (int col = 0; col < candidate_count; ++col) {
    int count = 0;
    bool is_winner = true;
    for (int row = 0; row < candidate_count; ++row) {
      if (locked[row][col]) {
        is_winner = false;
      } else {
        ++count;
      }
    }
    if (is_winner) {
      printf("Winner: %s\n", candidates[col]);
    }
  }

  return;
}
