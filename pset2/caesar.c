//This program encrypts messages using Caesar's cipher.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

//Make sure user enters only a command line argument, k.
    if (argc != 2)
    {
        printf("Invalid number of arguments.");
        return 1;
    }

//Convert user input to be stored as an integer.
    int k = atoi(argv[1]);

//Make sure the input is a non-negative integer.
    if (k < 0)
    {
        printf("Need to enter a non-negative integer.");
        return 1;
    }

//Get plaintext from user.
    string s = get_string("plaintext: ");

//Use the key to transform plaintext into ciphertext.

    printf("ciphertext: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {

        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                printf("%c", ((s[i] + k - 97) % 26) + 97);
            }

            else
            {
                printf("%c", ((s[i] + k - 65) % 26) + 65);
            }
        }
        else
        {
            printf("%c", s[i]);
        }

    }

    printf("\n");
}
