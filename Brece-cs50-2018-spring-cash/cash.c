#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    int coins = 0;
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;

    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);

    //convert float to int
    int cash = (int)(100.0 *n);

    while (cash >= 25)
    {
        cash -= 25;
        coins += 1;
        quarter += 1;
    }

    while (cash >= 10)
    {
        cash -= 10;
        coins += 1;
        dime += 1;
    }
    
    while (cash >= 5)
    {
        cash -= 5;
        coins += 1;
        nickel += 1;
    }

    while (cash >= 1)
    {
        cash -= 1;
        coins += 1;
        penny += 1;
        
    }
    
    
    printf("Quarter: %i ; dime: %i ; nickel: %i ; penny: %i\n", quarter, dime, nickel, penny);
    printf("Coins: %i\n", coins);
}