#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //only execute with ONE command line argument
    if (argc != 2)
    {
        printf("ERROR: exactly 1 argument!\n");
        return 1;
    }

    //check if key word consist on letters ONLY, print ERROR and return 1
    string key = argv[1];

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("ERROR: argument must consist on LETTERS only!\n");
            return 1;
        }
    }

    //user input
    string s = get_string("paintext: ");

    printf("ciphertext: ");

    //m increases the index j by 1 IF the char in plaintext is alpabetical
    int m = 0;
    
    //for each character in plaintext
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //rotate index position in string key 
        int j = m % strlen(key);
        
        //transform letter in key to a number between 0 and 25
        int k = (tolower(key[j]) - 97);
        
        //if alphabetic
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                printf("%c", (((s[i] - 97)  + k) % 26) + 97);
            }
            else
            {
                printf("%c", (((s[i] - 65) + k) % 26) + 65);
            }
            //next letter in key --> index j increases due to modulos by 1
            m++;
        }
        //not alphabetic
        else
        {
            printf("%c", (s[i]));
            
        }
    }





    printf("\n");
    return 0;

}