#include <stdio.h>
#include "src/cs50.h"


int average(int array[], int n);

int main(void)
{
      //Ask number of scores
      int n= get_int("Enter The number of Subjects:");      
    
      int scores[n];
     // Ask for the scores
      for(int i= 0; i<n; i++){
        scores[i]= get_int("Your subject score: ");
      }
      // print the result of avarage
      printf("Your average is: %i\n", average(scores, n));
}

int average(int array[], int n)
{
    int sum = 0;
     for(int i=0; i<n; i++)
     {
        sum= sum+array[i];
     }

    return sum / n;
}