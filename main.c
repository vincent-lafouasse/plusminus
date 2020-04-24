#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[]) {
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
  return 0;
}
