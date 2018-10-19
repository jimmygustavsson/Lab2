#include "lab2_funcs.h"

// reads the input from terminal and stores it in the array input[1000 + 1]
void readLine ( char *inputPtr )
{
  char character;

  do {
    character = getchar();
    *inputPtr = character;
    inputPtr++;
  }
  while ( character != '\n' );

  *(inputPtr - 1) = '\0';
}


// prints all the valid commands to the user
void printHelp(void)
{
  printf("\tset <var> <value>: Set variable <var> to value <value>, e.g. \"set a 3.14\"\n");
  printf("\tsin <res> <var>: Calculates the sin value of <var> and stores in <res>\n");
  printf("\tshow <var>: Shows a scalar or array of variable\n");
  printf("\tshowFile <filename>: Shows the file <filename>\n");
  printf("\tdeleteFile <filename>: Deletes the file <filename>\n");
  printf("\timportCVS <var> <filename>: Imports variables into the CVS file <filename>\n");
  printf("\texportCVS <filename>: Saves a variable into the CVS file <filename>\n");
  printf("\texportMAT <filename>: Saves a variable into the MatLab file <filename>\n");
  printf("\texportJSON <filename>: Saves a variable into the JSON file <filename>\n");
  printf("\texportXML <filename>: Saves a variable into the XML file <filename>\n");
  printf("\tquit: exit this application\n");
  printf("\texit: exit this application\n");
  printf("\texit x: exit this application with the return code x\n");
}


// find variable and give back a pointer to said variable
matlab_var_t *find_var ( char var )
{
  int i = 0;

  for ( i = 0; i < 6; i++ ) {
    if ( var == vars[i].n ) {
      return &vars[i];
    }
  }

  if ( var <= 'a' && var >= 'z' ) {
    printf("Variable not allowed. Allowed names are a, b, c, r, x, y\n");
  }

  return NULL;
}


// find array and give back a pointer to said array
matlab_arr_t *find_arr ( char var )
{
  int i = 0;

  for ( i = 0; i < 6; i++ ) {
    if ( var == arrs[i].n ) {
      return &arrs[i];
    }
  }

  if ( var >= 'D' && var <= 'Z' ) {
    printf("Not an allowed array. Allowed names are A, B, C, R, X, Y.\n");
  }

  return NULL;
}


// function to determine wether input is a variable or an array
int variableOrArray ( char input )
{
  matlab_arr_t *tempArr;
  matlab_var_t *tempVar;

  tempVar = find_var ( input );
  tempArr = find_arr ( input );

  if ( tempVar != NULL ) {
    return 0;
  }

  if ( tempArr != NULL ) {
    return 1;
  }

  return 666;
}

// Show array or variable
int show ( char name )
{
  int i = 0;

  if ( variableOrArray ( name ) == 0 ) {
    printf("%c = %g\n", (*find_var ( name )).n, (*find_var ( name )).v );
  }

  if ( variableOrArray ( name ) == 1 ) {
    printf("%c = [ ", (*find_arr ( name )).n);
    for ( i = 0; i < ARRAY_LEN; i++ ) {
      printf("%g ", (*find_arr ( name )).v[i] );
    }
    printf("]\n");
  }

  return 0;
}

// Clears the array or varible
int clear ( char name ) {
    int i = 0;

    if ( variableOrArray ( name ) == 0 ) {
	     (*find_var( name )).v = 0.0;
    }

    if ( variableOrArray ( name ) == 1) {
	     for( i = 0; i < ARRAY_LEN; ++i ) {
	        (*find_arr ( name )).v[i] = 0.0;
	     }
    }

    return 0;
}

// segments input array into the values writter by user and returns value as double
void segmentString ( char *input )
{
  char firstValue[100 + 1], secondValue[100 + 1], c;
  int i = 6, firstIndex = 0, j = 8, secondIndex = 0;

  if ( ( strncmp ( input, "set", 3 )) == 0 ) {
    do {
      c = input[i];
      firstValue[firstIndex] = c;
      i++, firstIndex++;
    }
    while ( c != '\0');

    firstValue[firstIndex - 1] = '\0';

    startValue = atof(firstValue);     // global variable startValue
  }

  if ( ( strncmp ( input, "array", 5 )) == 0 ) {
    do {
      c = input[j];
      firstValue[firstIndex] = c;
      j++, firstIndex++;
    }
    while ( c != ' ' );

    firstValue[firstIndex - 1] = '\0';

    startValue = atof(firstValue);   // global variable startValue

     do {
       c = input[j];
       secondValue[secondIndex] = c;
       j++, secondIndex++;
     }
     while ( c != '\0' );

     secondValue[secondIndex - 1] = '\0';

     stopValue = (double) atoi(secondValue);  // global variable secondValue
  }
}

