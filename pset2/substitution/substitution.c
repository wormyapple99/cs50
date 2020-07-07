//this program takes in a 26 character key as command line argument
//prompt user to enter a text, and it will return a cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//string get_cipher(string plain, string key);

int main(int argc, string argv[])
{
    //there are 2 arguments, and key has 26
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        for (int p = 0; p < 26; p++)
        {
            char checkDup[26];
            checkDup[p] = argv[1][p];

            //check for duplicate
            for (int q = 0; q < p; q++)
            {
                if (argv[1][p] == checkDup[q]) //exact duplicate
                {
                    printf("Key must contain 26 characters.");
                    return 1;
                }
                else if ((int)argv[1][p] == (int)checkDup[q] + 32) //same letter, lowercase
                {
                    printf("Key must contain 26 characters.");
                    return 1;
                }
                else if ((int)argv[1][p] == (int)checkDup[q] - 32)//same letter, uppercase
                {
                    printf("Key must contain 26 characters.");
                    return 1;
                }
            }

            //check that key are valid characters
            if (argv[1][p] < 'A' ||argv[1][p]> 'z')
            {
                printf("Key must contain 26 characters.");
                return 1;
            }
            else if (argv[1][p] > 'Z' && argv[1][p] < 'a')
            {
                printf("Key must contain 26 characters.");
                return 1;
            }
        }
        //if the key passes checking, continue to main code
        string plain = get_string("plaintext: ");
        string key = argv[1];

        char upperKey[26]; //initiate array
        char lowerKey[26] ;

        strcpy(upperKey, key); //copy string in key to upperKey
        strcpy(lowerKey, key); //if use lowerKey=key, it's just copying the reference, thus when changing key to all lowercase, the characters stored in upperKey will change to lower case as well


        for (int i = 0; i < 26; i ++)
        {
            upperKey[i] = toupper(upperKey[i]); //change key to upper
        }

        for (int i = 0; i < 26; i ++)
        {
            lowerKey[i] = tolower(lowerKey[i]); //change key to lower
        }


        string upperABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //[A:Z]
        string lowerABC = "abcdefghijklmnopqrstuvwxyz"; //[a:z]

        char cipher[strlen(plain)]; //initialize the cipher


        for (int j = 0, n = strlen(plain); j < n; j++)
        {
            for (int k = 0; k < 26; k ++)
            {
                if (plain[j] == upperABC[k]) //compare to normal ABC
                {
                    cipher[j] = upperKey[k]; //if match, assign to the key of the same index
                }
                else if (plain[j] == lowerABC[k])
                {
                    cipher[j] = lowerKey[k];
                }
                else if (plain[j] < 'a' && plain[j] > 'Z' )
                {
                    cipher[j] = plain[j];
                }
                else if(plain[j] < 'A' || plain[j] > 'z')
                {
                    cipher[j] = plain[j];
                }
            }
        }

        string cipherText = cipher;

        printf("ciphertext: %s\n", cipherText);
        return 0;
    }


    else if (argc != 2)//other invalid cases
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    else if (strlen(argv[1]) != 26) //2nd argument is not 26 charcters long
    {
        printf("Key must contain 26 characters.");
        return 1;
    }





}


