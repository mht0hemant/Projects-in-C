//
//  main.c
//  factors_2.c
//
//  Created by Hemant Mahato on 10/15/19.
//  Copyright © 2019 Hemant Mahato. All rights reserved.
//

#include <stdio.h>


   



    int main(int argc, const char * argv[])
    {
         printf("***************************************************************    \n");
         printf("  This program will test weather the numbers you entered fall      \n");
         printf("in the range of 1 to 30000 and help you calculate it's factors.    \n");
         printf("***************************************************************    \n");
         printf("      You are supposed to enter one positive integer.              \n");
         printf("***************************************************************    \n");
         printf(" The program will then check all your numbers against the range    \n");
         printf("1 to 30000 and tell you if the entry is valid or not. If the number\n");
         printf("you entered is valid, the program will display what you entered.   \n");
         printf(" and If the numbers you entered is invalid, the program will       \n");
         printf("get you to enter the number again until you enter a valid number.  \n");
         printf("            or decide to use the exit code                          \n");
         printf("            The program will exit if you enter -1.                 \n");
         printf("***************************************************************    \n\n");
        
        int enteredNumber;
        int factor;
        
        printf("Please, enter a positive whole integer\n");
        printf("***************************************************************   \n");
        printf("Please, enter a single integer between 1 and 30000\n");
        printf("or -1 to quit\n");
        printf("For example, to enter value 459, simply enter --> 459\n");
        printf("--> ");
        scanf("%d", &enteredNumber);
        
       if (enteredNumber == -1)
       {
            printf("                 *--Program Terminating--*\n");
            printf("***************************************************************  \n\n");
            printf("\n");
            return 1;
        }
       else
       {
       while (enteredNumber <= 1 || enteredNumber > 30000 || enteredNumber >= 1 || enteredNumber <= 30000)
        
        {
            while (enteredNumber == -1)
            {
                 printf("                 *--Program Terminating--*\n");
                 printf("***************************************************************  \n\n");
                 printf("\n");
                 break;
            }
            
            while (enteredNumber <= 1 || enteredNumber > 30000)
            {
                 printf("%d is not a valid entry, please re-enter \n", enteredNumber );
                 printf("***************************************************************  \n\n");
                 printf("Please, enter a single integer between 1 and 30000\n");
                 printf("or -1 to quit\n");
                 printf("For example, to enter value 459, simply enter --> 459\n");
                 printf("--> ");
                 scanf("%d",&enteredNumber);
            }
            
            while (enteredNumber >= 1 && enteredNumber <= 30000 )
            {
                printf("You entered %d,\n", enteredNumber);
                printf("The factors of %d are:",enteredNumber);
                int factorCounter = 0;
                for(factor=1; factor < enteredNumber; factor++)
                {
                    
                    if (enteredNumber % factor == 0)
                    {
                         printf("%7d",factor);
                         factorCounter++;
                      
                         
                         int lowestFactor;
                         int highestfactor;
                         if (factorCounter == 2)
                        {
                            
                            highestfactor = enteredNumber / factor;
                            
                            if (factor != highestfactor)
                            {
                                printf(",");
                            }
                         }
                            if (factorCounter % 3 != 0)
                            {
                                printf(",");
                            }
                            else
                            {
                                printf("\n");
                                printf("                       ");
                            }
                    }
                }
                
                printf("\n***************************************************************  \n\n");
                printf("\nPlease, enter a single integer between 1 and 30000\n");
                printf("or -1 to quit\n");
                printf("For example, to enter value 459, simply enter --> 459\n");
                printf("--> ");
                scanf("%d",&enteredNumber);
                
            }
                
        }


     return 0;
    }
            
}

        



