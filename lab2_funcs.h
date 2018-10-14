#ifndef __LAB2_FUNCS_H__
#define __LAB2_FUNCS_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "lab2.h"


// add all other functions below
int clear ( char var );
int calc ( char r, char x, char y, char op );
void readLine( char *inputPtr );
int set ( char variable, double value );
void printHelp( void );


#endif /* __LAB2_FUNCS_H__ */
