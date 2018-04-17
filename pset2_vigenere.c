//This program encrypts messages using Vigenere's cipher.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

//Make sure user enters only a single command-line argument.
    if (argc != 2)
    {
        printf("Invalid number of arguments.");
        return 1;
    }

//Make sure the single command-line argument is composed entirely of alphabetical characters.
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Argument must be entirely alphabetical.");
            return 1;
        }
    }

//Convert keyword to all upper-case (per instruction specifications, a is treated as A, b is treated as B, etc.)
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (islower(argv[1][i]))
        {
            argv[1][i] = argv[1][i] - 32;
        }
    }

//Get plaintext from user.
    string s = get_string("plaintext: ");

    printf("ciphertext: ");

//Count the number of non-alphabetical characters there have been for correct indexing, so that these can be ignored when applying the key value.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int count = 0;

        for (int k = 0; k < i; k++)
        {
            if (isalpha(s[k]))
            {
                count = count + 0;
            }
            else
            {
                count = count + 1;
            }
        }

        int j = i;
        int p = 0;

        if (i >= strlen(argv[1]))
        {
            j = i % strlen(argv[1]);
            p = (i - count) % strlen(argv[1]);
        }

        else
        {
            p = (i - count);
        }

//Use the keyword to transform plaintext into ciphertext.
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                printf("%c", ((s[i] + argv[1][p] - 97 - 65) % 26) + 97);
            }

            else
            {
                printf("%c", ((s[i] + argv[1][p] - 130) % 26) + 65);
            }
        }

        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");
}
