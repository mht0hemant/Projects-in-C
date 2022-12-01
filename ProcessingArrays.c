//
//  ProcressingArrays.c
//  Assignment-3:: ProcessingArrays
//
//  Created by Hemant Mahato on 11/20/19.
//  Copyright © 2019 Hemant Mahato. All rights reserved.
//

#include <stdio.h>
#define SIZE 100

//*******************************************************************
                    /*// FUNCTION PROTOTYPES \\*/
//*******************************************************************

void filter_Below_Threshold(int thres, int src[], int filtered[]);
void filter_Above_Threshold(int thres, int src[], int filtered[]);
void print3Arrays(int arr1[], int arr2[], int arr3[]);

//*******************************************************************
                            /*// MAIN \\*/
//*******************************************************************
int main ( void )
{
    printf("*********************************************************************    \n");
    printf("* ***************************************************************** *    \n");
    printf("* *                                                               * *    \n");
    printf("* *  This program starts with you choosing from one of the two    * *    \n");
    printf("* *  sets of numbers or arrays that are already initialized in    * *    \n");
    printf("* *   the program. The program will also ask you to enter two     * *    \n");
    printf("* *     threshold values. One upper and one lower threshold.      * *    \n");
    printf("* *  The lower threshold will filter the numbers in the array     * *    \n");
    printf("* *  that are greater than itself, whereas; the upper threshold   * *    \n");
    printf("* *          will filter numbers smaller than itself.             * *    \n");
    printf("* *  Finally the program will print out 'in columns' the numbers  * *    \n");
    printf("* *                   that were filtered.                         * *    \n");
    printf("* *                                                               * *    \n");
    printf("* *---------------------------------------------------------------* *    \n");
    printf("* *                                                               * *    \n");
    printf("* *  All you have to do is choose the array and enter thresholds  * *    \n");
    printf("* *                                                               * *    \n");
    printf("* *---------------------------------------------------------------* *    \n");
    printf("* *                                                               * *    \n");
    printf("* * After you do what you are asked to do, the program will then  * *    \n");
    printf("* * select the required array and then apply the threshold values * *    \n");
    printf("* *             to the arrays through programs,                   * *    \n");
    printf("* *  so that they are filtered accordingly. Finally, the program  * *    \n");
    printf("* * will print out in column, the row index values, the numbers   * *    \n");
    printf("* * above lower threshold, the numbers below higher threshold and * *    \n");
    printf("* *            the numbers in between the thresholds              * *    \n");
    printf("* *                                                               * *   \n");
    printf("* ***************************************************************** *   \n");
    printf("*********************************************************************    \n\n");

    
    int counter = 0;
    int inUseArray[SIZE];
    for (counter = 0; counter < SIZE; counter++)
    {
        inUseArray[counter] = -1;
    }
    int  lowNumbers[] = { 73,80,96,92,91,64,24,14,42,47,94,88,93,48,35,28,49,64,81, 5,47,
                          22,16,57,56,10,81,91,5 ,19,90,79,6 ,31,55,44,81, 3,75,80,93,69,
                          86,74,72,32,66,16,36,78,63,99,45,14,72,48,89, 3,83,57,43,96,33,
                          20,75,95,64,84,71,70,74,73,43,82,61,77,55,10, 6, 2,94,50,99,10,
                          55,34,39,12,78,7,73,35,32,13,54,45,0,74,18,40};
                          
    int highNumbers[] = {  90,129, 91, 62,144,138, 82,142,138, 86,148,116,130, 57,120, 62,
                           76, 75, 79,140, 73, 94,139, 81,122,113,100,121, 62, 86, 85,107,
                          129,119, 79, 84,104,143, 87,111,107, 85,141,143, 62, 92, 64,106,
                          148,147,143, 69,125,125,109, 86,148,137, 66, 61,133, 80, 64, 97,
                           84,123, 57, 94,116,115, 81,138,104, 79, 69,102,118, 64, 61, 99,
                           56, 69,135, 66, 61, 64,108,110,110, 91, 84,108,133,150, 68,109,
                          139, 84, 52, 63 };
    
    int aboveArray[SIZE];
    int index = 0;
    for (index = 0; index < SIZE; index++)
    {
        aboveArray[index] = -1;
    }
    int belowArray[SIZE];
    for (index= 0; index < SIZE; index++)
    {
        belowArray[index] = -1;
    }
    int betweenArray[SIZE];
    for (index = 0; index < SIZE; index++)
    {
        betweenArray[index] = -1;
    }
    
    char arrayOptions;
    printf("  There are two sets of numbers or arrays to choose from.           \n");
    printf("One of them is LOW-VALUE ranging from 1 to 99 and the other         \n");
    printf("one is HIGH-VALUE numbers that consists numbers in range of         \n");
    printf("                        52 to 150.                                  \n");
    printf("----OPTIONS::----------------------------------------------------   \n");
    printf("'a' = LOW-VALUE numbers (1 - 99)                                    \n");
    printf("'b' = HIGH-VALUE numbers (52 - 150)                                 \n");
    printf("                                                                    \n");
    printf("Enter 'a' or 'b' to choose want array you want to use.              \n");
    printf("If you want to use LOW-VALUE number. Enter;  --> a                  \n");
    printf("If you want to use HIGH-VALUE number. Enter; --> b                  \n");
    printf("                                                                    \n");
    printf("--> ");
    scanf("%s", &arrayOptions);
    printf("                                                                    \n");
    printf("****************************************************************    \n");
    printf("\n");
    
    int lowerThreshold = '#';
    int upperThreshold = '#';
    printf("Enter the THRESHOLD values below in two seperate prompts.           \n");
    printf("The lower threshold will filter the numbers in the array            \n");
    printf("that are greater than itself, whereas; the upper threshold          \n");
    printf("        will filter numbers smaller than itself.                    \n");
    printf("{For the program to run as expected, try to enter upper             \n");
    printf("   threshold value that is greater than the lower                   \n");
    printf("             threshold value you enter.                             \n");
    printf("This will print out the numbers in between thresholds.}             \n");
    printf("                                                                    \n");
    printf("****************************************************************    \n");
    printf("                                                                    \n");
    
    switch(arrayOptions)
    {
        case 'a':
            for (counter = 0; counter< SIZE ; counter++)
            {
                 inUseArray[counter] = lowNumbers[counter];
            }
            printf("Enter the lower threshold number that you want to use.              \n");
            printf("The value ranges from 0 - 99. [POSITIVE NUMBERS ONLY]               \n");
            printf("If you want to enter 55. Enter; [Ex. --> 55]                        \n");
            printf("                                                                    \n");
            printf("--> ");
            scanf("%3d", &lowerThreshold);
            printf("                                                                    \n");
            printf("****************************************************************    \n");
            printf("                                                                    \n");
            printf("Enter the upper threshold number that you want to use.              \n");
            printf("The value ranges from 0 - 99. [POSITIVE NUMBERS ONLY]               \n");
            printf("If you want to enter 55. Enter; [Ex. --> 55]                        \n");
            printf("                                                                    \n");
            printf("--> ");
            scanf("%3d", &upperThreshold);
            printf("                                                                    \n");
            printf("****************************************************************    \n");
            printf("                                                                    \n");
            
            break;
            
        case 'b':
            for (counter = 0; counter< SIZE ; counter++)
            {
                inUseArray[counter] = highNumbers[counter] ;
            }
            printf("Enter the lower threshold number that you want to use.              \n");
            printf("The value ranges from 52 - 150. [POSITIVE NUMBERS ONLY]             \n");
            printf("If you want to enter 55. Enter; [Ex. --> 55]                        \n");
            printf("                                                                    \n");
            printf("--> ");
            scanf("%3d", &lowerThreshold);
            printf("                                                                    \n");
            printf("****************************************************************    \n");
            printf("                                                                    \n");
            printf("Enter the upper threshold number that you want to use.              \n");
            printf("The value ranges from 52 - 150. [POSITIVE NUMBERS ONLY]             \n");
            printf("If you want to enter 55. Enter; [Ex. --> 55]                        \n");
            printf("                                                                    \n");
            printf("--> ");
            scanf("%3d", &upperThreshold);
            printf("                                                                    \n");
            printf("****************************************************************    \n");
            printf("                                                                    \n");
             break;
    }
    
    printf("        above  below   between                                              \n");
    printf(" index   %3d    %3d    the two                                              \n", lowerThreshold, upperThreshold);
    printf("-------------------------------                                             \n");
    
    filter_Below_Threshold(upperThreshold, inUseArray, belowArray);   // function call for less than threshold values
    filter_Above_Threshold(lowerThreshold, inUseArray, aboveArray);   // function call for more than threshold values
    filter_Above_Threshold(lowerThreshold, belowArray, betweenArray); // function call for BETWEEN threshold values
    print3Arrays(aboveArray, belowArray, betweenArray);               // function call to print the table
    
    printf("-------------------------------                                             \n\n");
    printf("****************************************************************            \n");
    printf("                    Program Terminating                                     \n");
    printf("****************************************************************            \n");
    
    return 0;
}

