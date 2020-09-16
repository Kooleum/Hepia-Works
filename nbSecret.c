#include <stdio.h>      /* printf(), scanf() */
#include <stdlib.h>     /* srand(), rand() */
#include <time.h>       /* time() */
#include <math.h>       /* log() */

int main(){

  //initialize variables
  srand(time(NULL));
  int nbRand = rand();
  int nbMax = 0;
  int nbGuess = 0;
  int nbTry = 0;
  int nbTryMax = 1;
  int nbDiv = 0;

  //Ask user form maximum nimber
  printf("Veuillez entrer le nombre maximum :\n");
  scanf("%d", &nbMax);
  nbRand = nbRand % nbMax + 1;
  nbDiv = nbRand;

//Max try number calculation
  while(nbDiv != 0){
    nbDiv/=2;
    nbTryMax++;
  }

//Show rules
  printf("Votre but est maintenant de devnier le nombre généré aléatoirement entre 0 et %d \n",nbMax );
  printf("\n");

  //game loop
  do {
    nbTry++;
    printf("votre essai : ");
    scanf("%d", &nbGuess);
    if(nbGuess < 0 || nbGuess > nbMax){
      //Repeat rules if number out of bounds
      printf("Attention vous devez deviner un nombre entre 0 et %d\n", nbMax);
    }else{
      if(nbGuess == nbRand){
        //Win message if number is correct
        printf("Bravo! vous avez gagné en %d essais le nombre de coup otpimal théorique était de %d\n", nbTry, nbTryMax);
      }else{
        if(nbGuess > nbRand){
          //Show message if number is inferior
          printf("Le nombre secret est inférieur à %d\n",nbGuess );
        }else{
          //Show message if number is superior
          printf("Le nombre secret est supérieur à %d\n",nbGuess );
        }
      }

    }
  } while(nbGuess != nbRand);
}
