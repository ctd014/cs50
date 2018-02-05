#include <cs50.h>
#include <stdio.h>

// prompts user for heights
// only accepts valid heights per direction specifications

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

// makes pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf("\n");
    }

}
