//
// CalcPaintCost.c

//
//  Created by Hemant Mahato on 11/5/19.
//  Copyright © 2019 Hemant Mahato. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define AREA_OF_DOOR 21
#define AREA_OF_WINDOW 12
#define SQ_FT_PER_GAllON_SPLASH_OF_COLOR 550
#define SQ_FT_PER_GAllON_CHANGE_THE_MOOD 400
#define SQ_FT_PER_GAllON_COVER_ALL_SINS 350
#define COST_PER_GAllON_SPLASH_OF_COLOR 19.99
#define COST_PER_GAllON_CHANGE_THE_MOOD 29.99
#define COST_PER_GAllON_COVER_ALL_SINS 35.99

void displayIntroduction(void);
int enter_room_dimensions(void);
int enter_doors_windows(void);
void displayTermination(void);
int calculate_gallons_neeed(int area, char paint_code);
float calculate_cost(int gallons, char paint_code);

int main(int argc, const char * argv[])
{
    displayIntroduction();

    int square_feet = enter_room_dimensions();
    int doors_windows_area = enter_doors_windows();
    
    int gross_sq_ft = square_feet - doors_windows_area;
    printf("You entered room dimensions that generated %d sq ft of area\n", square_feet);
    printf("You have doors and windows of %d sq ft of area.\n", doors_windows_area);
    printf("This generates %d of sq. ft. that needs to be covered.\n\n", gross_sq_ft);
    
    char splash_of_color = 'a';
    char change_the_mood = 'b';
    char cover_all_sins = 'c';
    int a_gallons = calculate_gallons_neeed(gross_sq_ft,splash_of_color);
    int a_2coats = calculate_gallons_neeed(2*gross_sq_ft,splash_of_color);
    int a_3coats = calculate_gallons_neeed(3*gross_sq_ft,splash_of_color);
    int b_gallons = calculate_gallons_neeed(gross_sq_ft,change_the_mood);
    int b_2coats = calculate_gallons_neeed(2*gross_sq_ft,change_the_mood);
    int c_gallons = calculate_gallons_neeed(gross_sq_ft,cover_all_sins);
    
    
    printf("The cost of using 'splash-of-color'\n");
    
    printf("        1 coat: $ %7.2f (%5d sq.ft --> gals: %2d)\n", calculate_cost(a_gallons,splash_of_color), gross_sq_ft, calculate_gallons_neeed(gross_sq_ft,splash_of_color));
    printf("        2 coat: $ %7.2f (%5d sq.ft --> gals: %2d)\n", calculate_cost(a_2coats,splash_of_color), 2*gross_sq_ft, calculate_gallons_neeed(2*gross_sq_ft,splash_of_color));
    printf("        3 coat: $ %7.2f (%5d sq.ft --> gals: %2d)\n", calculate_cost(a_3coats,splash_of_color), 3*gross_sq_ft, calculate_gallons_neeed(3*gross_sq_ft,splash_of_color));
    
    printf("The cost of using 'change-the-mood'\n");
    printf("        1 coat: $ %7.2f (%5d sq.ft --> gals: %2d)\n", calculate_cost(b_gallons,change_the_mood), gross_sq_ft, calculate_gallons_neeed(gross_sq_ft,change_the_mood));
    printf("        2 coat: $ %7.2f (%5d sq.ft --> gals: %2d)\n", calculate_cost(b_2coats,change_the_mood), 2*gross_sq_ft, calculate_gallons_neeed(2*gross_sq_ft,change_the_mood));
    
    printf("The cost of using 'cover-all-sins'\n");
    printf("        1 coat: $ %7.2f (%5d sq.ft --> gals: %2d)\n", calculate_cost(c_gallons,cover_all_sins), gross_sq_ft, calculate_gallons_neeed(gross_sq_ft,cover_all_sins));
    
    
    
    displayTermination();
        
}
//********************************************************
//*********************/*FUNCTIONS*/**********************
//********************************************************


