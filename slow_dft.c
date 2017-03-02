#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "RynComplex.h"

void slow_dft(Complex* X,float* x,unsigned int N);  /* Függvény prototípus */

int main(void){
  int i;  /* Ciklusváltozó */
  float x[] = {-30,20,-15,44,23,-10,23,10}; /* Teszt adatsor */
  Complex* X = (Complex*) calloc(8,sizeof(Complex));  /* Helyfoglalás az eredménynek a Heap-en */
  float* rX = (float*) calloc(8,sizeof(float)); /* Helyfoglalás az amplitúdóspektrumanak a Heap-en */

  slow_dft(X,x,8);  /* Fourier-trnaszformáció elvégzése */

  for(i=0;i<8;++i){
    rX[i] = sqrt((X[i].Real)*(X[i].Real) + (X[i].Imag)*(X[i].Imag));  /* Amplitúdóspektrum számítása */
  }

  for(i=0;i<8;++i){
    printf("X[%d]=(%6.4lf)+j(%6.4lf) => rX[%d]=%6.4f\n",i,X[i].Real,X[i].Imag,i,rX[i]); /* Eredmények kiírása */
  }

  return 0;
}

void slow_dft(Complex* X,float* x,unsigned int N){
  int p,k;  /* Ciklusváltozók */
  for(p=0;p<N;++p){
    for(k=0;k<N;++k){
      Complex* temp = W(N,p,k); /* Walsh-vektor ideiglenes létrehozása */
      MultipleWithScalar(temp,x[k]);  /* Walsh-vektor szorzása a mintával */
      SumComplex(X+p,temp); /* Összegzés */
      free(temp); /* Az ideiglenesen tárolt adatok eldobása */
      temp=NULL;
    }
    MultipleWithScalar(X+p, 1.0/sqrt(N)); /* Spketrumkomponens normálása */
  }
}
