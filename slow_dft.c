#include <stdio.h>
#include <stdlib.h>
#include "RynComplex.h"

void slow_dft(Complex* X,float* x,unsigned int N);

int main(void){
  int i;
  float x[] = {-30,20,-15,44,23,-10,23,10};
  Complex* X = (Complex*) calloc(8,sizeof(Complex));

  slow_dft(X,x,8);

  for(i=0;i<8;++i){
    printf("X[%d]=(%6.4lf)+j(%6.4lf)\n",i,X[i].Real,X[i].Imag);
  }

  return 0;
}

void slow_dft(Complex* X,float* x,unsigned int N){
  int i,j;
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      Complex* temp = W(N,i,j);
      MultipleWithScalar(temp,x[j]);
      SumComplex(X+i,temp);
      free(temp);
      temp=NULL;
    }
    MultipleWithScalar(X+i, 1.0/N);
  }
}