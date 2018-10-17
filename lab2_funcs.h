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
void readLine ( char *inputPtr );
int set ( char name, double v );
void printHelp ( void );
int show ( char name );
int show_vars ( void );
int clear ( char name );
int variableOrArray ( char input );
int array ( char name, double start, double stop );
void segmentString ( char *input );
int importCSV ( char var, const char *filename );
int showCSV ( const char *filename );

#endif /* __LAB2_FUNCS_H__ */
