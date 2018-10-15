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
  printf("set <var> <value>: Set variable <var> to value <value>, e.g. \"set a 3.14\"\n");
  printf("sin <res> <var>: Calculates the sin value of <var> and stores in <res>\n");
  printf("show <var>: Shows a scalar or array of variable\n");
  printf("showFile <filename>: Shows the file <filename>\n");
  printf("deleteFile <filename>: Deletes the file <filename>\n");
  printf("importCVS <var> <filename>: Imports variables into the CVS file <filename>\n");
  printf("exportCVS <filename>: Saves a variable into the CVS file <filename>\n");
  printf("exportMAT <filename>: Saves a variable into the MatLab file <filename>\n");
  printf("exportJSON <filename>: Saves a variable into the JSON file <filename>\n");
  printf("exportXML <filename>: Saves a variable into the XML file <filename>\n");
  printf("quit: exit this application\n");
  printf("exit: exit this application\n");
  printf("exit x: exit this application with the return code x\n");
}


/*
matlab_var_t *find_var ( char var )
{

}


//
matlab_arr_t *find_arr ( char var )
{

}*/
