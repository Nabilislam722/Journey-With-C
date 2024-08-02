#include <stdio.h>
#include <stdlib.h>

 int main(void)
 {
    // Finding the maximum number in a array
    int array[] = {10, 11, 1, 13, 131, 1313, 317, 1384, 5, 8167425};
     
       int lenth = sizeof(array) / sizeof(array[0]);
     
          int maxn = array[0];
      
       for (int i = 0; i < lenth; i++)
       {
          if (maxn <= array[i])
          {
            maxn = array[i];
          }
          
       }
       
      printf("Your max is: %i\n", maxn);
      return 0;
 }