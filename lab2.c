/* Laboration 2 */

#include "lab2_funcs.h"

int main(int argc, char *argv[])
{
  /*arr A[50] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5,
               1, 2, 3, 4, 5, 1, 2, 3, 4, 5,
               1, 2, 3, 4, 5, 1, 2, 3, 4, 5,
               1, 2, 3, 4, 5, 1, 2, 3, 4, 5,
               1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
      B[50] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
               10, 11, 12, 13, 14, 15, 16, 17,
               18, 19, 20, 21, 22, 23, 24, 25,
               26, 27, 28, 29, 30, 31, 32, 33,
               34, 35, 36, 37, 38, 39, 40, 41,
               42, 43, 44, 45, 46, 47, 48, 49};
  arr R[50], X[50], Y[50];
  var a, b, c, r, x, y;*/
  char input[1000 + 1];
  int a;

  while ( true ) {
    // read line from user
    readLine ( input );

    a = processLine( input );
    printf("\n\n%i\n\n", a);

    // writes out all valid commands to the user
    if ( (strcmp ( input, "help" )) == 0 ) {
      printHelp();
    }

    // exits the program
    else if ( ((strcmp ( input, "exit" )) == 0 ) ||
               (strcmp ( input, "quit" )) == 0 ) {
      exit(0);
    }
/*
    //
    else if ( processLine( input ) == 1 ) {
      printf("\nOHYES");
    }*/

    // not a valid input, displays message and let's the program continue
    else {
      printf("Invalid expression. Try again or write 'help' to display valid commands.'\n");
      continue;
    }
  }

  return 0;
}