// sets an array to values from start to stop with equal steps inbetween
int array ( char name, double start, double stop )
{
  int i = 0;
  double diff;
  matlab_arr_t *tempArr;

  tempArr = find_arr ( name );

  if ( tempArr != NULL ) {
    diff = stop - start;
    diff = diff / (ARRAY_LEN - 1);

    for ( i = 0; i < ARRAY_LEN; i++ ) {
      (*tempArr).v[i] = start;
      start = start + diff;
    }
  }

  return 666;
}

// sets an array or variable to a start value
int set ( char name, double v ) {
	int i = 0;


    if ( variableOrArray ( name ) == 0 ) {
       (*find_var( name )).v = v;
    }

    if ( variableOrArray ( name ) == 1 ) {
	     for ( i = 0; i < ARRAY_LEN; ++i ) {
	        (*find_arr ( name )).v[i] = v;
	     }
    }

  return 0;
}

// calculator , allows +-*/ operators on variables and +- for arrays
int calc ( char r, char x, char y, char op )
{
  int i = 0;

  switch ( op ) {
    case '+':
      if ( variableOrArray ( x ) == 0 && variableOrArray ( y ) == 0 ) {
        (*find_var ( r )).v = (*find_var ( x )).v + (*find_var ( y )).v;
      }

      if ( variableOrArray ( x ) == 1 && variableOrArray ( y ) ) {
        for ( i = 0; i < ARRAY_LEN; i++ ) {
          (*find_arr ( r )).v[i] = (*find_arr ( x )).v[i] + (*find_arr ( y )).v[i];
        }
      }
      if ( ((variableOrArray ( x ) == 0) && (variableOrArray ( y ) == 1)) ||
           ((variableOrArray ( x ) == 1) && (variableOrArray ( y ) == 0)) ) {
        printf("Operation not allowed.\n");
      }
    break;

    case '-':
      if ( variableOrArray ( x ) == 0 && variableOrArray ( y ) == 0 ) {
        (*find_var ( r )).v = (*find_var ( x )).v - (*find_var ( y )).v;
      }

      if ( variableOrArray ( x ) == 1 && variableOrArray ( y ) ) {
        for ( i = 0; i < ARRAY_LEN; i++ ) {
          (*find_arr ( r )).v[i] = (*find_arr ( x )).v[i] - (*find_arr ( y )).v[i];
        }
      }
      if ( ((variableOrArray ( x ) == 0) && (variableOrArray ( y ) == 1)) ||
           ((variableOrArray ( x ) == 1) && (variableOrArray ( y ) == 0)) ) {
        printf("Operation not allowed.\n");
      }
    break;

    case '*':
      if ( variableOrArray ( r ) == 1 ) {
        printf("Operation not allowed.\n");
        break;
      }
      if ( variableOrArray ( x ) == 0 && variableOrArray ( y ) == 0 ) {
        (*find_var ( r )).v = (*find_var ( x )).v * (*find_var ( y )).v;
      }
      else {
        printf("Operation not allowed, must be variables.\n");
      }
    break;

    case '/':
      if ( variableOrArray ( r ) == 1 ) {
        printf("Operation not allowed.\n");
        break;
      }
      if ( variableOrArray ( x ) == 0 && variableOrArray ( y ) == 0 ) {
        (*find_var ( r )).v = (*find_var ( x )).v / (*find_var ( y )).v;
      }
      else {
        printf("Operation not allowed, must be variables.\n");
      }
    break;

    default:
      printf("Not an allowed operator. Allowed operators are +-*/.\n");
      break;
  }

  return 666;
}

// prints out values of all variables
int show_vars(void)
{
  int i = 0;
  for ( i = 0; i < 6; i++ ) {
    printf("%c = %g\n", vars[i].n, vars[i].v);
  }

  return 0;
}

