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

char * * explode(const char * str, const char * delims, int * arrLen)
{
  //Variables
  const char *position= str;
  *arrLen=1;

  //Executions
  while(*position!='\0')
    {
      if(strchr(delims,*position))
	{
	  *arrLen=*arrLen+1;
	}
      position++;
    }
  
  char * * stringArr=malloc(*arrLen * sizeof(char*));
  
  int index1=0;
  const char *begin=str;
  position = str;

  while(*position!='\0')
    {
      if(strchr(delims, *position))
	{
	  int length = position - begin;
	  stringArr[index1]= malloc( (1+length) * sizeof(char));
	  
	  memcpy(stringArr[index1],begin,(length)*sizeof(char));
	  stringArr[index1][length]='\0';
	  index1=index1+1;
	  begin= position+1;
	}
      position=position+1;
    }

  int length=position - begin;
  stringArr[index1]=malloc((1+length)*sizeof(char));
  memcpy(stringArr[index1],begin,(length)*sizeof(char));
  stringArr[index1][length]='\0';
  return stringArr;

}


char * implode(char * * strArr, int len, const char * glue)
{
  //Variables
  int i=0;

  int length=0;

  char * string1 = malloc(1*sizeof(char));
  strcpy(string1, "");
  
  //Executions
  while(i<length)
    {
      string1= strcat_ex(&string1,&length,strArr[i]);
      if((i+1)!=length)
	{
	  string1=strcat_ex(&string1,&length,glue);
	}
      i=i+1;
    }
  
  return string1;


}


void sortStringArray(char * * arrString, int len)
{
  qsort(arrString, len, sizeof(char*),comparison);

}

int comparison(const void * prime1, const void * prime2)
{
  return(strcmp(*(char**) prime1, *(char**) prime2));

}

void sortStringCharacters(char * str)
{
  qsort(str,strlen(str),sizeof(char),compareCharacter);
  return;
}

int compareCharacter(const void * prime1, const void * prime2)
{
  return(*(char*)prime1 - *(char*)prime2); 

}
