#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "revbit.h"

unsigned int revbit(unsigned int word, unsigned int length){
  unsigned int mask1 = 0x55555555;	/* Maszkok a bit-reversal művelethez. */
  unsigned int mask2 = 0x33333333;
  unsigned int mask4 = 0x0f0f0f0f;
  unsigned int mask8 = 0x00ff00ff;
  unsigned int mask16 = 0x0000ffff;

  word = ((word & mask1) << 1) | ((word & (~mask1)) >> 1);	/* Egymás mellett lévő bitek cseréje. */
  word = ((word & mask2) << 2) | ((word & (~mask2)) >> 2);	/* Egymás mellett lévő kettes csoportok cseréje. */
  word = ((word & mask4) << 4) | ((word & (~mask4)) >> 4);	/* Egymás mellett lévő négyes csoportok cseréje. */
  word = ((word & mask8) << 8) | ((word & (~mask8)) >> 8);	/* Egymás mellett lévő nyolcas csoportok cseréje. */
  word = ((word & mask16) << 16) | ((word & (~mask16)) >> 16);	/* Egymás mellett lévő tizenhatos csoportok cseréje. */

  word = word >> (32-length);	/* Ha kisebb a szó, mint 32 bit, akkor a korrekció (shiftelés) végrehajtása. */

  return word;
}

void revbit_short(float* data, unsigned int logN){
  unsigned int i;
  unsigned int N = 1 << logN;	/* Adatsor hosszának számítása (hatványozás). */
  float* temp = (float*) malloc(N*sizeof(float));

  for (i = 0; i < N; ++i) {
    temp[i] = data[i];	/* Bemenet ideignelenes tárolása. */
  }

  for(i=0;i<N;++i){
    data[i] = temp[revbit(i,logN)];	/* Rendezés végrehajtása. */
  }

  free(temp);
}
