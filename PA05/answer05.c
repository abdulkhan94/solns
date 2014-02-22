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
  size_t num_bytes=0;
  int r;
  Image * img=NULL;
  Image * temp_img=NULL;
  ImageHeader head;
  FILE *point=NULL;
  
  //Executions
  point = fopen(filename, "r");
     
  if(point==NULL)
    {
      
      return img;

    }

  r=fread(&head,sizeof(ImageHeader),1,point);
  
  if(r==0)
    {
      fclose(point);
      return img;
    }

  if(ECE264_IMAGE_MAGIC_NUMBER!=head.magic_number)
    {
      fclose(point);
      return img;
    }

  
  if(head.width==0||head.height==0)
    {
      fclose(point);
      return img;
    }

  
  if(head.comment_len==0)
    {
      fclose(point);
      return img;
    }
  
  char * comm=malloc(head.comment_len * sizeof(char));
  if(comm== NULL)
    {
      fclose(point);

      free(comm);

      return temp_img;
    }
  
 
  r=fread(comm,head.comment_len,1,point);
  if(head.comment_len!=r)
    {

      fclose(point);
      free(comm);

      return temp_img;
    }
  
  if(comm[head.comment_len-1]!='\0')
    {
      fclose(point);
      free(comm);
      return img;
    }
  
  num_bytes=sizeof(uint8_t)*head.width*head.height;
  img=malloc(sizeof(Image));
  img->width=head.width;
  img->height=head.height;
  img->comment=malloc(sizeof(char)*(strlen(comm)+1));
  strcpy(img->comment,comm);
  img->data=malloc(num_bytes);
  if(img->data== NULL)
    {
      Image_free(img);
      fclose(point);
      return temp_img;
    }
  
  r=fread(img->data,sizeof(uint8_t),num_bytes,point);
  
  if(r!=num_bytes)
    {
      Image_free(img);
      free(comm);
      fclose(point);
      return temp_img;
    }

  uint8_t bytes;
  
  r=fread(&bytes,sizeof(uint8_t),1,point);

  if(r!=0)
    {
      Image_free(img);
      free(comm);
      fclose(point);
      return temp_img;
    }
   
  free(comm);
  fclose(point);
  return(img);


}
/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image)
{


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

}
/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity)
{



}
