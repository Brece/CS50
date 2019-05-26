// Helper functions for music

#include <cs50.h>
#include <string.h>

#include <math.h>
#include "helpers.h"



// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //convert number in fraction to integers
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    
    //convert numerator to number of eigths
    return ((8/denominator) * numerator);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //get octave from last char of note string
    int octave = note[strlen(note) - 1] - '0';
    
    
    //frequency for all notes in one octave; n is distance of the key to key A ..positive when above and negative when below
    double freq;
    
    if (note[0] == 'A')
    {
        freq = 440;
    }
    
    else if (note[0] == 'B')
    {
        freq = 440.0 * (pow(2, (2.0/12.0)));
    }
    
    else if (note[0] == 'C')
    {
        freq = 440.0 * (pow(2, (-9.0/12.0)));
    }

    else if (note[0] == 'D')
    {
        freq = 440.0 * (pow(2, (-7.0/12.0)));
    }
 
     else if (note[0] == 'E')
    {
        freq = 440.0 * (pow(2, (-5.0/12.0)));
    }

    else if (note[0] == 'F')
    {
        freq = 440.0 * (pow(2, (-4.0/12.0)));
    }    
    
    else if (note[0] == 'G')
    {
        freq = 440.0 * (pow(2, (-2.0/12.0)));
    }
    
    
    //loop to shift octave
    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }
    
    //flat or sharp notes
    if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0/12.0)));
    }
    else if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0/12.0)));
    }
    
    int result = round(freq);
    return result;
    
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
        return true;
    else
        return false;
}
