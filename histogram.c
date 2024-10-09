#include <stdio.h>

#define MAX_WORD_LENGTH 10


int main(void)
{
   int c;
   int cwl =0;
   int word_length[MAX_WORD_LENGTH +1] = {0};

   while ((c = getchar()) != EOF)
   {
     if( c== '\n' || c == ' ' || c == ',' || c == '\t')
     {
      if(cwl > 0 && cwl <= MAX_WORD_LENGTH)
      {
        word_length[cwl]++;
        cwl = 0;
      }
     }

     else
     {
      cwl++;
     }
   }


   if (cwl > 0 && cwl <= MAX_WORD_LENGTH)
    word_length[cwl]++;

   int max_count = 0;

   for (int i = 1; i <= MAX_WORD_LENGTH; i++)
   {
     if(word_length[i] > max_count)
      max_count = word_length[i];
   }

   for (int i = max_count; i > 0; i--)
   {
     for (int j = 1; j <= MAX_WORD_LENGTH; j++)
     {
       if (word_length[j] >= i)
       {
       printf(" | ");
       }
       else 
       {
        printf("   ");
       }
       
     }
     printf("\n");
     
   }

    for (int j = 1; j <= MAX_WORD_LENGTH; j++)
    {
        printf("---");
    }
    printf("\n");

    for (int i = 1; i <= MAX_WORD_LENGTH; i++)
    {
      printf("%2d ", i);
    }
    printf("\n");


    return 0;
    
   
   
   
   
}