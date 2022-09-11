#ifndef MAIN_H
#define MAIN_H
#define  _POSIX_C_SOURCE 200809L

/* Libraries to include */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* For bolean variables */
#include <stdint.h> /* For 64 bit integers. I.e very long numbers : Yaani number ndefuuuu*/

/* Function prototypes */
/* File managers */
FILE *openFile(int argc, char **argv);

void processLine(char *line);
int getNextPrime(int prevPrime);
bool isPrime(int num);

#endif
