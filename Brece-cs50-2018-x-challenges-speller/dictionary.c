// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include "dictionary.h"

//define node structure
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[26];
//word counter for SIZE
int word_counter = 0;

//boolean for SIZE
bool loaded = false;

//sdbm hash function
int c;
static unsigned long hash (char *str)
{
    unsigned long hash = 0;

    while (c == *str++)
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    } 
    return hash;
}


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    if(loaded)
    {

        //declare pointer to string array that stores the lower case version of the words to check in the dictionary
        int orgn_len = strlen(word);
        char *lo_word = malloc( sizeof(char) * (orgn_len+1) );

        //copy lower case version in lo_word
        for(int i = 0; i < orgn_len; i++)
        {
                lo_word[i] = tolower(word[i]);
        }

        lo_word[orgn_len] = '\0';

        //get index where the word is being stored
        int index = hash(lo_word);

        //create node cursor to compare it to the ones on the linked lists

        //node *cursor = malloc(sizeof(node));

        //traversing linked lists where the word whould be found in the hash table
        node *cursor = hashtable[index];
        while(cursor != NULL)
        {
            //word exists if the string that the cursor is pointing to is equal to lo_word
            if(strcmp(cursor->word, lo_word) == 0)
            {
                //word is in dictionary
                return true;
            }
            //point to the next node
            cursor = cursor->next;
        }

        free(lo_word);
        //free(cursor);
        return false;
    }

    else
    {
        return false;
    }
}





// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open dictionary to read
    FILE *file = fopen(dictionary, "r");

    //if the dictionary is not accessible or out of memory
    if(file == NULL)
    {
        return false;
    }

    //define string to copy the word to
    char word[LENGTH +1] = {'\0'};

    //scan dictionary word by word
    //malloc a node * for each new word, unload if NULL-pointer
    //malloc returns NULL when no memory is available
    while(fscanf(file, "%s", word) != EOF)
    {
        //increase word counter for SIZE
        word_counter++;

        node *new_node = malloc(sizeof(node));


        //copy string stored in word to the node value 'word'
        strcpy(new_node->word, word);

        //call the hashfunction and get the hash code where the word should be stored in the hash table
        int index = hash(word);

        //insert if hashtable is empty at index
        if(hashtable[index] == NULL)
        {
            hashtable[index] = new_node;
            new_node->next = NULL;
        }

        //append node to the hashtable in the right index and make it the new head of the linked list
        else
        {
            new_node->next = hashtable[index];
            hashtable[index] = new_node;
        }


    }
    loaded = true;
    fclose(file);
    return true;
}





// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;
}





// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if(loaded)
    {

        //unload all indexes of the hash table
        for(int i = 0; i < sizeof(hashtable); i++)
        {
            //create pointer to the head of the linked lists in the hashtable
            node *cursor = hashtable[i];

            //traverse the linked lists with help of a temporary pointer,
            //two pointers are needed because cursor points to the next node, if the temp (current) pointer points to the last node then cursor points to NULL
            while(cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);
            }

        }
        loaded = false;
        return true;
    }

    else
    {
        return false;
    }
}
