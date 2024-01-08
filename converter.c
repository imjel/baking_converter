/*
~ BAKING CONVERTER ~
convenient program for converting recipe quantities from cups to grams
@author Max Endieveri
*/
#include <stdio.h>

int loop;
int input;
int ingInput;
double quantityVal;
double output;

/*
Notes if converting from weight to vol or vice versa
*/
int setWeightVol()
{
	printf("\nIs the original quantity by weight (1) or volume (2)?\n");
	scanf("%d", &input);
	if(input != 1 && input != 2){
		printf("\nInvalid input\n");
		return 0;
	}
	return 1;
}

/*
Conversion function takes ingredient and converts
*/
void conversion(double factor, const char* ingredient)
{
	printf("\nEnter the quantity in %s: ", (input == 1) ? "grams" : "cups");
	scanf("%lf", &quantityVal);
	output = quantityVal * factor;
	printf("\nYou need %lf %s of %s.\n", output, (input == 1) ? "cups" : "grams", ingredient);
}

int main()
{
	printf("\n-----Welcome to the cups and grams baking converter!-----\n");
	// output menu loop
	do{
		printf("\nEnter '1' to convert, or '2' to quit!\n");
		scanf("%d", &loop);
		
		if(loop == 1)
		{
			// check if grams -> cups or vice versa
			setWeightVol();

			if(setWeightVol()){
				// get ingredient to convert from user
				printf("\nWhat ingredient are you converting, from the following list?\n");
				printf("Flour (1)\nWhite sugar (2)\nOil (3)\nButter (4)\nCocoa powder (5)\nCream cheese (6)\nChocolate (7)\nHeavy cream (8)\n");

				scanf("%d", &ingInput);
				
				switch(ingInput){
					case 1:
						conversion((input == 1) ? 1.0/125 : 125, "flour");
						break;
					case 2:
						conversion((input == 1) ? 1.0/200 : 200, "sugar");
						break;
					case 3:
						conversion((input == 1) ? 1.0/215 : 215, "oil");
						break;
					case 4:
						conversion((input == 1) ? 1.0/226 : 226, "butter");
						break;
					case 5:
						conversion((input == 1) ? 1.0/120 : 120, "cocoa powder");
						break;
					case 6: 
						conversion((input == 1) ? 1.0/225 : 225, "cream cheese");
						break;
					case 7:
						conversion((input == 1) ? 1.0/160 : 160, "chocolate");
						break;
					case 8:
						conversion((input == 1) ? 1.0/240 : 240, "heavy cream");
						break;
					default:
						printf("\nInvalid input. Choose an ingredient from the list and try again.\n");
						break;
				}
			}
		}
	}while (loop != 2);

	return 0;
}