#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fht.h"

int main(void) {
	unsigned int i;
	float x[] = {-30,20,-15,44,23,-10,23,10};	/* Teszt adatsor felvétele. */
	float* r = (float*) malloc(8*sizeof(float));	/* Helyfoglalás az amplitúdóspektrumnak. */
	float* h = (float*) malloc(8*sizeof(float));	/* Helyfoglalás a Hartley-transzformáltnak */
	
	recursive_fht(x,h,8);	/* Rekurzív trnaszformáció */
	
	r[0] = h[0];
	for(i=1;i<8;++i){
		r[i] = sqrt(h[i]*h[i]+h[8-i]*h[8-i])/sqrt(2);	/* Amplitúdóspektrum számítása. */
	}

	for(i=0;i<8;++i){
		printf("x[%d]=%6.4f =H=> h[%d]=%6.4f ==> r[%d]=%6.4f\n",i,x[i],i,h[i],i,r[i]);	/* Eredmények kijelézése. */
	}

	return 0;
}