void displayIntroduction(void)
{
    printf("       This program will ask you to enter your house dimensions\n");
    printf("         i.e. the length width and the height of your walls \n");
    printf("  It will the ask you to enter the numbers of doors and windows \n");
    printf("                           in your house \n");
    printf("  The program will then take the data you entered and calculate the \n");
    printf("     square footage of your house and your windows seperately \n");
    printf("  After all is processed, the program will give you the gross square  \n");
    printf("          footage of your house that needs to be painted. \n");
    printf("  The program will calculate the cost and the gallons of paint to cover \n");
    printf("             the enitre gross square footage of the place\n");
    printf("\n");
    printf("***************************************************************************\n");
    printf("There are three types of paint namely, splash-of-color, change-the-mood \n");
    printf("                       and cover-all-sins.\n");
    printf("Splash-of color is s best if used to cover paint of the same color to  \n");
    printf("            give the room a fresh, clean appearance . \n");
    printf("Change-the-mood is meant to go on over a different color, when a change .\n");
    printf("of the room’s color is wanted. Works best when going from light color to \n");
    printf("                        a darkern color.\n");
    printf("          Cover-all-sins is meant to cover anything under a\n");
    printf("single coat of paint from dark or bright colors colors to dark oily stains.\n");
    printf("This is used when other paints would have the underlaying color show through\n");
    printf("***************************************************************************\n");
    printf("***************************************************************************\n");
}

int  enter_room_dimensions(void)
{
    printf("Please enter the length, width and height\n");
    printf("of the room to be painted, seperated by a space.\n");
    printf("For example, if your room is \n");
    printf("  10 feet long, \n");
    printf("  13 feet wide and\n");
    printf("   8 feet high,\n");
    printf("Enter 10 13 8\n");
    printf("All numbers should be positive & between 0 and 100. \n");
    
    int length;
    int width;
    int height;
    
    printf("--> ");
    scanf(" %d %d %d", &length, &width, &height);
    printf("You entered room dimensons of %3d by %3d by %3d.\n", length, width, height);
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    int square_feet = 2* height * width + 2 * height * length;
    return square_feet;
}

int enter_doors_windows(void)
{
    printf("Please enter the number of standard doors and standard\n");
    printf("windows seperated by a space.\n");
    printf("For example, if you have one door and one window, enter 1 1\n");
    printf("All numbers should be positive & between 0 and 100.\n");
    int number_of_doors;
    int number_of_windows;

    printf("--> ");
    scanf(" %d %d", &number_of_doors, &number_of_windows);
    printf("You entered %2d doors and %2d windows.\n", number_of_doors, number_of_windows);
    printf("***********************************************************\n");
    int area_of_doorsAndWindows = number_of_doors*AREA_OF_DOOR + number_of_windows*AREA_OF_WINDOW;
    return  area_of_doorsAndWindows;
}

int calculate_gallons_neeed (int area, char paint_code )
{
    int gallons;
    int sq_ft_per_gallon = '#';
    switch (paint_code)
    {
        case 'a':
            sq_ft_per_gallon = SQ_FT_PER_GAllON_SPLASH_OF_COLOR;
            break;
        case 'b':
            sq_ft_per_gallon = SQ_FT_PER_GAllON_CHANGE_THE_MOOD;
            break;
        case 'c':
            sq_ft_per_gallon = SQ_FT_PER_GAllON_COVER_ALL_SINS;
            break;
    }
    gallons = area / sq_ft_per_gallon;
    if (area % sq_ft_per_gallon != 0)
        gallons++;
    return round(gallons);
}

float calculate_cost (int gallons, char paint_code)
{
    
    float cost= '#';
   
    switch (paint_code)
    {
        case 'a':
            cost = gallons * COST_PER_GAllON_SPLASH_OF_COLOR;
            break;
        case 'b':
            cost = gallons * COST_PER_GAllON_CHANGE_THE_MOOD;
            break;
        case 'c':
            cost = gallons * COST_PER_GAllON_COVER_ALL_SINS;
            break;
    }
    float total_cost = cost;
    return total_cost;
}

void displayTermination(void)
{
    puts("***********************************************************\n");
    printf("               Thank you for your business.\n");
    puts("                  This program is ending.\n");
    puts("***********************************************************\n");
    exit (1);
}

