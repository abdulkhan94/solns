#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

size_t my_strlen(const char * str);
char * my_strstr(const char * haystack, const char * needle);

int main(int argc, char * * argv)
{
  //Variables
  int indexx= 1; 
  int no=0;
  int quote=0;
  int def=0;
  int j=1;
  FILE * fileptr=NULL;
  int found=0;
  int linenumber=0;
  int bufflength=2000;
  char*buffer=malloc(sizeof(char)*bufflength);
  int vag=0;

  if (argc < 2)
    {
      
      printf("Error no input arguments.\n");
      return 2;

    }

  while(indexx<argc)
    {
      if(strcmp(argv[indexx],"--help")==FALSE)
	{
	  printf(" Usage: grep-lite [OPTION]... PATTERN\n");
		 
	  printf(" Search for PATTERN in standard input. PATTERN is a\n");
	  printf(" string. grep-lite will search standard input line by\n");

	  printf(" line, and (by default) print out those lines which\n");
	  printf(" contain pattern as a substring.\n");

	  printf("\n");
	  printf(" -v, --invert-match print non-matching lines\n");

	  printf(" -n, --line-number print line number with output\n");

	  printf(" -q, --quiet suppress all output\n");
	  printf("\n");
	  printf(" Exit status is 0 if any line is selected, 1 otherwise;\n");
	  printf(" if any error occurs, then the exit status is 2.\n\n");
	  free(buffer);

	  return EXIT_SUCCESS;
	}
      indexx=indexx+1;
    }
  while(j<=(argc-2))
    {
      if((strcmp(argv[j],"-v")==FALSE)||((strcmp(argv[j],"--invert-match")==FALSE)))
	{
	  vag=1;
	}
      else if((strcmp(argv[j],"-n")==FALSE)||((strcmp(argv[j],"--line-number")==FALSE)))
	{
	  no=1;
	}
      
      else if ((strcmp(argv[j],"-q")==FALSE)||((strcmp(argv[j],"--quiet")==FALSE)))
	{
	  quote=TRUE;
	}
      else if(argv[j][0]=='-')
	{
	  fprintf(stderr,"Unknown command: %s\nABORTING...\n",argv[j]);
	  return 2;
	}
      j=j+1;
    }

  
  if ((vag+no+quote)==FALSE)
    {
      
      def=1;
    }
 
  if(quote)
    {
      no=0;
      vag=0;
      def=0;
    }

  if (argv[argc-1][FALSE]=='-')
    {

      fprintf(stderr,"Pattern identifier was input wrong.\nABORTING...\n");

      return 2;
    }


  fileptr=stdin;
  while(!feof(fileptr))
    {
      if(fgets(buffer,bufflength,fileptr)!=NULL)
	{
	  linenumber=linenumber+1;
	  if(strstr(buffer,argv[argc-1])!=NULL)
	    {
	      found=1;

	      if (def)
		{


		  printf("%s",buffer);
		
		}

	      if(no&&!vag)
		{
		  printf("%d: %s",linenumber,buffer);
		}
	    }
	  else
	    {
	      if (vag&&no)
		{
		  printf("%d: %s",linenumber,buffer);
		}
	      else if(vag)
		{
		  printf("%s",buffer);
		}
	    }
	}
    }

  free(buffer);

  if(found)
    {
      return FALSE;
    }
  else
    {
      return TRUE;
    }
}
