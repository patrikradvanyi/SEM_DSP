#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "revbit.h"

int main(void) {
	unsigned int i;
	float x[] = {0,1,2,3,4,5,6,7};	/* Teszt adatsor felvétele. */

	for(i=0;i<8;++i){
			printf("x[%d]=%6.4f\n",i,x[i]);	/* Teszt adatsor kiírása. */
	}

	printf("\nBit-reversal shorting...\n\n");
	
	revbit_short(x,3);	/* A teszt adatsor rendezése. */
	
	for(i=0;i<8;++i){
		printf("x[%d]=%6.4f\n",i,x[i]);	/* Rendezett adatsor kiírása. */
	}

	return 0;
}
