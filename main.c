#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int menu(void);
void plusmoins(int difficulty);

int main(int argc, char const *argv[]) {
  int play_again = 1;
  /*int difficulty = 2;*/
  srand(time(NULL));

  printf("Welcome to plusminus !\n");

  do {
    plusmoins(menu());
    printf(" Press 1 to play again, otherwhise press 0\n");
    scanf("%d", &play_again );
  }while(play_again);
  return 0;
}

void plusmoins(int difficulty){
  const int MIN = 1;
  int max = 100; /* Donne les bornes pour le nombre à deviner */
  int nombreMystere = 0; /* Le nombre à deviner */
  int devine = 0; /* La tentative pour trouver nombreMystere */

  switch (difficulty) {
    case 1 :
      max = 50;
      break;

    case 2 :
      max = 100;
      break;

    case 3 :
      max = 200;
      break;

    case 4 :
      max = 500;
      break;

    case 0 :
      max = 1;
      printf("You have unlocked the hidden difficulty setting\n");
      printf("Be prepared for an exciting game\n");
      break;
  }

  nombreMystere = (rand() % (max - MIN + 1)) + MIN; /* Genere le nombre à deviner */

  printf("%d\n", max);

  do {
    scanf("%d",&devine);

    if (devine < MIN || devine > max)
      {
        printf("Ce nombre est en dehors des bornes, reessayez donc. \n");
      }

    else if (devine < nombreMystere)
      {
        printf("+\n");
      }
    else if (devine > nombreMystere)
      {
        printf("-\n");
      }

  } while(devine != nombreMystere);
  printf("Bien ouej, c'etait bien %d\n", nombreMystere );
}

int menu(void){
  int difficulty = 2;

  printf("How hrdcr do you wnt to go ?\n");
  printf("1. chill \n");
  printf("2. standard \n");
  printf("3. kinda hard i guess\n");
  printf("4. i wouldnt do this\n");

  scanf("%d", &difficulty);
  return difficulty;

}
