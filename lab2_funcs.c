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
    printf("%f", (*find_var( name )).v );
  }

  if ( variableOrArray ( name ) == 1 ) {
    for ( i = 0; i < 50; i++ ) {
      printf("%f\n", (*find_arr ( name )).v[i] );
    }
  }

  return 0;
}

// Clears the array or varible
int clear(char name){
    int i = 0;


    if ( variableOrArray ( name ) == 0){
	(*find_var( name )).v = 0.0;
    }
    if ( variableOrArray ( name ) == 1){
	for( i = 0; i < 50; ++i){
	    (*find_arr ( name )).v[i] = 0.0;
	}
    }

    return 0;
}

