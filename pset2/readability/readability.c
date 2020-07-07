// this program takes in text and determines its reading level
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
//prompt user for text
//count number of letters, words, sentences
//output:"Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
//If the resulting index number is 16 or higher,
///output "Grade 16+" instead of giving the exact index number.
//If the index number is less than 1, your program should output "Before Grade 1".

int main(void)
{
    string s = get_string("Enter Text to Test: \n");
    //string s = "One fish. Two fish. Red fish. Blue fish.";
    //count letters, words, sentences
    int letter = 0;
    int word = 1;
    int sentence = 0;

    for (int i = 0, n = strlen(s); i < n; i ++)
    {
        if (s[i]>= 'a' && s[i] <= 'z' )
        {
            letter += 1;
        }
        else if (s[i]>= 'A' && s[i] <= 'Z' )
        {
            letter += 1;
        }
        else if (s[i] == ' ')
        {
            word += 1;
        }
        else if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentence += 1;
        }

    }

    float L = (float)letter/word * 100;
    float S = (float)sentence/word * 100;

    float I = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
   


}
