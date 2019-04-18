#include          <stdio.h>
#include         <stdlib.h>
#include         <assert.h>
#include        <Windows.h>
#include         <crtdbg.h>
#include          "Tests.h"
#include           "Date.h"
#include   "ProductRepo.h"
#include          "Stack.h"
#include     "Controller.h"


void testvalidateDate()
{
	Date d;
	d.day = 2; d.month = 2; d.year = 2017;
	assert(validateDate(d) == 1);
	d.year = 2014;
	assert(validateDate(d) == 0);
	d.year = 2017; d.day = -2;
	assert(validateDate(d) == 0);
	d.day = 30;
	assert(validateDate(d) == 0);
}

///////////////////////////////////////////////////////////////

void testcompareDates()
{
	Date d1, d2, d3;
	d1.day = 19; d1.month = 4; d1.year = 2018;
	d2.day = 2; d2.month = 5; d2.year = 2018;
	d3.day = 2; d3.month = 5; d3.year = 2018;
	assert(compareDates(d1, d2) == -1);
	//assert(compareDates(d1, d3) == 0);
	assert(compareDates(d2, d1) == 1);
	assert(compareDates(d2, d3) == 0);
}

//////////////////////////////////////////////////////////////

void testcopyDate()
{
	Date d1, d2;
	d1.day = 19; d1.month = 4; d1.year = 2018;
	d2.day = 2; d2.month = 5; d2.year = 2018;
	copyDate(&d2, d1);
	printDate(d2);
}

///////////////////////////////////////////////////////////////

void testCreateDestroyProduct()
{
	Product *prod;
	char *name = "apple", *category = "fruits";
	Date exp;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, 10, exp);
	destroyProduct(prod);
	_CrtDumpMemoryLeaks();
}

///////////////////////////////////////////////////////////////

void testcopyProduct()
{
	Product *prod, *newProd;
	char *name = "apple", *category = "fruits";
	Date exp;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, 10, exp);
	newProd = copyProduct(prod);
	printProduct(newProd);
}


///////////////////////////////////////////////////////////////

void testgetName()
{
	Product *prod;
	char *name = "candy", *category = "sweets";
	Date exp;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, 10, exp);
	char *str = getName(prod);
	printf("%s\n", str);
}

///////////////////////////////////////////////////////////////


void testgetCategory()
{
	Product *prod;
	char *name = "candy", *category = "sweets";
	Date exp;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, 10, exp);
	char *str = getCategory(prod);
	printf("%s\n", str);
}

///////////////////////////////////////////////////////////////


int testgetQuantity()
{
	Product *prod;
	char *name = "candy", *category = "sweets";
	Date exp;
	int quant = 5;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, quant, exp);
	printf("%d\n", prod->quantity);
}


///////////////////////////////////////////////////////////////


Date testgetExpirationDate()
{
	Product *prod;
	char *name = "candy", *category = "sweets";
	Date exp;
	int quant = 5;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, quant, exp);
	Date d = getExpirationDate(prod);
	printDate(d);
}

///////////////////////////////////////////////////////////////


void testCreateDestroyRepo()
{
	ProductRepo* v = createRepo();
	destroyRepo(v);
	_CrtDumpMemoryLeaks();

}


///////////////////////////////////////////////////////////////


void testaddProduct()
{
	Product *prod;
	char *name = "milk", *category = "dairy";
	Date exp;
	int quant = 3;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, quant, exp);
	ProductRepo* v = createRepo();
	int check = addProduct(v, prod);

	Product *prod2;
	char *name2 = "candy", *category2 = "sweets";
	Date exp2;
	int quant2 = 1;
	exp2.day = 3; exp2.month = 4; exp2.year = 2018;
	prod2 = createProduct(name2, category2, quant2, exp2);
	check = addProduct(v, prod2);

	printf("%d\n", check);
	printf("%d\n", getQuantity(v->products->elems[0]));

}

///////////////////////////////////////////////////////////////


void testdeleteProduct()
{
	Product *prod;
	char *name = "milk", *category = "dairy";
	Date exp;
	int quant = 3;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, quant, exp);
	ProductRepo* v = createRepo();
	int check = addProduct(v, prod);
	deleteProduct(v, "milk");
	if (v->products->length == 0)
		printf("ok");
	else
		printf("nooooooo!!!");
}

