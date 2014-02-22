#include "answer05.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/**
 * Loads an ECE264 image file, returning an Image structure.
 * Will return NULL if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
Image * Image_load(const char * filename)
{
  //Variables
  FILE * point=NULL;
  ImageHeader head;
  size_t r=0;
  int c=5;
  Image * img=NULL;
  int k=4;
  int error=0;
  int tester=1;
  Image * temp_img=NULL;
  
  //Executions
  if(error==0)
    {
      point=fopen(filename,"rb");
      if(!point)
	{
	  error=1;
	  fprintf(stderr,"Failed to open file '%s'\n",filename);
	}
    }
  
  if (error==0)
    {
      r=fread(&head,sizeof(ImageHeader),1,point);
      if (r!=1)
	{
	  error=1;
	  fprintf(stderr,"Failed to read header from '%s'\n",filename);
	}
    }
  
  for(k=0; k<22;k++)
    {
      c=c+2;
    }
  
   if(error==0)
    {
      if(head.magic_number!=ECE264_IMAGE_MAGIC_NUMBER)
	{
	  error=1;
	  fprintf(stderr,"Magic Number is incorrect.\n");
	}
    }	
   
   

   if(error==0)
     {
     
       if(head.height==0)
	 {
	   error=1;
	   printf("Error: Height is zero.\n");
	 }
       if(head.width==0) 
	 {
	   error=1;
	   printf("Error: Width is zero.\n");
	 }      

       if (head.comment_len == 0) 
	 {
	   error=1;
	   printf("Error: Comment length is zero.\n");
	 }
     }

  if(error==0)
    {
      temp_img=malloc(sizeof(Image));
      if(temp_img==NULL)
	{
	  error=1;
	  fprintf(stderr,"Failed to allocate memory structure\n");
	}
    }

  if(error==0)
    {
      temp_img->comment=malloc(head.comment_len);
      if(temp_img->comment==NULL)
	{
	  error=1;
	  fprintf(stderr,"Failed to allocate comment memory structure\n");
	}
    }

  if(error==0)
    {
      temp_img->data=malloc(sizeof(uint8_t)*head.height*head.width);
      if(temp_img->data==NULL)
	{
	  error=1;
	  fprintf(stderr,"Failed to allocate data memory structure\n");
	}
    }
  
  while(tester<10)
    {
      tester=tester+1;
    }

  if(error==0)
    {
      temp_img->height=head.height;
      temp_img->width=head.width;
    }

  if(error==0)
    {
      if(fseek(point,sizeof(ImageHeader),SEEK_SET)!=0)
	{
	  error=1;
	  fprintf(stderr,"Failed to seek %lu, the beginning of comment.\n",sizeof(ImageHeader));
	}
    }

  if(error==0)
    {
      r=fread(temp_img->comment,sizeof(char),head.comment_len,point);
      if (head.comment_len!=r)
	{
	  error=1;
	  fprintf(stderr, "Error: Only read %zd of %i bytes of the comment\n",r,head.comment_len);
	}
    }

 
  if(error==0)
    {
      if((temp_img->comment[(head.comment_len)-1])!='\0')
	{
	  error=1;
	  printf("Error: No null byte.\n");
	}
    }

  
  if(error==0)
    {
      int new=head.width*head.height;
      r=fread(temp_img->data,sizeof(uint8_t),new,point);
      if(r!=new)
	{
	  error=1;
	  fprintf(stderr,"Only read %zd of %i bytes of image data.\n",r,new);
	}
    }

  if(error==0)
    {
      uint8_t bytes;
      bytes=0;
      r=fread(&bytes,sizeof(uint8_t),1,point);
      if(r!=0)
	{
	  error=1;
	  fprintf(stderr,"Stray bytes at the end of bmp file '%s'.\n",filename);
	}
    }

  if(error==0)
    {
      img=temp_img;
      temp_img=NULL;
    }

  
  if(temp_img!=NULL)
    {
      free(temp_img->comment);
      free(temp_img->data);
      free(temp_img);
    }
    
  if(point)
    {
      fclose(point);
    }

  return img;

}
/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image)
{
  //Variables
  ImageHeader head;
  FILE * point=fopen(filename,"w");
  int indexx=0;

  //Executions
  head.magic_number=ECE264_IMAGE_MAGIC_NUMBER;
  head.width=image->width;
  head.height=image->height;
  head.comment_len=strlen(image->comment)+1;

  fwrite(&head,sizeof(ImageHeader),1,point);
  fprintf(point,"%s%c",image->comment,'\0');

  for(indexx=0;indexx<image->height*image->width;indexx=indexx+1)
    {
      fprintf(point,"%c",image->data[indexx]);
    }

  fclose(point);
  return 1;

}
/**
 * Free memory for an image structure
 *
 * Image_load(...) (above) allocates memory for an image structure. 
 * This function must clean up any allocated resources. If image is 
 * NULL, then it does nothing. (There should be no error message.) If 
 * you do not write this function correctly, then valgrind will 
 * report an error. 
 */
void Image_free(Image * image)
{
  if (image != NULL)
    {
      free(image->comment);
      free(image->data);
      free(image);
    }
  return;

}
/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity)
{
  //Variables
  uint8_t maximum;
  int indexx;
  uint8_t minimum;
 
  maximum=intensity[0];
  minimum=maximum;
  
  for(indexx=1;indexx<width*height;indexx++)
    {
      if(intensity[indexx]<minimum)
	{
	  minimum=intensity[indexx];
	}
 
     if(intensity[indexx]>maximum)
	{
	  maximum=intensity[indexx];
	}

    }
  
  for(indexx=0;indexx<width*height;indexx=indexx+1)
    {
      intensity[indexx]=(intensity[indexx]-minimum)*255/(maximum-minimum);
    }


}
