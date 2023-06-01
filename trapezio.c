#include <stdio.h>
#include <math.h>

double areaTrapezio (double baseMaior, double baseMenor, double altura) {
  return(((baseMaior + baseMenor) * altura)/2);
}

int main() {
  double areat;
  areat = areaTrapezio(10, 8, 5);
  printf("A area do trapézio é %f\n", areat);
  
  return 0;
}