//This program calculates the minimum number of coins required to give a user change.

//import libraries
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    //get change due (e.g. if $9.27 is due, input as 9.27)
    float c;
    do
    {
    c = get_float("Change owed: ");
    }
    while (c<0);

    //convert to cents for simplicity of later arithmetic
    int cents = round(c*100);

    //determine the appropriate numbers of coins to dispense
    int quarters = cents/25;
    int dimes = (cents%25)/10;
    int nickels = ((cents%25)%10)/5;
    int pennies = (((cents%25)%10)%5);

    //sum up total number of coins
    int coins = quarters+dimes+nickels+pennies;

    //print out the number of coins due to customer
    printf("%d\n", coins);

}
