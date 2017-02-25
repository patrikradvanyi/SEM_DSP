#include "RynComplex.h"
#include <math.h>
#include <stdlib.h>

void MultipleWithScalar(Complex* z, float mu){
    z->Real = (z->Real)*mu;
    z->Imag = (z->Imag)*mu;
}

void SumComplex(Complex* z, Complex* w){
    z->Real = z->Real + w->Real;
    z->Imag = z->Imag + w->Imag;
}

float NormOfComplex(Complex* z){
    return sqrt((z->Real)*(z->Real)+(z->Imag)*(z->Imag));
}

float ArgumentOfComplex(Complex* z){
    return atan2(z->Real,z->Imag);
}

void ConjugateComplex(Complex* z){
    z->Imag = (-1)*(z->Imag);
}

Complex* W(int N, int p, int k){
    Complex* w = (Complex*) malloc(sizeof(Complex));
    
    w->Real = cos(2.0*M_PI*p*k/N);
    w->Imag = (-1)*sin(2.0*M_PI*p*k/N);
    
    return w;
}