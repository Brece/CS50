#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int row;
    int column;


    do
    {
        n = get_int("Height: ");
    }
    //repeat loop while n is invalid
    while (n < 0 || n > 23);

    //variable to limit the number of spaces in row,
    //increase by one after a loop for each row
    //is also used as an upper limit for the amount of hashes for the left pyramid
    int i = 1;

    //loop for each row, <n because it starts at 0
    for (row = 0; row < n; row++)
    {

        //loop for each position (column) in the current row
        //<= n because it starts at 0 and the number of column = n+1
        for (column = 0; column <= n; column++)
        {
            //print row specific number of spaces
            //the first row always has two # and i=1
            //(column < n-i) means that there are max n-2 spaces
            while (column < n-i)
            {
                printf("%c", ' ');
                column++;
            }
            
            //fill the rest of the row with #
            printf("%c", '#');
        }
        

        //print two spaces    
        printf("%s", "  ");
            
        
        //print the amount of remaining hashes
        for (int hash = 0; hash <= i; hash++)
            {
                printf("%c", '#');
            }
        

        //print new line for the next row
        printf("\n");

        //reduce the amount of spaces by one for the next row AND increase the amount of hashes for the left pyramid
        i++;
    }

}

