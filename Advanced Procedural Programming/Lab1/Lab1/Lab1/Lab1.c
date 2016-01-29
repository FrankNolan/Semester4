#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

FILE*fptr;

void main()
{
	char department[10];
	float numOfSales;
	float totalSales = 0;
	// Total is for the total amount of sales within the department
	float totalHardware = 0;
	float totalGrocery = 0;
	float totalDrapery = 0;
	// The highest sale that was made in a department
	float maxHardware = 0;
	float maxGrocery = 0;
	float maxDrapery = 0;
	// 3 variables for sales count in each department
	int hCount = 0;
	int gCount = 0;
	int dCount = 0;
	// 3 average variables per department
	float averageHardware;
	float averageGrocery;
	float averageDrapery;

	fptr = fopen("DailySales.txt", "r");
	if (fptr == NULL)
	{
		printf("Cannot find file");
	}
	else
	{

		while (!feof(fptr))
		{
			//Read name of department %s
			fscanf(fptr, "%s", department);

			//Read value %f
			fscanf(fptr, "%f", &numOfSales);
			
			//If department equals hardware/grocery/drapery
			//Add to total Sales for each department
			//Add to count so that an average for each department can be calculated
			//And check what the highest/max sale is for each department
			if (strcmp(department, "Hardware") == 0)
			{
				// add number of sales to total hardware
				totalHardware += numOfSales;
				// add to hardware sales count
				hCount++;

				// check if the number of sales is higher than the current maxHardware sale
				// if so -> replace the current maxHardware value with the sales record
				if (numOfSales > maxHardware)
				{
					maxHardware = numOfSales;
				}
			}
			if (strcmp(department, "Grocery") == 0)
			{
				totalGrocery += numOfSales;
				gCount++;

				if (numOfSales > maxGrocery)
				{
					maxGrocery = numOfSales;
				}
			}
			if (strcmp(department, "Drapery") == 0)
			{
				totalDrapery += numOfSales;
				dCount++;

				if (numOfSales > maxDrapery)
				{
					maxDrapery = numOfSales;
				}
			}
		}
		// Calculate total sales
		totalSales = totalHardware + totalGrocery + totalDrapery;

		// Output header
		printf("Department Sales\n\n");

		// output the total sales for the day
		printf("Total Sales: %.2f\n", totalSales);

		// calculate the averages of each department and output to the screen
		averageHardware = totalHardware / hCount;
		averageGrocery = totalGrocery / gCount;
		averageDrapery = totalDrapery / dCount;

		printf("Average Hardware: %.2f\n", averageHardware);
		printf("Average Grocery: %.2f\n", averageGrocery);
		printf("Average Drapery: %.2f\n", averageDrapery);

		// Print out the highest/max sale in each department
		printf("MaxHardware Sales: %.2f\n", maxHardware);
		printf("MaxGrocery Sales: %.2f\n", maxGrocery);
		printf("MaxDrapery Sales: %.2f\n", maxDrapery);

		// close the file
		fclose(fptr);
	}
	getch();		
}


