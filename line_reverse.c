#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char lines[], int count);
void trim_trailing_whitespace(char line[]);
void reverse(char s[]);


int main(void)
{
   char line[MAXLINE]; 
   char lineprime[MAXLINE][MAXLINE];

   int n;

   int i = 0;

   while ((n = get_line(line, MAXLINE)) > 0)
   {
     if (i < n)
     {
        trim_trailing_whitespace(line);

        if (strlen(line) > 0) 
        {
            strcpy(lineprime[i], line); 
            i++;
      
       }
     }
     
   }

   printf("\nTrimmed Lines:\n");
   printf("\n");
   for (int j = 0; j < i; j++) 
   {
       printf("%s\n", lineprime[j]);
    
   }
    printf("\n");
  
   printf("\nREVERSE LINE:\n");
   printf("\n");
   for (int x = 0; x < i; x++)
   {
    reverse(lineprime[x]);
   }
   
}

int get_line(char line[], int limit)
{
  int c, i;

   for ( i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n' ; i++)
     line[i] = c;
   
   if ( c == '\n')
   {
     line[i] = '\n';
     i++;
   }
    line[i]= '\0';

    return i;
}

void trim_trailing_whitespace(char line[]) 
{
    int i = strlen(line) - 1;

   
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
        line[i] = '\0'; 
        i--;
    }
}


void reverse(char s[])
{
  int size = strlen(s);
    char newS[MAXLINE];
    int j = 0;

    for (int i = size - 1; i >= 0; i--) {
        newS[j] = s[i];
        j++;
    }

    newS[j] = '\0';
    printf("%s\n", newS);
    strcpy(s, newS);
  
}