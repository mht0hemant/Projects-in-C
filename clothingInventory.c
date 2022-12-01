//
//  clothigInventory.c
//  clothingInventory
//
//  Created by Hemant Mahato and Sujal Joshi on 2/6/20.
//  Copyright © 2020 Hemant Mahato. All rights reserved.
//

#include <stdio.h>
#define SIZE 10

void displayInventory(int id[], int number[], char type[], char size[], float cost[]);
int getIndex(int id, int ids[]);
void ReadDataFromFile (int itemID[], int amount[], int sales[], int returns[]);
void DisplayTransactionTotals (int itemID[], float price[], int sales[], int returns[]);
void WriteReportToFile (int itemID[], int amount[], char type[], char size[], float price[], int sales[], int returns[]);


int main(void)
{
    int itemID[SIZE] = {3213, 6293, 6190, 2420, 6859, 2703, 3220, 2899, 1987, 3191};
    int amount[SIZE] = { 5, 14, 6, 23, 6, 3, 8, 2, 11, 3};
    char type[SIZE] = { 'c', 'p', 'd', 's', 'c', 'p', 'p', 'p', 'd', 's'};
    char size[SIZE] = { 'L', 'X', 'M', 'M', 'X', 'M', 'S', 'X', 'M', 'S'};
    float price[SIZE] = {16.99,36.95,41.99,9.95,43.99,82.95,15.99,85.95,81.99,43.95};
    int sales[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int returns[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf(" Inventory prior to sales transactions\n");
    displayInventory(itemID, amount, type, size, price);

    ReadDataFromFile (itemID, amount, sales, returns);

    DisplayTransactionTotals (itemID, price, sales, returns);

    printf("\n\n Inventory after processing sales transactions\n");
    displayInventory(itemID, amount, type, size, price);

    WriteReportToFile (itemID, amount, type, size, price, sales, returns);

}

int getIndex(int id, int ids[])
{
    int position;
    for(position = 0; position < SIZE; position++)
    {
        if(id == ids[position])
        {
            return position;
            break;
        }
    }
    return -1;
}

void displayInventory(int id[], int number[], char type[], char size[], float cost[])
{
    int position;
    printf(" item#   ID  units   type    size    price\n");
    for(position = 0; position < SIZE; position ++)
    {
        printf(" %2d %8d %3d %6c %8c     $%5.2f\n", position+1, id[position],number[position],type[position],size[position],cost[position]);
    }
}

void ReadDataFromFile (int itemID[], int amount[], int sales[], int returns[])
{
    int index, Id, numUnits;

    FILE* dataStream = fopen("/Users/hemantmht0/Documents/clothingInventory/clothingInventory/salesForTheWeek.dat", "r");

    if(dataStream == NULL)
    {
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        puts("!!!!!!!!!ERROR READING FILE!!!!!!!!!!");
        puts("!!!!CHECK FILE NAME OR LOCATION!!!!!!");
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    }

    while (fscanf(dataStream, "%d %d", &Id, &numUnits) != EOF)
    {
        index = getIndex( Id, itemID);

        if(numUnits > 0)
        {
            returns[index] += numUnits;
        }
        else if(numUnits < 0)
        {
            sales[index] +=numUnits;
        }
    }
    for (int index = 0; index < SIZE; index++)
    {
        amount[index] += (sales[index] + returns[index]);
    }
    fclose(dataStream);
}

void DisplayTransactionTotals (int itemID[], float price[], int sales[], int returns[])
{
    float salesTotal = 0, returnTotal = 0;

    printf("\n\n\t\t\t            purchases\n\t\t\t            and\n item#\t id\t    sales\treturns\n");

    for (int index = 0; index < SIZE; index++)
    {
        printf(" %2d %8d %9.2f %8.2f\n", index+1 , itemID[index], (sales[index]*price[index]), (returns[index]*price[index]));
        salesTotal += sales[index]*price[index];
        returnTotal += returns[index]*price[index];
    }

    printf("\ntotals %16.2f %8.2f\n\n", salesTotal, returnTotal);
    printf("Change in inventory %12.2f\n", (salesTotal+returnTotal));

}

void WriteReportToFile (int itemID[], int amount[], char type[], char size[], float price[], int sales[], int returns[])
{
    FILE*reportStream = fopen("/Users/hemantmht0/Documents/clothingInventory/clothingInventory/transactionReport.txt", "w");

    if (reportStream == NULL)
    {
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        puts("!!!!!!!!!ERROR READING FILE!!!!!!!!!!");
        puts("!!!!CHECK FILE NAME OR LOCATION!!!!!!");
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        

    }
    fprintf(reportStream, "Post sales transactions report\n");
    fprintf(reportStream, "item#     ID  units   type    size    price   sales   returns\n");

    for( int index = 0; index < SIZE; index++)
    {
        fprintf(reportStream, "%3d %9d %3d %6c %8c    $%5.2f %8.2f %8.2f\n", index+1, itemID[index], amount[index], type[index], size[index],
        price[index], (sales[index]*price[index]), (returns[index]*price[index]));
    }
    if (reportStream != NULL)
    {
        printf("\n#########################################");
        printf("\n Please check file directory for report.");
        printf("\n#########################################");
    }
    fclose(reportStream);
}

