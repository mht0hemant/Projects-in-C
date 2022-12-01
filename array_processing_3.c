//
//  array_processing_2.c
//
//
//  Created by Hemant Mahato on 10/22/19.
//  Copyright © 2019 Hemant Mahato. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ELEMENTS 50
#define HIGH_LIMIT 50
#define LOW_LIMIT 25

int main(int argc, const char * argv[])
{
     
    printf("The program will start with a random number\n");
    printf("and print random numbers in the given range. \n ");
    printf("It will then give you options to choose from\n");
    printf("to perform calculations on the set of numbers\n");
    printf("**********************************************\n");
    printf("   All you have to do is enter the ELEMENTS,\n");
    printf("      and set HIGH LIMIT and LOW LIMIT\n");
    printf("Only positive integers like 5 or 6 for ELEMENTS\n");
    printf("  whereas any integers like -50 or 999 can be \n");
    printf("   entered for the high and low limits\n");
    printf("**********************************************\n");
    printf(" Once the numbers are generated, just choose\n");
    printf("    from the options what you want to do.\n");
    printf(" \n");
    
    int counter;
    srand((int)time(NULL));
    int units[ELEMENTS];
  
   for( counter = 0; counter < ELEMENTS; counter++)
    {
     
         units[counter] = rand() % (HIGH_LIMIT -LOW_LIMIT + 1) + LOW_LIMIT ;
         printf("element %2d  is:   %4d\n",counter, units[counter]);
        
    }
   
    printf("\n");
    printf("**********************************************\n");
    printf("Enter the option next to process you wish to perform\n");
    printf("1 - find maximun value\n");
    printf("2 - find minimun value\n");
    printf("3 - find average value\n");
    printf("4 - find numbers above selected value\n");
    printf("5 - exit program\n");
    
    
    
    int enteredNumber;
    int sum = 0;
    float average;
    int index_1 = 0;
    int index_2 = 0;
    
    
    int min_value = units[0];
    int max_value = units[0];
   
     printf("-->  ");
     scanf("%d", &enteredNumber);
     printf("\n");
    
     while (enteredNumber <= 5 && enteredNumber > 0)
     {
            switch (enteredNumber)
            {
                case 1:
                    for (counter = 0; counter < ELEMENTS; counter++)
                    {
                        if (units[counter] > max_value )
                        {
                            max_value = units[counter];
                            index_1 = counter;
                        }
                    }
                      
                    printf("Maximum Value: %4d\n", max_value);
                    printf("Maximum Index: %4d\n", index_1);
                    printf("\n");

                    break;
            
                case 2:
                    for (counter = 0; counter < ELEMENTS; counter++)
                    {
                        if (units[counter] < min_value )
                        {
                            min_value = units[counter];
                            index_2 = counter;
                        }
                    }
               
                    printf("Minimum Value: %4d\n", min_value);
                    printf("Minimum Index: %4d\n", index_2);
                    printf("\n");

                    break;
            
                case 3:
                    for (counter = 0; counter < ELEMENTS; counter++)
                    {
                        sum += units[counter];
                    }
                        average = sum / (float)ELEMENTS;
                        printf("Average Value: %4.2f\n", average);
                   
                    break;

                case 4:
                     
                      
                      printf("Lower Limit of Values: %d\n", LOW_LIMIT);
                      printf("Upper Limit of Values: %d\n", HIGH_LIMIT);
                      printf("Content of array of %d elements:\n", ELEMENTS);
                      srand((int)time(NULL));
                      int units[ELEMENTS];
                    
                     for( counter = 0; counter < ELEMENTS; counter++)
                      {
                       
                           units[counter] = rand() % (HIGH_LIMIT -LOW_LIMIT + 1) + LOW_LIMIT ;
                           printf("  element %2d:%4d\n",counter, units[counter]);
                          
                      }
                      int index = 0;
                      int holderArray[ELEMENTS] = {-1};
                      /*for (index=0; index<ELEMENTS; index++)
                      {
                          holderArray[index] = -1;
                      }*/
                      int thresholdNumber;
                      int averageExample = (HIGH_LIMIT+LOW_LIMIT)/ 2;
                      printf("\n");
                      printf("Please enter a positive integer\n");
                      printf("between the values of %d and %d\n", LOW_LIMIT, HIGH_LIMIT);
                      printf("for the threshold value to filter by.\n");
                      printf("\n");
                      printf("For example, if you want all value\n");
                      printf("greater than %d, enter --> %d \n",averageExample, averageExample );
                      printf(" \n");
                      printf("--> ");
                      scanf("%d", &thresholdNumber);
                      printf("\n");
                      printf("You entered a threshold of %2d\n",thresholdNumber);
                      

                      if (thresholdNumber < HIGH_LIMIT && thresholdNumber > LOW_LIMIT )
                      {
                          printf("Array contents\n");
                          printf("  #  units  holding\n");

                          for( counter = 0; counter < ELEMENTS; counter++)
                          {
                              if (units[counter] >= thresholdNumber)
                              {
                                  holderArray[index] = units[counter];
                                  index++;
                              }
                          }
                              counter = 0;
                          for( index = 0; index < ELEMENTS; index++)
                          {
                              printf("%3d %4d",counter, units[counter]);
                              if( holderArray[index] > 0 )
                              {
                                  printf("%9d\n",holderArray[index]);
                              }
                              else
                              {
                                  printf("      ---\n");
                              }
                              counter++;
                          }
                         
                      }
                      
                      else
                      {
                          printf("which is not a valid value between %d and %d\n", LOW_LIMIT, HIGH_LIMIT);
                      }
                    break;
                case 5:
                    printf("***********Exiting Program************\n");
                    exit (1);
                    
               
            }
       
   
          printf("**********************************************\n");
          printf("Enter the option next to process you wish to perform\n");
          printf("1 - find maximun value\n");
          printf("2 - find minimun value\n");
          printf("3 - find average value\n");
          printf("4 - find numbers above selected value\n");
          printf("5 - exit program\n");
          printf("-->  ");
          scanf("%d", &enteredNumber);
          printf("\n");
     }
       
    
    
    return 0;
}

   
   
    


