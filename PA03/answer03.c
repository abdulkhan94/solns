#include "answer03.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int comparison(const void * prime1, const void * prime2);
int compareCharacter(const void * prime1, const void * prime2);


char * strcat_ex(char * * dest, int * n, const char * src)
{
  //Variables
  char * buffer;
  int src_length;
  int dest_length;

  //Executions
  src_length= strlen(src);
  if(*dest==NULL)
    {
      dest_length=0;
    }
  else
    {
     dest_length=strlen(*dest);
    }

  if(*dest==NULL||(1+src_length+dest_length)>= *n)
    {
      *n=1+2*(src_length+dest_length);
      buffer=malloc(*n * sizeof(char));

      *buffer='\0';
      
      if(*dest!=NULL)
	{
	  strcpy(buffer,*dest);
	}

      free(*dest);
      *dest=buffer;

    }

  strcat(*dest,src);


  return *dest;


}

