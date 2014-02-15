#include <stdio.h>
#include <string.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char ** argv)
{
  //Variables
  int indexx=0;
  int count;
  FILE *filepointer;

  //Executions
  if(argc==1)
    {
      do{
	count=fgetc(stdin);
	if(count!=EOF)
	  {

	    fputc(count,stdout);

	  }

      }while(count!=EOF);
    }
 

  while(indexx < argc )
     {
 
     if(!strcmp(argv[indexx],"--help"))
	{

	  fprintf(stdout , "Usage: cat-lite [--help] [FILE]...\n");
	  fprintf(stdout , "With no FILE, or when FILE is -, read standard input.\n\n");
	  fprintf(stdout , "Examples:\n");

	  fprintf(stdout , " cat-lite README Print the file README to standard output.\n");
	  fprintf(stdout , " cat-lite f - g Print f's contents, then standard input,\n");
	  fprintf(stdout , " then g's contents.\n");
	  fprintf(stdout , " cat-lite Copy standard input to standard output.\n\n");

	  return EXIT_SUCCESS;

	}

      indexx++;

     }

  indexx=1;
  while(indexx<argc)
    {
      if(!strcmp(argv[indexx], "-"))
	{
	  do{
	    count=fgetc(stdin);
	    if(count!=EOF)
	      {
		fputc(count,stdout);
	      }
	  }while(count!=EOF);
	}
      else
	{
	  filepointer=fopen(argv[indexx],"r");
	  if(filepointer==NULL)
	    {
	      fprintf(stderr, "cat cannot open %s\n", argv[indexx]);
	      return EXIT_FAILURE;
	    }
	  do{
	    count=fgetc(filepointer);
	    if(count!= EOF)
	      {
		fputc(count,stdout);
	      }
	  }while(count!=EOF);

	  fclose(filepointer);
	}
      indexx++;
    }
  return EXIT_SUCCESS;
}
