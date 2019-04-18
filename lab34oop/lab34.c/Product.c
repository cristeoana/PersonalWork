#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Product.h"
#include "Date.h"


Product* createProduct(char* name, char* category, int quant, Date expDate)
{
	Product* prod = (Product*)malloc(sizeof(Product));
	prod->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(prod->name, name);
	prod->category = (char*)malloc(sizeof(char) * (strlen(category) + 1));
	strcpy(prod->category, category);

	prod->quantity = quant;
	copyDate(&prod->expDate, expDate);


	return prod;
}


///////////////////////////////////////////////////////////////



void destroyProduct(Product* prod)
{

	if (prod == NULL)
		return;

	// free the memory which was allocated for the component fields
	free(prod->name);
	free(prod->category);

	// free the memory which was allocated for the Product structure
	free(prod);
	

}

///////////////////////////////////////////////////////////////


void printProduct(Product* prod)
{
	printf("Name: %s  Category: %s  Quantity: %d  ExpDate: ", getName(prod), getCategory(prod), getQuantity(prod));
	printDate(prod->expDate);
	printf("\n");
}

///////////////////////////////////////////////////////////////


char* getName(Product* prod)
{
	return prod->name;
}

///////////////////////////////////////////////////////////////

char* getCategory(Product* prod)
{
	return prod->category;
}

///////////////////////////////////////////////////////////////



int   getQuantity(Product* prod)
{
	return prod->quantity;
}

///////////////////////////////////////////////////////////////


Date getExpirationDate(Product* prod)
{
	return prod->expDate;
}

///////////////////////////////////////////////////////////////

Product* copyProduct(Product* prod)
{
	if (prod == NULL)
		return NULL;

	Product* newProd = createProduct(getName(prod), getCategory(prod), getQuantity(prod), getExpirationDate(prod));
	return newProd;
}

///////////////////////////////////////////////////////////////
void swapProducts(Product* *prod1, Product* *prod2)
{
	Product* temp = *prod1;
	*prod1 = *prod2;
	*prod2 = temp;
}

void deleteP(Product *product)
{
	product->name = NULL;
	product->category = NULL;
}