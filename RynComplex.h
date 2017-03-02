#ifndef RYNCOMPLEX_H
#define RYNCOMPLEX_H

typedef struct{
  float Real;  /* A komplex szám valós része */
  float Imag;  /* A komplex szám képzetes része */
} Complex;

void MultipleWithScalar(Complex* z, float mu);   /* A "z" komplex számot megszorozza "mu" skalár számmal és az eredményt a paraméterlistán adja vissza */
void SumComplex(Complex* z, Complex* w);  /* A "z" és "w" komplex számokat összeadja és  az elerdményt az első argumentumban adja vissza */
float NormOfComplex(Complex* z);  /* Kiszámítja a "z" komplex szám hosszát */
float ArgumentOfComplex(Complex* z); /* Kiszámítja a "z" komplex szám szögét (radiánban) */
void ConjugateComplex(Complex* z);  /* Konjugálja a "z" komplex számot és az eredményt a paraméterlitán adja vissza */
Complex* W(int N, int p, int k); /* Kiszámolja az exp(-j2*pi*p*k/N) komplex számokat */

#endif
