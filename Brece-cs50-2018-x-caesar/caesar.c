#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//#include <strlen.h>


int main(int argc, string argv[])
{
    //key from command line argument
    if (argc != 2)
    {
        printf("Error: exactly 1 argument!\n");
        return 1;
    }

    //convert string to int
    int key = atoi(argv[1]);

    //key must not be negative, return to main
    if (key < 0)
    {
        printf("Error: key must not be negative! max 1 argument!\n");
        return 1;
    }


    //get user input
    string s = get_string("plaintext: ");

    //string text = "";

    printf("ciphertext: ");
    
    //for each character in plaintext
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if alphabetic
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                printf("%c", (((s[i] - 97) + key) % 26) + 97);
            }
            else
            {
                printf("%c", (((s[i] - 65) + key) % 26) + 65);
            }
        }
        //not alphabetic
        else
        {
            printf("%c", (s[i]));
        }
        

    }
    printf("\n");
    return 0;
    //printf("ciphertext: %i\n", text);
}