///////////////////////////////////////////////////////////////


void testupdateProduct()
{
	Product *prod;
	char *name = "milk", *category = "dairy";
	Date exp;
	int quant = 3;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod = createProduct(name, category, quant, exp);
	ProductRepo* v = createRepo();
	int check = addProduct(v, prod);
	printf("%d\n", check);
	Product *newprod;
	char *name2 = "yogurt";
	char *category2 = "dairy";
	quant = 10;
	exp.day = 3; exp.month = 10; exp.year = 2018;
	newprod = createProduct(name2, category2, quant, exp);
	updateProduct(v, prod, newprod);

	int pos = findPosOfProduct(v, "milk");
	printf("%d\n", pos);
}

///////////////////////////////////////////////////////////////


void testStackOperations()
{
	OperationStack* s = createStack();
	Product *prod1, *prod2;
	char *name = "milk", *category = "dairy";
	Date exp;
	int quant = 3;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod1 = createProduct(name, category, quant, exp);

	name = "banana"; category = "fruits";
	quant = 15;
	prod2 = createProduct(name, category, quant, exp);
	int id1, id2;
	Operation* o1 = createOperation(prod1, "add", 1);
	Operation* o2 = createOperation(prod2, "add", 1);
	Operation* o3 = createOperation(prod1, "remove", 1);

	// the materials may be destroyed, as the operations contain copies of these planets
	destroyProduct(prod1);
	destroyProduct(prod2);

	push(s, o1);
	push(s, o2);
	push(s, o3);

	// the operations may be destroyed, as the stack contains copies of these operations
	destroyOperation(o1);
	destroyOperation(o2);
	destroyOperation(o3);

	assert(isFull(s) == 0);
	assert(isEmpty(s) == 0);
	Operation* o = pop(s);
	assert(strcmp(o->operationType, "remove") == 0);
	// after each pop, the operations must be destroyed
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	assert(isEmpty(s) == 1);

	// destroy the stack
	destroyStack(s);
}

///////////////////////////////////////////////////////////////



void testController()
{
	ProductRepo* r = createRepo();
	OperationStack* s = createStack();
	OperationStack* rs = createStack();
	Controller* c = createController(r, s, rs);

	//create Product
	Product *prod1;
	char *name = "milk", *category = "dairy";
	Date exp;
	int quant = 3;
	exp.day = 3; exp.month = 4; exp.year = 2018;
	prod1 = createProduct(name, category, quant, exp);

	//add Product
	addProductController(c, name, category, quant, exp);
	int id = findPosOfProduct(c->repo, prod1->name);



	//update Product
	Product* prod2;
	char* name2 = "candy", *category2 = "sweets";
	int quant2 = 5;
	prod2 = createProduct(name2, category2, quant2, exp);
	updateProductController(c, prod1, prod2);



	//push operation add on stack
	Operation* oUndo = createOperation(prod1, "add", id);
	Operation* opUndo = createOperation(prod1, "update", id);

	Operation* oRedo = createOperation(prod1, "add", id);
	Operation* opRedo = createOperation(prod2, "update", id);

	push(c->undoStack, oUndo);
	push(c->undoStack, opUndo);
	push(c->redoStack, oRedo);
	push(c->redoStack, opRedo);

	int checkUndo = undo(c);
	printProducts(c->repo);

	int checkRedo = redo(c);
	printProducts(c->repo);

	printf("%d %d\n", checkUndo, checkRedo);

	//destroyController(c);
}



///////////////////////////////////////////////////////////////



void testInitializeController()
{
	ProductRepo* r = createRepo();
	OperationStack* s = createStack();
	OperationStack* rs = createStack();
	Controller* c = createController(r, s, rs);
	initializeController(c);
	printProducts(c->repo);
}


//int main()
//{
//testvalidateDate();
//testcompareDates();
//testcopyDate();
//testCreateDestroyMaterial();
//testgetName();
//testgetSupplier();
//testgetQuantity();
//testgetExpirationDate();
//testcopyMaterial();
//testCreateDestroyRepo();
//testaddMaterial();
//testdeleteMaterial();
//testupdateMaterial();
//testStackOperations();
//testController();
//testInitializeController();
//testMaterialSupplier();
//testswapMaterials();
//system("pause");
//return 0;
//}