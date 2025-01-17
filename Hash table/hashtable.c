#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Table_SIZE 10 


typedef struct person{
    char *name;
    int age;
    struct person *next;
    
}person;

 person* hash_table[MAX_Table_SIZE];

void init_table(){
  for (int i = 0; i < MAX_Table_SIZE; i++)
  {
     hash_table[i] = NULL;
  }
  // Empty Table
}

int hash(char *name){
  int index = 0;
  
  for (int i = 0; i < strlen(name); i++)
  {
      index = index + name[i];
  }
    index = index % MAX_Table_SIZE;
  return index;
}

void print_table(){
      
      for (int i = 0; i < MAX_Table_SIZE; i++)
      {
        if (hash_table[i] == NULL){
            printf("%d\t----\n", i);
        }
        else{
            printf("%d\t", i);
            person* temp = hash_table[i];
            while (temp != NULL)
            {
                printf(" %s - ", temp->name);
                temp = temp->next;
            }
            printf("\n");
            
        }
        
        
      }
      

}
void insert_person(char *name) {
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL) {
        return;  // Handle allocation failure
    }

    int index = hash(name);  
    
    new_person->name = name;          
    new_person->next = hash_table[index];  

    hash_table[index] = new_person;    
}


char *hash_table_lookup(char *name)
{
  int index = hash(name);

  char *noMatch = "Person not here"; // If fail to find

  if(hash_table[index] == NULL)
  {
    return NULL;
  }
   
   person *temp = hash_table[index];
  while (temp!= NULL)
  {
    if (strcmp(temp->name, name) == 0)
    {
      char *result = malloc(strlen("Person Found: ") + strlen(temp->name));
      if(result == NULL)
      {
        return "Memory allocation failed";
      }
       sprintf(result, "Person found: %s", temp->name);
       return result;
      
    }
    temp = temp -> next;
  }
   
   return NULL;
   
}



int main(void){

      init_table(); 
      print_table();
      printf("\nEND\n");

        insert_person("Nabil");
           
               print_table();
          
        printf("\n\n%s",hash_table_lookup("Nabil"));  
      
      
     return 0;
}