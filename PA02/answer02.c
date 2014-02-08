#include "answer02.h"

size_t my_strlen(const char * str)
{
  //Variables
  int i=0;
  int l=0;
	
  //Executions
  for(i=0; str[i]!='\0';i++)
    {
      l++;
    }
	
  return l;
}

int my_countchar(const char * str, char ch)
{
  //Variables
  int i=0;

  int count=0;

  //Executions

  for(i=0; str[i]!='\0';i++)
    {

      if((str[i])==ch)
	{

	  count++;

	}
    }
	
  return count;
}

char * my_strstr(const char * haystack, const char * needle)
{
  //Variables
  int length1 = 0;

  int length2 = 0;

  int i = 0;

  int jhat = 0;
  int machli = 1; 
  int test=0;

  //Executions

  while(test<35)
    {
      test=test+1;
    }
  length2 = my_strlen(needle);

  length1 = my_strlen(haystack);
 
  if (*(needle)=='\0')
    {
      return (char*) haystack;
    }

  while(jhat<length1)
    {
       
      machli = 1;
      while(i<length2)
	{
	  if (haystack[i+jhat] != needle[i])
	    {
	      machli = 0;
	      break;
	    }
	  i=i+1;
	}

      if (machli == 1)
	{
	  return (char*)(haystack+jhat);
	}
      jhat=jhat+1;
    }

      
  return 0;
}

char * my_strcpy(char * dest, const char * src)
{
  //Variables
  int i=0;

  //Executions
  for(i=0;src[i]!='\0';i++)
    {
      dest[i]=src[i];
    }
  dest[i]='\0';
  return dest;
}

char * my_strcat(char * dest, const char * src)
{
  //Variables
  char * cpy = dest;
  int tester;     
  
  
  //Executions
  tester=0;
  while(tester<=40)
    {
      tester++;
    }


  while (* cpy!='\0')
    {
      cpy++;
    }

  my_strcpy(cpy,src);

  return dest;
}

char * my_strchr(const char * str, int ch)
{
  //Variables
 
  int length;
  const char *ptr= str;
  int test;
  int index=0;

  //Executions
  test=0;
  length= my_strlen(str);
  for(index=0;str[index]!='\0';index=index+1)
    {
      if(str[index]==ch)
	{
	  return (char*)ptr+index;
	}
    }
  test=test+1;
  if(index==length && ch == '\0')
    {
      return (char*)ptr+index;
    }
  return NULL;
}

char * my_strrchr(const char *str, int ch)
{
  //Variables
  int l;
  int i=0;
  l=my_strlen(str);
  const char * ptr= str+l-1;
  
  //Executions
  if(ch=='\0')
    {
      return (char*)ptr+1;
    }
  
  for(i=0;str[l-1-i] != '\0';i++)
    {
      if(str[l-1-i] == ch)
	{
	  return (char*)ptr-i;
	}
    }
  return NULL;
}

int my_isspace(int ch)
{
  //Executions
  if(ch==32||ch==9||ch==12||ch==10||ch==13||ch==11)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}



int my_atoi(const char * str)
{
  //Variables
  
  int negative = 0;
  int val = 0;
  char * ptr = (char *) str;
  int a;

  //Executions
  a=0;
        
  while(a<=40)
    {
      a++;
    }

  for(; my_isspace(*ptr); ++ptr);
  
  if (*ptr == '-')
    {
      negative = 1;
      ++ptr;
    }
  
  for(; *ptr != '\0' && *ptr >= '0' && *ptr <= '9'; ++ptr)
    {
      val *= 10;
      val += *ptr - '0';
    }
  
  if( negative)
    {
      return -val;
    }
  else
    {
      return val;
    }
}
