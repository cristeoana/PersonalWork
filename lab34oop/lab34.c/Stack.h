#pragma once
#include "Product.h"
#include "Repo.h"
#include <string.h>

typedef struct
{
	Product* product;
	char* operationType;
	int idProduct;
}Operation;


/// DESCRIPTION: creates a new operation
/// INPUT: prod = Product type value
///        operationType = string, type of the operation
///        id = integer posiive number, id of product
/// OUTPUT: pointer to Opertaion type value
Operation* createOperation(Product* prod, char* operationType, int id);



/// DESCRIPTION: destroys operation
/// INPUT: o = operation to be destroyed
/// OUTPUT: -
void destroyOperation(Operation* o);



/// DESCRIPTION: copies an operation
/// INPUT: o = operation to be copied
/// OUTPUT: pointer to Operation type value
Operation* copyOperation(Operation* o);



/// DESCRIPTION: retrieves the type of an operation
/// INPUT: o = operation type
/// OUTPUT: pointer to OperationType value
char* getOperationType(Operation* o);



/// DESCRIPTION: retrieves the Product of an operation value
/// INPUT: o = operation type
/// OUTPUT: pointer to Product object
Product* getProduct(Operation* o);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct
{
	Operation* operations[100];
	int length;

}OperationStack;


/// DESCRIPTION: creates a stack of operations
/// INPUT: -
/// OUTPUT: pointer to OperationStack value
OperationStack* createStack();


/// DESCRIPTION: creates a stack of operations
/// INPUT: - s - OperationStack pointer
/// OUTPUT: -
void destroyStack(OperationStack* s);


/// DESCRIPTION: pushes an operation on the stack
/// INPUT: - s - OperationStack pointer
///          o - Opertion pointer
/// OUTPUT: -
void push(OperationStack* s, Operation* o);


/// DESCRIPTION: removes an operation from the stack and returns it
/// INPUT: - s - OperationStack pointer
///          o - Opertion pointer
/// OUTPUT: -
Operation* pop(OperationStack* s);


/// DESCRIPTION: checks if a stack is empty or not
/// INPUT: - s - OperationStack pointer
/// OUTPUT: 1 - is empty; 0- otherwise
int isEmpty(OperationStack* s);



/// DESCRIPTION: checks if a stack is empty or not
/// INPUT: - s - OperationStack pointer
/// OUTPUT: 1 - is empty; 0- otherwise
int isFull(OperationStack* s);

