#include <stdio.h>
#include "src/cs50.h"
#include <string.h>
#include <stdlib.h>

// Function prototypes
string encryption(string msg);
string decryption(string msg, int key);

int encryptionkey= 52;





int main(void)
{
    // Input the msg
    string msg = get_string("Enter the Secret message: ");
    // Print the Encrypted msg
    string encrypted_msg = encryption(msg);
    printf("Encrypted message: %s\n", encrypted_msg);

    int key = get_int("Enter your decryption Key: ");
    // Print the Decrypted msg
    string decrypted_msg = decryption(encrypted_msg, key);
    printf("Decrypted message: %s\n", decrypted_msg);
}










string encryption(string msg)
{
    int n = strlen(msg);
    // Allocate memory for the encrypted message
    char *encrypted_msg = malloc(n + 1);
    
    // Check if memory allocation was successful
    if (encrypted_msg == NULL)
    {
        return NULL;
    }
    
    for (int i = 0; i < n; i++)
    {
        encrypted_msg[i] = msg[i] - encryptionkey;
    }
    // Null-terminate the encrypted message
    encrypted_msg[n] = '\0';
    
    return encrypted_msg;
}

string decryption(string msg, int key)
{
    int n = strlen(msg);
    // Allocate memory for the decrypted message
    char *decrypted_msg = malloc(n + 1);
    
    // Check if memory allocation was successful
    if (decrypted_msg == NULL)
    {
        return NULL;
    }
    
    for (int i = 0; i < n; i++)
    {
        decrypted_msg[i] = msg[i] + key;
    }
    // Null-terminate the decrypted message
    decrypted_msg[n] = '\0';
    
    return decrypted_msg;
}