// prints file to terminal
int showCSV ( const char *filename )
{
  char c;
  FILE *in;

  in = fopen ( filename, "r" );

  while ( (c = getc ( in )) != EOF ) {
    putc (c, stdout);
  }

  fclose ( in );

  return 1;
}

// imports values from a file and stores it in an array of ARRAY_LEN elements
int importCSV ( char var, const char *filename )
{
  int i = 0;
  char valueAsString[50];
  FILE *in;

  in = fopen ( filename, "r" );
  if ( (in = fopen ( filename, "r" )) == NULL ) {
    printf("Canẗ open file.\n");
  }

  for ( i = 0; i < ARRAY_LEN; i++ ) {
    fgets( valueAsString, 100, in );
    (*find_arr ( var )).v[i] = atof ( valueAsString );
  }

  fclose(in);

  return 1;
}

// exports values from a file and stores it in an array of ARRAY_LEN elements
int exportCSV ( char var, const char *filename )
{
  int i = 0;
  FILE *out;

  out = fopen ( filename, "w" );

  for ( i = 0; i < ARRAY_LEN; i++ ) {
    fprintf( out, "%f", (*find_arr(var)).v[i] );
    fputs("\n", out);
  }

  fclose(out);

  return 1;
}

// exports an array to a MAT file
int exportMAT ( char var, const char *filename )
{
  Fmatrix tempStruct;
  FILE *out;
  int i = 0;

  tempStruct.type = 0000;
  tempStruct.mrows = 50;
  tempStruct.ncols = 1;
  tempStruct.imagf = 0;
  tempStruct.namelen = 2;

  char temp[2];
  temp[0] = var;
  temp[1] = '\0';

  if ( variableOrArray(var) == 1 ) {
    out = fopen ( filename, "wb" );

    fwrite( &tempStruct, sizeof(Fmatrix), 1, out );
    fwrite( temp, sizeof(temp), 1, out );
    for ( i = 0; i < ARRAY_LEN; i++ ) {
      fwrite( &(*find_arr(var)).v[i], sizeof(double), 1, out );
    }
  }

  fclose(out);

  return 666;
}

// function to remove interference and fluxing in a given signal
int debounce ( char R, char I )
{
  int i, counter = 0, j;
  for ( i = 0; i < ARRAY_LEN; i ++ ) {
    if ( (*find_arr ( I )).v[i] > 3 ) {
      (*find_arr ( R )).v[i] = 3.3;
    }

    if ( (*find_arr ( I )).v[i] < 0.3 ) {
      (*find_arr ( R )).v[i] = 0;
    }
  }

  // remove signal fluxing from array R
  i = 0;
  while ( i < ARRAY_LEN ) {
    // searching for flux in signal
    if ((*find_arr(R)).v[i] == (*find_arr(R)).v[i + 1]) {
      i++;
    }
    // flux found
    else {
      i++;
        // real signal only when 10 elements in a row has the same value
        for ( ; i < ARRAY_LEN; i++ ) {
          if ( (*find_arr(R)).v[i] == (*find_arr(R)).v[i + 1] ) {
            counter++;

            if ( counter == 10 ) {
              i -= 10;
              for ( j = 0; j < i; j++ ) {
                (*find_arr(R)).v[j] = (*find_arr(R)).v[0];
            }
            break;
          }
        }

        // sets counter to 0 if the condition "10 elements in a row" is not filled
          if ((*find_arr(R)).v[i] != (*find_arr(R)).v[i + 1]) {
            counter = 0;
          }
        }

        break;
      }
    }

  return 0;
}

// function to filter out interference before and after an event in data
int event ( char R, char I ) {
	int i, j, k = 0, eStart, eStop;

	// detecting event start and stop
	for ( i = 0; i < ARRAY_LEN; ++i ) {
		j = i;
		while ( (*find_arr(I)).v[j] >= 0.5 ) {
			++j;
			++k;

			if ( k == 10 ) {
				eStart = i;
			}

			if ( (*find_arr(I)).v[j] < 0.5 ) {
				eStop = j;
			}
		}
	}

	// loops in event data into result array
	j = eStop;
	clear ( (*find_arr(R)).n );

	for ( i = eStart; i <= j; ++i ) {
		(*find_arr(R)).v[i] = (*find_arr(I)).v[i];
	}

	printf("Event detected @%i\n", eStart);
	printf("Event stopped  @%i\n", eStop);

	return 0;
}
