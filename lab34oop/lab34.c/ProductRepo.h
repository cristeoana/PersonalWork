#pragma once
#include "Repo.h"
#include "Product.h"


typedef struct
{
	DynamicRepo* products;
} ProductRepo;


/// DESCRIPTION: creates a repository of Product type values
/// INPUT: -
/// OUTPUT:  pointer to ProductRepo type
ProductRepo* createRepo();




/// DESCRIPTION: destroys a repository of Product type values
/// INPUT: pointer to ProductRepo type
/// OUTPUT: -
void destroyRepo(ProductRepo *v);



/// DESCRIPTION: searches by name for a product in the Product repository
/// INPUT: v-pointer to ProductRepo type, name- pointer to string(the name to search for)
/// OUTPUT: position of the found product;
///         if no such product was found, it retrieves -1 value
int findPosOfProduct(ProductRepo* v, char* name);



/// DESCRIPTION: searches by name for a product in the Product repository
/// INPUT: v-pointer to ProductRepo type, name- pointer to string(the name to search for)
/// OUTPUT: pointer to the product whose name we searched for. 
///         if no such product was found, it retrieves a NULL pointer
Product* find(ProductRepo* v, char* name);



/// DESCRIPTION: adds a Product to the repository of Products
/// INPUT: v-pointer to ProductRepo type
///        prod - a product to be added to the repository
/// OUTPUT: 1 - successfully added
///         0 - otherwise - product already exists
int addProduct(ProductRepo* v, Product* mat);




/// DESCRIPTION: adds a Product to the repository of Products
/// INPUT: v-pointer to ProductRepo type
///        name -name of the product to be removed from repo
///        if found, the product is deleted
/// OUTPUT: -
void deleteProduct(ProductRepo* v, char* name);





/// DESCRIPTION: updates a Product from repo, if that Product exists
/// INPUT: v-pointer to ProductRepo type
///        prod -Product to update
///        newProd - Product to replace with the old one
/// OUTPUT: -
void updateProduct(ProductRepo* v, Product* mat, Product* newMat);




/// DESCRIPTION: retrieves the length of the repository
/// INPUT: v-pointer to ProductRepo type
/// OUTPUT: integer, positive number; could be >=0
int getRepoLength(ProductRepo* v);




/// DESCRIPTION: retrieves the Product on a given position from repo 
/// INPUT: v-pointer to ProductRepo type
///        pos - integer, valid position
/// OUTPUT: pointer to the Product; NULL - otherwise
Product* getProductOnPos(ProductRepo* v, int pos);




/// DESCRIPTION: prints the elements from repository of Products
/// INPUT: v-pointer to ProductRepo type
/// OUTPUT: -
void printProducts(ProductRepo* v);



/// DESCRIPTION: sorts Products ascendently, by quantity
/// INPUT: v-pointer to ProductRepo type
/// OUTPUT: -
void sortProductsName(ProductRepo* v);



/// DESCRIPTION: sorts Products ascendently, by expiration month
/// INPUT: v-pointer to ProductRepo type
/// OUTPUT: -
void sortProductsMonth(ProductRepo* v);
