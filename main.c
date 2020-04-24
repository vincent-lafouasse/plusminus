#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void plusmoins(void);

int main(int argc, char const *argv[]) {
  int play_again = 1;
  do {
    plusmoins();
    printf(" Press 1 to play again, otherwhise press 0\n");
    scanf("%d", &play_again );
  }while(play_again);
  return 0;
}

void plusmoins(void){
  const int MIN = 1, MAX = 100; // Donne les bornes pour le nombre à deviner
  int nombreMystere = 0; // Le nombre à deviner
  int devine = 0; // La tentative pour trouver nombreMystere
  srand(time(NULL));
  nombreMystere = (rand() % (MAX - MIN + 1)) + MIN; // Génére le nombre à deviner

  do {
    scanf("%d",&devine);

    if (devine < MIN || devine > MAX)
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
