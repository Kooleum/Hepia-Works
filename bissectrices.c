#include <stdio.h>      /* printf(), scanf() */
#include <stdlib.h>     /* srand(), rand() */
#include <time.h>       /* time() */
#include <math.h>       /* log() */
#include <stdbool.h>       /* log() */

double g(double x);
int bisect(double a1, double b1, double epsilon, double *zero);
int sign(double x);

double a1;
double b1;
double epsilon;
double zero;
int iter = 0;

int main(){
  printf("Entrez la première borne \n");
  scanf("%lf", &a1);
  printf("Entrez la deuxième borne \n");
  scanf("%lf", &b1);
  printf("Entrez epsilon\n");
  scanf("%lf", &epsilon);

  if(a1 >= b1 || sign(g(a1)) == sign(g(b1)) || epsilon <= 0){
    scanf("Les nombres entrés sont incohérents");
    exit(1);
  }

  iter = bisect(a1, b1, epsilon, &zero);

  printf("La valeur du zéro trouvée est de %lf, elle a été trouvée en %d itérations\n", zero, iter);

}

double g(double x){
  return pow(x, 4) + pow(x, 3) + pow(x, 2) - 1;
}

int sign(double x){
  // return x/abs(x);
  return (x<0) ? true:false;
}

int bisect(double a1, double b1, double epsilon, double *zero){
  double c1;
  int i = 0;
  while(b1-a1 > epsilon || i>300){
    i++;
    c1 = (b1+a1)/2;
    if(sign(g(c1)) != sign(g(b1))){
      a1 = c1;
    }else{
      b1 = c1;
    }
  }

  if(i>300){
    return -1;
  }
  *zero = c1;
  return i;
}
