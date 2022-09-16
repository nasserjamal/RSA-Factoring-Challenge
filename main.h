#ifndef MAIN_H
#define MAIN_H
#define  _POSIX_C_SOURCE 200809L

/* Libraries to include */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* For bolean variables */
#include <stdint.h> /* For 64 bit integers. I.e very long numbers : Yaani number ndefuuuu*/
#include <math.h>
#include <string.h>

/* Function prototypes */
/* File managers */
FILE *openFile(int argc, char **argv);

void processLine(char *line);
int getNextPrime(int prevPrime);
bool isPrime(int num);
char *removeWhiteSpaces(char *str);


void process64bitLine(char *line);
char *arrDiv(uint64_t *numbers, uint64_t div, int arrSize, int len);
char *arrStr(uint64_t *numbers, int arrSize, int len);
uint64_t arrMod(uint64_t *numbers, int mod, int arrSize);
uint64_t addCarry(uint64_t num, uint64_t carry);

#endif
