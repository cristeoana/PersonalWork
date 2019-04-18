#pragma once
#include "ProductRepo.h"
#include "Stack.h"

typedef struct
{
	ProductRepo* repo;
	OperationStack* undoStack;
	OperationStack* redoStack;

}Controller;



/// DESCRIPTION: creates a new Controller type object
/// INPUT: r - repository of products
///        undo - stack of operations used for undo/redo functionalities
/// OUTPUT: pointer to Controller type
Controller* createController(ProductRepo* r, OperationStack* undo, OperationStack* redo);



/// DESCRIPTION: destroys a Controller type object
/// INPUT: c - Controller type pointer
/// OUTPUT: -
void destroyController(Controller* c);




/// DESCRIPTION: adds a Product to the repository of Products
/// INPUT: c - pointer to a Controller type object;
///        + characteristics of Product (name, category - string, quantity - integer, expiration date - Date)
/// OUTPUT: 1 - successfully added ;  0 - could not be added
int addProductController(Controller* c, char* name, char* category, int quantity, Date expDate);




/// DESCRIPTION: removes a Product from the repository of Products
/// INPUT: c - pointer to a Controller type object;
///        name - string, the name of the object which we want to delete
/// OUTPUT: -
void removeProductController(Controller*c, char *name);




/// DESCRIPTION: updates a Product from the repository of Products
/// INPUT: c - pointer to a Controller type object;
///        prod - Product to be replaced
///        newProd - Product which replaces prod, if mat exists in repository
/// OUTPUT: -
void updateProductController(Controller* c, Product* prod, Product* newProd);




/// DESCRIPTION: destroys a Controller type object
/// INPUT: c - Controller type pointer
/// OUTPUT: pointer to ProductRepo type
ProductRepo* getRepo(Controller* c);


/// DESCRIPTION: un-does the last performed operation
/// INPUT: c - Controller type pointer
/// OUTPUT: 1 - successfully undone, 0 - otherwise
int undo(Controller* c);



/// DESCRIPTION: re-does the last performed operation
/// INPUT: c - Controller type pointer
/// OUTPUT: 1 - successfully redone, 0 - otherwise
int redo(Controller* c);



/// DESCRIPTION: filters all Products from repo which have a given category
///              the selected items are stored in a ProductRepo 
/// INPUT: c - Controller type pointer
///        category - name of a category
/// OUTPUT: pointer to ProductRepo 
ProductRepo* displayProductsForCategory(Controller* c, char* category);



/// DESCRIPTION: adds a few Products to a controoler
/// INPUT: c - Controller type pointer
/// OUTPUT: -
void initializeController(Controller* c);


