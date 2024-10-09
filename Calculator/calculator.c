#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
 int oparation(char *input);
 int performOperation(int result, int number, char operator);
 

 
 int main(void)
 {
    
  char *input = malloc(100 * sizeof(char));

  printf("Calculator:\n");
   scanf("%s", input);
   
  printf("Result:%i", oparation(input));
   
   free(input);

 }


 int oparation(char *input)
 {
    int result = 0;
    int currentNumber = 0;  
    char currentOperator = '+';  

    int i = 0, len = strlen(input);

    // Parse the input string
    while (i <= len) {
        if (input[i] >= '0' && input[i] <= '9') {
 
            currentNumber = currentNumber * 10 + (input[i] - '0');

        } 
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || i == len) {
            
            result = performOperation(result, currentNumber, currentOperator);
            currentOperator = input[i];
            currentNumber = 0;
        }
      
        i++;
        
    }

    return result;
 }


int performOperation(int result, int number, char operator) {
    switch (operator) {
        case '+': return result + number;
        case '-': return result - number;
        case '*': return result * number;
        case '/': 
            if (number != 0)
                return result / number;
            else {
                return result = 0; 
            }
        default: return result;
    }
}
