#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;

    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int pennie = 0;



    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);

    //convert float to int
    int owed = (int)(100 * n);

    int payed = 0;
    
    while (payed != owed)
    {
        
        if (owed % 25 > 0)
        {
            quarter += owed/25;
            payed += quarter*25;
        }

        else if (owed % 10 > 0)
        {
            dime += owed/10;
            payed += dime*10;
        }

        else if (owed % 5 > 0)
        {
            nickel += owed/5;
            payed += nickel*5;
        }


        else if (owed % 1 > 0)
        {
            pennie += owed/1;
            payed = pennie % 1;
        }
    }

    
    int coins = quarter + dime + nickel + pennie;
    printf("Quarter: %i ; dime: %i ; nickel: %i ; pennie: %i\n", quarter, dime, nickel, pennie);
    printf("Coins: %i\n", coins);


}