# include <stdio.h>
#include <cs50.h>

int get_height(string prompt);

int main(void)
{
   int h = get_height("Height: ");
   int w= h;

   for (int j = 1; j < h+1; j++)
   {
       //print spaces on LHS
       for (int i = 0; i < h-j; i++)
       {
           printf(" ");
       }
       //print # on LHS
       for (int k = 0; k < j; k++)
       {
           printf("#");
       }
       
       printf("  ");
       
       //print # on RHS
        for (int p = 0; p < j; p++)
       {
           printf("#");
       }
       //print spaces on RHS (technically no need this)
       //for (int q = 0; q < h-j; q++)
       //{
           //printf(" ");
       //}

       printf("\n");

   }

}


int get_height(string prompt) //takes in a sting, (prompt), returns integer
{
    int n; //define n here, so can use n throught this function
    do
    {
         n = get_int("%s\n", prompt);
    }
    while (n < 1 || n > 8 );
    return n ;
}