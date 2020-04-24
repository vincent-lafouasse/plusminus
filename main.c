#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int difficulty_choice(void);
void plusminus(int difficulty);

int main(void) {
	int play_again = 1;
	srand(time(NULL));

	printf(" == Welcome to plusminus ! == \n");

	do {
		plusminus(difficulty_choice());
		printf(" Press 1 to play again, otherwhise press 0\n");
		scanf("%d", &play_again );
	}while(play_again);
	printf("Thank you !");
	return 0;
}

void plusminus(int difficulty){
	const int MIN = 1;
	int max = 100;
	int mystery_number = 0;
	int guess = 0;
	int counter = 0;

	switch (difficulty) {
	case 1:
		max = 50;
		break;

	case 2:
		max = 100;
		break;

	case 3:
		max = 1000;
		break;

	case 4:
		max = 10000;
		break;

	case 0:
		max = 1;
		printf("You have unlocked the hidden difficulty setting\n");
		printf("Be prepared for an exciting game\n");
		break;
	}

	mystery_number = (rand() % (max - MIN + 1)) + MIN; /* Generates a random mystery_number */

	printf("%d\n", max);

	do {
		scanf("%d",&guess);

		if (guess < MIN || guess > max)
		{
			printf("This number is not valid, please try again.\n");
		}

		else if (guess < mystery_number)
		{
			printf("+\n");
			counter++;
		}
		else if (guess > mystery_number)
		{
			printf("-\n");
			counter++;
		}

	} while(guess != mystery_number);
	printf("Well done, it was indeed %d\n", mystery_number);
	printf("And you only took %d turns !\n", counter);
}

int difficulty_choice(void){
	int difficulty = 2;

	printf("How hrdcr do you wnt to go ?\n");
	printf("1. chill \n");
	printf("2. standard \n");
	printf("3. kinda hard i guess\n");
	printf("4. i wouldnt do this\n");

	scanf("%d", &difficulty);
	return difficulty;

}
