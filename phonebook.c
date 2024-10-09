#include <stdio.h>
#include <string.h>
#include "src/cs50.h"


  int main(void)
  {
     FILE *file = fopen("phonebook.csv", "a");
       
       string name =get_string("ENTER YOUR NAME:");
        string number = get_string("ENTER YOUR PHONE NUMBER:");

        fprintf(file, "%s,\t%s\n", name, number);
      fclose(file);
     return 0;

  }