//*******************************************************************
                    /*// FUNCTION DEFINITIONS \\*/
//*******************************************************************

void filter_Below_Threshold(int thres, int src[], int filtered[])
{
    int counter = 0;
    int index = 0;
    for (counter = 0; counter < SIZE; counter++)
    {
        if (src[counter] < thres)
        {
            filtered[index] = src[counter];
            index++;
        }
    }
}
void filter_Above_Threshold(int thres, int src[], int filtered[])
{
    int counter = 0;
    int index = 0;
    for (counter = 0; counter < SIZE; counter++)
    {
        if (src[counter] > thres)
        {
            filtered[index] = src[counter];
            index++;
        }
    }
}
void print3Arrays(int arr1[], int arr2[], int arr3[])
{
   int counter = 0;
    int index;
    for (index = 0; index < SIZE; index++)
    {
        if (arr1[index] > -1 || arr2[index] > -1 || arr3[index] > -1)
        {
            printf("  %2d:", counter);
           
            if( arr1[index] > -1 )
            {
                printf("    %3d",arr1[index]);
            }
            else
            {
                printf("    ---");
            }
            if( arr2[index] > -1 )
            {
                printf("    %3d",arr2[index]);
            }
            else
            {
                printf("    ---");
            }
            if( arr3[index] > -1 )
            {
                printf("     %3d\n",arr3[index]);
            }
            else
            {
                printf("     ---\n");
            }
        }
        counter++;
    }
}

