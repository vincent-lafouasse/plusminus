#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int difficulty_choice(void);
void plusminus(int max);

int main(void) {
  int play_again;

  play_again = 1;
  srand(time(NULL));
  printf(" == Welcome to plusminus ! == \n\n");
  do {
    plusminus(difficulty_choice());
    printf("\nPress 1 to play again, otherwhise press 0\n");
    scanf("%d", &play_again);
    printf("\n");
  } while (play_again);
  printf("Thank you !\n");
  return (0);
}

void plusminus(int max) {
  const int MIN;
  int mystery_number;
  int guess;
  int counter;

  MIN = 1;
  mystery_number = 0;
  guess = 0;
  counter = 0;
  mystery_number = (rand() % (max - MIN + 1)) + MIN;
  /* Generates a random number between max and MIN */
  do {
    scanf("%d", &guess);
    if (guess < MIN || guess > max) {
      printf("This number is not valid, please try again.\n");
    } else if (guess < mystery_number) {
      printf("(+) The mystery number is greater than that\n\n");
      counter++;
    } else if (guess > mystery_number) {
      printf("(-) The mystery number is lower than that\n\n");
      counter++;
    }
  } while (guess != mystery_number);
  counter++;
  printf("\n");
  printf("Well done, it was indeed %d.\n", mystery_number);
  printf("And you only took %d turns !\n\n", counter);
}

int difficulty_choice(void) {
  int difficulty;
  int max[];

  difficulty = 2;
  max[] = {1, 50, 100, 1000, 10000};
  printf("What difficulty setting do you choose ?\n");
  printf("1. chill \n");
  printf("2. standard \n");
  printf("3. annoying\n");
  printf("4. i wouldnt do this\n\n");
  scanf("%d", &difficulty);
  printf("\n");
  if (difficulty == 0) {
    printf("You have unlocked the hidden difficulty setting.\n");
    printf("Be prepared for an exciting game.\n\n");
  }
  printf("To win at plusminus, you will have to guess a number.\n");
  printf("This number has been randomly selected between 1 and %d.\n\n",
         max[difficulty]);
  printf("Good luck !\n\n");
  printf("What's your guess ?\n\n");
  return (max[difficulty]);
}
