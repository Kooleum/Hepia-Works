#include <stdio.h>      /* printf(), scanf() */
#include <stdlib.h>     /* srand(), rand() */
#include <time.h>       /* time() */
#include <math.h>       /* log() */
#include <stdbool.h>       /* log() */
#include <unistd.h>

double g(double x);
int bisect(double a1, double b1, double epsilon, double *zero/*, int *values[]*/);
int sign(double x);
bool arrayContain(int a, int *b[]);

double a1;
double b1;
double epsilon;
double zero;
int iter = 0;

bool coh=false;

int values[200];


int main(){
  srand(time(NULL));

    printf("Entrez epsilon\n");
    scanf("%lf", &epsilon);

    for(int i = 0; i<200; i++){
      while(!coh){

        if(a1 >= b1 || sign(g(a1)) == sign(g(b1))){
          coh=false;
          a1 = (rand()%20000)*-1;
          b1 = rand()%20000;
        }else{
          coh = true;
        }
      }
      // printf("rand 1 %lf, rand 2 %lf\n", a1, b1);


      iter = bisect(a1, b1, epsilon, &zero/*, &values[*]*/);

      printf("La valeur du zéro trouvée est de %lf, elle a été trouvée en %d itérations\n", zero, iter);
      coh = false;
      a1 = (rand()%20000)*-1;
      b1 = rand()%20000;
    }
    sleep(1);
  }

  double g(double x){
    return pow(x, 4) + pow(x, 3) + pow(x, 2) - 1;
  }

  int sign(double x){
    // return x/abs(x);
    return (x<0) ? true:false;
  }

  int bisect(double a1, double b1, double epsilon, double *zero/*, int *values[]*/){
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
    *zero=c1;
    // if(!arrayContain(c1, *values[*])){
    // insertInArray(c1, *values[*])
    // }
    return i;
  }

  //
  // bool arrayContain(int a, int b[]){
  //   for(int i = 0; i< 200; i++){
  //     if(a == b[i]){
  //       return true;
  //     }
  //   }
  //   retrun false;
  // }

  // void insertInArray(int value, int *array[]){
  //   for(int i = 0; i< 200; i++){
  //     if(b[i]==0){
  //       *b[i]=value;
  //       return;
  //     }
  //   }
  // }
