/* Laboration 2 */

#include "lab2_funcs.h"



int main(int argc, char *argv[])
{
  matlab_arr_t arrs[6];
  arrs[0] = { 'A', {1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0,
                    3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0,
                    5.0, 1.0, 2.0, 3.0, 4.0, 5.0, 1.0,
                    2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0,
                    4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0,
                    1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0,
                    3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0,
                    5.0} };
  arrs[1] = { 'B', {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0,
                    7.0, 8.0, 9.0, 10.0, 11.0, 12.0,
                    13.0, 14.0, 15.0, 16.0, 17.0, 18.0,
                    19.0, 20.0, 21.0, 22.0, 23.0, 24.0,
                    25.0, 26.0, 27.0, 28.0, 29.0, 30.0,
                    31.0, 32.0, 33.0, 34.0, 35.0, 36.0,
                    37.0, 38.0, 39.0, 40.0, 41.0, 42.0,
                    43.0, 44.0, 45.0, 46.0, 47.0, 48.0,
                    49.0} };
  arrs[2].n = 'C';
  arrs[3].n = 'R', arrs[4].n = 'X', arrs[5].n = 'Y';

  matlab_var_t vars[6];
  vars[0].n = 'a', vars[1].n = 'b', vars[2].n = 'c';
  vars[3].n = 'r', vars[4].n = 'x', vars[5].n = 'y';

  char input[1000 + 1];

  while ( true ) {
    // read line from user
    readLine ( input );

    // writes out all valid commands to the user
    if ( (strcmp ( input, "help" )) == 0 ) {
      printHelp();
    }

    // exits the program
    else if ( ((strcmp ( input, "exit" )) == 0 ) ||
               (strcmp ( input, "quit" )) == 0 ) {
      exit(0);
    }


    // not a valid input, displays message and let's the program continue
    else {
      printf("Invalid expression. Try again or write 'help' to display valid commands.'\n");
      continue;
    }
  }

  return 0;
}