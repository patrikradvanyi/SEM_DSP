#include "RynComplex.h"
#include <math.h>
#include <stdlib.h>

void MultipleWithScalar(Complex* z, float mu){
    z->Real = (z->Real)*mu; /*A valós rész szorzása a skalárral*/
    z->Imag = (z->Imag)*mu; /*A képzeletes rész szorzása a skalárral*/
}

void SumComplex(Complex* z, Complex* w){
    z->Real = z->Real + w->Real;  /* A valós részek összege (eredmény a z-ben) */
    z->Imag = z->Imag + w->Imag;  /* A képzetes részek összege (eredmény a z-ben) */
}

float NormOfComplex(Complex* z){
    return sqrt((z->Real)*(z->Real)+(z->Imag)*(z->Imag)); /* Pythagoras-tétel alkalmazása */
}

float ArgumentOfComplex(Complex* z){
    return atan2(z->Real,z->Imag);  /* A komple szám szögének képzése */
}

void ConjugateComplex(Complex* z){
    z->Imag = (-1)*(z->Imag); /* Konjugálás (a képzetes rész előjelet vált) */
}

Complex* W(int N, int p, int k){
    Complex* w = (Complex*) malloc(sizeof(Complex));  /* Helyfoglalás a Heap-en */

    w->Real = cos(2.0*M_PI*p*k/N);  /* Walsh-vektor valós része */
    w->Imag = (-1)*sin(2.0*M_PI*p*k/N); /* Walsh-vektor képzetes része */

    return w;
}
