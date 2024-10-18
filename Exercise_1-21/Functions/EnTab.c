#include <stdio.h>


void Entab(char line[], char enLine[], int length) {
    int Space_count = 0, n = 0;

    for (int i = 0; i < length; i++) {
        
        if (line[i] == ' ') 
        {
            Space_count++;
        } 
        else 
        {
            
            while (Space_count > 0) {
                if (Space_count >= 8) 
                { 
                    enLine[n++] = '\t'; 
                    Space_count -= 8; 
                } 
                else 
                {
                    enLine[n++] = ' ';
                    Space_count--;
                }
            }
            enLine[n++] = line[i]; 
        }
    }

    
    while (Space_count > 0) 
    {
        enLine[n++] = ' ';
        Space_count--;
    }

    enLine[n] = '\0'; 
}
