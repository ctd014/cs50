// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths.
int duration(string fraction)
{
// Splice the fraction into its numerator and denominator.
    char x[2];
    char y[2];
    x[0] = fraction[0];
    y[0] = fraction[2];

// Convert the numerator and denominator into integer data types.
    int x_int = atoi(x);
    int y_int = atoi(y);

// Determine the integral number of eighths that the fraction is equivalent to.
    return (x_int * 8) / y_int;
}

// Calculate frequency (in Hz) of a note.
// The argument for this function will be either two or three characters.
// If three characters, then this means the note is a black key (for example, C#5).
// If two characters, then this means the note is a white key (for example, B4).
int frequency(string note)
{
// Determine the octave of the note.
// This is done by retrieving the last character of the inputted string and converting it to an integer.
    int len = strlen(note);
    char oct[2];
    oct[0] = note[len - 1];
    int oct_int = atoi(oct);

// In the determined octave, determine how many semitones away A is from the A key in octave 4.
    int octave_semitones = 12 * (oct_int - 4);

// Ignoring sharps and flats for now, determine how many semitones away the note is from A in its octave.
    int note_semitones = 0;

    if (note[0] == 'A')
    {
        note_semitones = 0.0;
    }
    else if (note[0] == 'B')
    {
        note_semitones = 2.0;
    }
    else if (note[0] == 'C')
    {
        note_semitones = -9.0;
    }
    else if (note[0] == 'D')
    {
        note_semitones = -7.0;
    }
    else if (note[0] == 'E')
    {
        note_semitones = -5.0;
    }
    else if (note[0] == 'F')
    {
        note_semitones = -4.0;
    }
    else if (note[0] == 'G')
    {
        note_semitones = -2.0;
    }


// If sharp, add one semitone.
    if (note[1] == '#')
    {
        note_semitones += 1;
    }

// If flat, subtract one semitone.
    if (note[1] == 'b')
    {
        note_semitones -= 1;
    }

// Calculate total number of semitones away from A4.
    int n = octave_semitones + note_semitones;

// Determine frequency (in Hz) of the note.
    double freq = round(pow(2.0, n / 12.0) * 440);

    return freq;
}

// Determines whether a string represents a rest.
// If a user simply presses enter (signifying a rest), the get_string function returns "".
bool is_rest(string s)
{
    string rest = "";

    if (strcmp(s, rest) == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}
