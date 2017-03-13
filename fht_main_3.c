#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fht.h"

int main(void) {
	unsigned int i;
	float x[] = {-30,20,-15,44,23,-10,23,10};	/* Teszt adatsor felvétele. */
	float* r = (float*) malloc(8*sizeof(float));	/* Helyfoglalás az amplitúdóspektrumnak. */
	float* h = (float*) malloc(8*sizeof(float));	/* Helyfoglalás a Hartley-transzformáltnak */

	for(i=0;i<8;++i){
			printf("x[%d]=%6.4f\n",i,x[i]);	/* Tesztadatok kijelzése, mert a trnaszformálás után már nem állnak rendelkezésre. */
		}

	printf("\nIterative FHT...\n\n");

	iterative_fht(x,3);	/* Iteratív transzformáció. */

	r[0] = x[0];
	for(i=1;i<8;++i){
		r[i] = sqrt(x[i]*x[i]+x[8-i]*x[8-i])/sqrt(2);	/* Amplitúdóspektrum számítása. */
	}

	for(i=0;i<8;++i){
		printf("h[%d]=%6.4f ==> r[%d]=%6.4f\n",i,x[i],i,r[i]);	/* Eredmények kijelézése. */
	}

	free(r);
	free(h);

	return 0;
}
