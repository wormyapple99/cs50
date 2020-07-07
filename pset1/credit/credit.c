#include <stdio.h>
#include <cs50.h>

//declare functions
long get_card(string prompt);
bool checkSum(long n);

int main(void)
{
    //boudary that the card numbers need to satisfy

    //number of digits - 2
    long amex = 10000000000000; //13
    long master = 100000000000000; //14
    //number of digits - 1
    long visa1 = 1000000000000;    //12
    long visa2 = 1000000000000000; //15 

    //AMEX
    //15 digits
    //start with 34, 37

    //MASTERCARD
    // 16 digits
    //start with 51, 52, 53, 54, 55

    //VISA
    // 13 digits, 16 digits
    //start with 4

    long amex_1 = 34*amex;
    long amex_2 = 35*amex;
    long amex_3 = 37*amex;
    long amex_4 = 38*amex;

    long master_1 = 51*master;
    long master_2 = 56*master;

    long visa_1 = 4*visa1;
    long visa_2 = 5*visa1;
    long visa_3 = 4*visa2;
    long visa_4 = 5*visa2;

    //prompt user for credit card number
    long n = get_card("Enter Credit Card Number: \n");

    //check if number satisfies the Luhn algorithm, using function checkSum
    if (checkSum(n))
    {
        //check if number satisfy the type
        if ( (n>=amex_1 & n < amex_2) || (n>=amex_3 & n < amex_4))
        {
            printf("AMEX\n");
        }
        else if ( n >= master_1 & n < master_2)
        {
            printf("MASTERCARD\n");
        }
        else if ( (n>= visa_1 & n < visa_2) || (n >= visa_3 & n < visa_4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }


}

//funtion to prompt for card number
long get_card(string prompt)
{
    long n;
    long limit = 1000000000; //11
    do
    {
        n = get_long("%s", prompt);
    }
    //checks that the number of numbers are at least 10^13
    while (n < limit);
    return n;
}

//function to check that number satisfies Luhn's algorithm
//returns true if satisfy, else false
bool checkSum(long n)
{
    //initiate values
    int final_c = 0;
    int d = 0;
    
    int length = 17; //there is at most 16 digits in card number
    
    long f = 10;
    int last_digit = n % f;
    
    for(int i = 1; i < length; i ++)
    {
        
       //every other digit*2
        long c1 = n % f;//last digit
        long c2 = n % (f*10); // last 2 digits
        long c3 = c2 - c1; //second last digit*10
        long c4 = c3/f; //second last digit
        int c5 = c4*2; //second last digit*2
        
        if (c5>=10)
        {
            int final_c1 = c5 % 10; //the second digit
            int final_c2 = c5 - final_c1;// the first digit*10
            int final_c3 = final_c2/10;  //the first digit
            final_c = final_c + final_c1 + final_c3; //add all digits
        }
        else 
        {
            final_c = final_c + c5; //add all digits
        }
       
       //the other digits that are not multiplied
        long d1 = n % (f*10); //last 2 digits
        long d2 = n % (f*100); //last 3 digits
        long d3 = d2 - d1; //third last digit*100
        int d4 = d3/(f*10); //third last digit
        
        d = d + d4; //add the digit
       
        f *= 100; //move 2 places up 
       
    }

    //add everything tgt
    int sum = final_c + d + last_digit;
    
    //if the last digit of the sum is zero
    if ( sum % 10 == 0)
    {
        return true;  //satisfies Luhn's algorithm 
    }
    else
    {
        return false;
    }
}