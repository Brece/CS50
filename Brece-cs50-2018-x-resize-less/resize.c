#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    //check usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    //convert n into an integer
    int n = atoi(argv[1]);

    //only 0 < n <= 100
    if (n <= 0 || n > 100)
    {
        fprintf(stderr, "n has to be an integer, positive and less or equal to 100\n");
        return 2;
    }

    //file names
    char *infile = argv[2];
    char *outfile = argv[3];

    //open infile
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    //open outfile
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(outptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    //read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    //read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //ensure infile is a 24-bit uncompressed BMP 4.0
    if ( bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }


    //track paddings for infile and outfile !!!
    //padding for scanlines of infile
    int paddingIn = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //padding for outfile, factored by n
    int paddingOut = (4 - (n * bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int inWidth = bi.biWidth;
    int inHeight = bi.biHeight;
    bi.biWidth *= n;
    bi.biHeight *= n;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + paddingOut) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    //write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    //write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    //allocate memory for scaled outfile
    //char *output = malloc(bf.bfSize * sizeof(char));


    //iterate over infile's scanlines
    for (int i = 0, Height = abs(inHeight); i < Height; i++)
    {

        //copies line n-times
        for (int a = 0; a < n; a++)
        {
            //iterate over pixels in scanline
            for (int j = 0; j < inWidth; j++)
            {
                RGBTRIPLE triple;

                //read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                 //write RGB triple to outfile n-times
                for (int q = 0; q < n; q++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            //change offset to the start of the line if it is not the last iteration
            if (a != n-1)
            {
                fseek(inptr, (inWidth * sizeof(RGBTRIPLE))* -1, SEEK_CUR);
            }

            //add it back
            for (int k = 0; k < paddingOut; k++)
            {
                fputc(0x00, outptr);
            }
        }
        //skip over padding in infile, if any
        fseek(inptr, paddingIn, SEEK_CUR);


    }

    fclose(inptr);
    fclose(outptr);
    return 0;

}