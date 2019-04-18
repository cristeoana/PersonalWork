#pragma once
#include "Date.h"

typedef struct
{
	char          *name;
	char      *category;
	int            quantity;
	Date         expDate;
}Product;

void deleteP(Product *product);

/// DESCRIPTION: creates a new Material
/// INPUT: name,category - char pointers, quantity - integer, positive value, expDate - Date type value
/// OUTPUT: pointer to a Product object
Product* createProduct(char* name, char* category, int quantity, Date expDate);



/// DESCRIPTION: frees the memory allocated for a Product structure
/// INPUT: prod - pointer to Product, prod - the memory to be deallocated
/// OUTPUT: -
void destroyProduct(Product* prod);



/// DESCRIPTION: copies a Product and returns a pointer to the copy
/// INPUT: prod - pointer to Product
/// OUTPUT: pointer to Product
Product* copyProduct(Product* prod);



/// DESCRIPTION: gets the Product name
/// INPUT: prod - pointer to Product
/// OUTPUT: pointer to char
char* getName(Product* prod);



/// DESCRIPTION: gets the Product category
/// INPUT:prod - Product data type
/// OUTPUT: prod - pointer to Product
char* getCategory(Product* prod);


/// DESCRIPTION: get the Product quantity
/// INPUT: prod - pointer to Product
/// OUTPUT:  integer, positive value
int   getQuantity(Product* prod);


/// DESCRIPTION: gets the expiration date of a Product
/// INPUT: prod - pointer to Product
/// OUTPUT:  Date type value
Date getExpirationDate(Product* prod);


/// DESCRIPTION: pretty-prints Product object
/// INPUT: prod - pointer to Product
/// OUTPUT: -
void printProduct(Product* prod);



/// DESCRIPTION: swaps 2 Products
/// INPUT: 2 pointers to pointers of Product structures
/// OUTPUT: -
void swapProducts(Product* *prod1, Product* *prod2);
