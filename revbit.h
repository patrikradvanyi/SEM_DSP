#ifndef REVBIT_H
#define REVBIT_H

unsigned int revbit(unsigned int word,unsigned int length);	/* Egy "length" bites szót megfordít. */
void revbit_short(float* data, unsigned int logN);	/* A bemeneti (N hosszú) adatsort rendezi, az indexek megfordítása szerint. */

#endif
