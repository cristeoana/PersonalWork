#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Controller.h"



Controller* createController(ProductRepo* r, OperationStack* undo, OperationStack* redo)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	c->undoStack = undo;
	c->redoStack = redo;
}


///////////////////////////////////////////////////////////////


void destroyController(Controller* c)
{
	// destroy the repository inside
	destroyRepo(c->repo);

	//  destroy the operation stack
	destroyStack(c->undoStack);
	destroyStack(c->redoStack);

	// free memory of c
	free(c);
}

///////////////////////////////////////////////////////////////


int addProductController(Controller* c, char* name, char* category, int quantity, Date expDate)
{
	Product* prod = createProduct(name, category, quantity, expDate);
	int res = addProduct(c->repo, prod);
	if (res == 1)  // if successful operation, add to stack
	{
		Operation* o = createOperation(prod, "add", findPosOfProduct(c->repo, prod->name));
		push(c->undoStack, o);
		// after adding, operation can be destroyed; we stored the copy of it
		destroyOperation(o);
	}
	// destroy the Product that was created, as we stored a copy of it in repo
	destroyProduct(prod);
}


///////////////////////////////////////////////////////////////

void removeProductController(Controller*c, char *name)
{
	Product* prod = find(c->repo, name);
	int pos = findPosOfProduct(c->repo, name);
	Operation* o = createOperation(prod, "remove", pos);
	push(c->undoStack, o);
	deleteProduct(c->repo, name);
}

///////////////////////////////////////////////////////////////


void updateProductController(Controller* c, Product* prod, Product* newProd)
{
	int pos = findPosOfProduct(c->repo, prod->name);
	Product* copy = copyProduct(prod); //
	Operation* o = createOperation(copy, "update", pos);//
	destroyProduct(copy);//
	push(c->undoStack, o);
	updateProduct(c->repo, prod, newProd);

}

///////////////////////////////////////////////////////////////

ProductRepo* getRepo(Controller* c)
{
	return c->repo;
}

///////////////////////////////////////////////////////////////


int undo(Controller* c)
{
	if (isEmpty(c->undoStack))
		return 0;

	Operation* operation = pop(c->undoStack);
	if (strcmp(operation->operationType, "upadate") != 0)
		push(c->redoStack, operation);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Product* product = getProduct(operation);
		char name[50];
		strcpy(name, getName(product));
		deleteProduct(c->repo, name);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0 || strcmp(getOperationType(operation), "delete") == 0)
	{
		Product* product = getProduct(operation);
		addProduct(c->repo, product);

	}
	else if (strcmp(getOperationType(operation), "update") == 0)
	{
		Product* product = getProduct(operation);
		operation->product = c->repo->products->elems[operation->idProduct];
		push(c->redoStack, operation);
		updateProduct(c->repo, c->repo->products->elems[operation->idProduct], product);

	}
	// destroy the operation
	//destroyOperation(operation);

	return 1;
}

///////////////////////////////////////////////////////////////


int redo(Controller* c)
{
	if (isEmpty(c->redoStack))
		return 0;

	Operation* operation = pop(c->redoStack);
	push(c->undoStack, operation);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Product* product = getProduct(operation);
		addProductController(c, product->name, product->category, product->quantity, product->expDate);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0 || strcmp(getOperationType(operation), "delete") == 0)
	{
		Product* product = getProduct(operation);
		removeProductController(c, product->name);

	}
	else if (strcmp(getOperationType(operation), "update") == 0)
	{
		Product* product = getProduct(operation);
		updateProduct(c->repo, c->repo->products->elems[operation->idProduct], product);

	}
	return 1;

}


///////////////////////////////////////////////////////////////

ProductRepo* displayProductsForCategory(Controller* c, char* category)
{
	ProductRepo* prodRepo = createRepo();
	int length = c->repo->products->length;
	int ok = 0;
	for (int i = 0; i < length; i++)
	{
		Product* prod = getProductOnPos(c->repo, i);
		if (strcmp(prod->category, category) == 0)
		{
			addProduct(prodRepo, prod);
			ok = 1;
		}
	}
	if (ok)
		return prodRepo;
	prodRepo = NULL;
	return prodRepo; // category not found in repo
}

///////////////////////////////////////////////////////////////

void initializeController(Controller* c)
{

	
	Date exp;

	exp.day = 7; exp.month = 3; exp.year = 2018;
	addProductController(c, "yogurt", "diary", 7, exp);

	int quantity = 300;
	exp.day = 6; exp.month = 2; exp.year = 2018;
	addProductController(c, "cheese", "diary", quantity, exp);
	

	exp.day = 7; exp.month = 5; exp.year = 2018;
	addProductController(c, "milk", "diary", 7, exp);

	/*char *name2 = "donuts", *category2 = "sweets";
	exp.day = 3; exp.month = 4; exp.year = 2018;
	addProductController(c, name2, category2, 15, exp);


	char *name3 = "chocolate", *category3 = "sweets";
	exp.day = 4; exp.month = 12; exp.year = 2018;
	addProductController(c, name3, category3, 5, exp);

	char *name4 = "chicken breast", *category4 = "meat";
	exp.day = 8; exp.month = 5; exp.year = 2018;
	addProductController(c, name4, category4, 2, exp);

	char *name5 = "banana", *category5 = "fruits";
	exp.day = 12; exp.month = 5; exp.year = 2018;
	addProductController(c, name5, category5, 8, exp);

	char *name6 = "orange", *category6 = "fruits";
	exp.day = 27; exp.month = 11; exp.year = 2018;
	addProductController(c, name6, category6, 29, exp);

	char *name7 = "milk", *category7 = "dairy";
	exp.day = 19; exp.month = 6; exp.year = 2018;
	addProductController(c, name7, category7, 1, exp);

	char *name8 = "bacon", *category8 = "meat";
	exp.day = 25; exp.month = 10; exp.year = 2018;
	addProductController(c, name8, category8, 3, exp);*/
}