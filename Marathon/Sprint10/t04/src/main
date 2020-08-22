#include "mx_cat.h"
#include <stdio.h>

int main(void)
{
   const char *myfile = "test.txt";
   int bytes = 0;
   int words = 0;
   int newLine = 0;
   char buffer[1];
   int file = open(myfile,O_RDONLY);
   enum states { WHITESPACE, WORD };
   int state = WHITESPACE;
   if(file == -1){
      printf("can not find :%s\n",myfile);
   }
   else{
      char last = ' ';
      while (read(file,buffer,1) ==1 )
      {
         bytes++;
         if ( buffer[0]== ' ' || buffer[0] == '\t'  )
         {
            state = WHITESPACE;
         }
         else if (buffer[0]=='\n')
         {
            newLine++;
            state = WHITESPACE;
         }
         else
         {
            if ( state == WHITESPACE )
            {
               words++;
            }
            state = WORD;
         }
         last = buffer[0];
      }
      printf("%d        %d      %d      %s\n",newLine,words,bytes,myfile);
   }

}
