#ifndef FHT_H
#define FHT_H

void iterative_fht(float* input,unsigned int n);	/* Iteratív módon végzi a Gyors Hartley-transzformációt, a bemeneti adatsor változik. */
void recursive_fht(float* input,float* output,int N);	/* Rekurzív módon végzi el az FHT-t, a stack mechanizmust használja! */
void slow_dht(float* input, float* output, int N);	/* Definíció szeerint végzi a DHT-t. */

#endif //FHT_H
