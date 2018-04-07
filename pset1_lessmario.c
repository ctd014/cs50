//This program prints out a half-pyramid of a specified height.

#include <cs50.h>
#include <stdio.h>


// prompts user for height
// only accepts valid heights
int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n<0 || n>23);


// makes pyramid
for (int i = 1; i<n+1; i++)
    {
    for (int j = 0; j<n-i; j++)
    {
        printf(" ");
    }
    for (int k = 0; k < i+1; k++)
    {
        printf("#");
    }
    printf("\n");
    }
}
