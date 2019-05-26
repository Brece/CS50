#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main (int argc, char *argv[])
{
    //check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover image\n");
        return 1;
    }

    //store file in pointer variable
    char *infile = argv[1];

    //open file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return 2;
    }

    //declare buffer
    typedef uint8_t BYTE;
    BYTE buffer[512];

    //store filename
    char filename[8];

    //
    bool existingfile = false;

    //jpeg counter
    int counter = 0;

    //declare image pointer globally to be used locally in while loop
    FILE *img;

    //while the programm can read chunks of 512 bytes; because the end of file is less than 512 bytes long
    while (fread(&buffer, sizeof(buffer), 1, inptr) == 1)
    {

        //check for jpeg file format
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //boolean is false until the first jpeg is found
            if (existingfile == false)
            {
                existingfile = true;
            }

            //close current file if new jpeg header is found
            else
            {
                fclose(img);
            }

            //creates new jpeg file and opens it to be written; increase counter by one for filename
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            fwrite(&buffer, sizeof(buffer), 1, img);
            counter++;
        }

        //if the buffer doesn't match a jpeg header, it will be written to the current image file if one already exists,
        //otherwise it will be skipped
        else
        {
            if(existingfile == true)
            {
                fwrite(&buffer, sizeof(buffer), 1, img);
            }

        }
    }

    //close all open files
    fclose(img);
    fclose(inptr);

    return 0;
}

