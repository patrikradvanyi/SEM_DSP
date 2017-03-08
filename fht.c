#include <math.h>
#include "fht.h"
#include "revbit.h"

void iterative_fht(float* input,unsigned int logN){
  unsigned int N,M,logM,i,j;
  float temp1,temp2;

  N = 1 << logN;	/* Az adatsor hosszának számítása.  */

  revbin_short(input,logN);	/* Bemeneti adatsor rendezése. */

  for(logM = 1;logM<=logN;++logM){

    M = 1 << logM;	/* Az aktuális pillangók hosszának számítása. */

    for(i=0;i<=(N-M);i=i+M){	/* Végighaladás az M-es csoportokon. */

      for(j=1;j<(M/4);++j){	/* Az M-es csoport második felé a Node-shift végrehajtása. */
        temp1 = input[i+M/2+j];
        temp2 = input[i+M-j];
        input[i+M/2+j] = temp1*cos(2.0*M_PI*j/M)+temp2*sin(2.0*M_PI*j/M);
        input[i+M-j] = temp1*sin(2.0*M_PI*j/M)-temp2*cos(2.0*M_PI*j/M);
      }

      for(j=0;j<M/2;++j){	/* A pillangó végrehajtása. */
        temp1 = input[i+j];
        temp2 = input[i+j+M/2];
        input[i+j] = (temp1 + temp2)/sqrt(2);
        input[i+j+M/2] = (temp1 - temp2)/sqrt(2);
      }
    }
  }
}

void recursive_fht(float* input,float* output,int N){
  int i;
  float temp1,temp2;
  float even_output[N/2],odd_output[N/2],even_input[N/2],odd_input[N/2];	/* A rekurzív számításokhoz szükséges hely foglalása a stack-ben. */

  if(N==1){	/* Bázisfeltétel. */
    output[0] = input[0];
    return;
  }

  for(i=0;i<N/2;++i){	/* Bemenet szétválogatása. */
    even_input[i] = input[2*i];
    odd_input[i] = input[2*i+1];
  }

  recursive_fht(even_input,even_output,N/2);	/* Páros DHT.*/
  recursive_fht(odd_input,odd_output,N/2);	/* Páratlan DHT. */

  for(i=1;i<N/4;++i){	/* Node-shift művelet végrehajtása a páratlan transzformáltakon. */
    temp1 = odd_output[i];
    temp2 = odd_output[N/2-i];
    odd_output[i] = temp1*cos(2.0*M_PI*i/N)+temp2*sin(2.0*M_PI*i/N);
    odd_output[N/2-i] = temp1*sin(2.0*M_PI*i/N)-temp2*cos(2.0*M_PI*i/N);
  }

  for(i=0;i<N/2;++i){	/* Pillangók végrehajtása. */
    output[i] = (even_output[i]+odd_output[i])/sqrt(2);
    output[N/2+i] = (even_output[i]-odd_output[i])/sqrt(2);
  }
}

void slow_dht(float* input, float* output, int N){
  int i,j;
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      output[i] = output[i] + input[j]*(cos(2.0*M_PI*i*j/N)+sin(2.0*M_PI*i*j/N));	/* Hartley-transzformáció a definíció szerint. */
    }
    output[i] = output[i]/sqrt(N);	/* Komponens normálása. */
  }
}
