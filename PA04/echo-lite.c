#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * * argv)
{
  //Variables
  int indexx=0; 

  //Executions
  for(indexx=1;indexx<argc;indexx++)
    {
      printf("%s",argv[indexx]);
      printf(" ");
    }

  printf("\n");
  return 0;
}
