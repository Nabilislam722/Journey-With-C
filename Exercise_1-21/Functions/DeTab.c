#include <stdio.h>



void deTab(char line[], char deLine[], int length) 
{
    int space_count, n = 0;

    for (int i = 0; i < length; i++)
     {
        if (line[i] == '\t') 
        {
            space_count = 8 - (n % 8); 
            for (int j = 0; j < space_count; j++)
             {
                deLine[n++] = ' ';
            }
        } 
        else 
        {
            deLine[n++] = line[i]; 
        }
    }
    deLine[n] = '\0'; 
}
