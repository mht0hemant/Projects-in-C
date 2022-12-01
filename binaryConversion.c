//
// binaryConversion.c
//  Binary_Conversion
//
//Authors:
//  Hemant Mahato
//  Alex Richard
//  9/28/19.
//  Copyright © 2019 Hemant Mahato. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(int argc, const char * argv[])
{
     /*
           *Introduction Screen
     */
    
     printf("***************************************************************  \n");
     printf("This program will only take whole numbers in the range of        \n");
     printf("   0 to 255. ## A whole number is a decimal number ##            \n");
     printf(" Once the program knows that the entered number is valid,        \n");
     printf("  it will take the decimal number and convert it into            \n");
     printf("                    binary number.                               \n");
     printf("***************************************************************  \n");
     printf("         You are supposed to enter one whole number.             \n");
     printf("***************************************************************  \n");
     printf("The program will then check all your numbers against the range   \n");
     printf("  0 to 255. If the number entered is valid the program will      \n");
     printf("  automatically convert the decimal number to binary number      \n");
     printf("If entered numbers is less than and equal to -1 or more than 255,\n");
     printf("the program is going to ask you to enter the number again until  \n");
     printf("               a valid entry is received.                        \n");
     printf("  You can quit that process by entering -1, which will then      \n");
     printf("                 terminate the program.                          \n");
     printf("***************************************************************  \n\n");
     
     /*
         *Declaring Variables
     */
     int base10_number;
     int binary_number[7];
     int counter;
     
     /*
           *User Prompt
     */
     
     printf("                     Enter any whole number.                      \n");
     printf("  Example of expected kind of entry : 10 or -2 or 111 or 179      \n");
     printf("The valid range is 0 to 255 ; whereas any whole numbers can be    \n");
     printf("                           entered.                               \n");
     printf("\n\n");
     printf("--> ");
     scanf("%d", &base10_number);
     
    
     /*
           * Data Validation
           *Loop Start
     */
     while (base10_number <= -1 || base10_number >= 256)
     {
          /*
                *User Prompt for Loop
          */
         
          printf("***************************************************************   \n");
          printf("                    %d is not a valid entry  \n", base10_number );
          printf("***************************************************************  \n\n");
          printf("                     Enter any whole number.                      \n");
          printf("  Example of expected kind of entry : 10 or -2 or 111 or 179      \n");
          printf("The valid range is 0 to 255 ; whereas any whole numbers can be    \n");
          printf("                             entered                              \n");
          printf("\"You have entered a loop\":: either enter number from valid range\n");
          printf("         or enter -1 to exit and terminate the program\n");
          printf("\n\n");
          printf("--> ");
          scanf("%d", &base10_number);
          
          /*
               *Loop Exit
          */
         
          if (base10_number == -1)
          {
               printf("\n");
               printf("               You entered the exit code \"-1\"\n");
               printf("           You have successfully exited the loop\n");
               printf("         Please reload the program to start again.\n");
               printf("\n");
               printf("                 *--Program Terminating--*\n");
               printf("\n");
               break;
          }
          
         
     }
     /*
          * Decimal to Binary Conversion
     */
    
     while (base10_number > -1 && base10_number < 256)
     {
          printf("***************************************************************  \n");
          printf("\n");
          printf("The base ten value %d converted to binary is:  ", base10_number);
          
          for (counter = 0; base10_number > 0; counter++)
          {
               binary_number[counter] = base10_number % 2;
               base10_number = base10_number / 2;
          }
          
          /*
                *Printing the Binary Number
          */
         
          for (counter = counter-1; counter >=0; counter--)
          {
               printf("%d ", binary_number[counter]);
          }
         
          printf("\n");
          printf("\n*************************************************************** \n");
          printf("\n");
          printf("                    *--Program Terminating--*\n");
          printf("\n");
          break;
    }
     
    return 0;
}



