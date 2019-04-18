#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"


Operation* createOperation(Product* prod, char* operationType, int id)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->product = copyProduct(prod);
	o->idProduct = id;

	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}


//////////////////////////////////////////////////////////////////////////



void destroyOperation(Operation *o)
{
	if (o == NULL)
		return;
	//first destroy the product
	destroyProduct(o->product);
	// free the operationType
	free(o->operationType);
	//free(o->idProduct);
	//free the operation
	free(o);
	
	
}


//////////////////////////////////////////////////////////////////////////


Operation* copyOperation(Operation* o)
{
	if (o == NULL)
		return NULL;

	Operation* newOp = createOperation(o->product, o->operationType, o->idProduct);
	return newOp;
}


//////////////////////////////////////////////////////////////////////////


char* getOperationType(Operation* o)
{
	return o->operationType;
}

//////////////////////////////////////////////////////////////////////////


Product* getProduct(Operation* o)
{
	return o->product;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////     STACK OPERATIONS      /////////////////////////
//////////////////////////////////////////////////////////////////////////


OperationStack* createStack()
{
	OperationStack* s = (OperationStack*)malloc(sizeof(OperationStack));
	s->length = 0;
	return s;
}

//////////////////////////////////////////////////////////////////////////

void destroyStack(OperationStack* s)
{
	if (s == NULL)
		return;
	// deallocate memory operations
	for (int i = 0; i < s->length; i++)
		destroyOperation(s->operations[i]);
	// free the stack
	free(s);
}

//////////////////////////////////////////////////////////////////////////


int isEmpty(OperationStack* s)
{
	return (s->length == 0);
}


int isFull(OperationStack* s)
{
	return (s->length == 100); // we've reached max capacity of stack
}


//////////////////////////////////////////////////////////////////////////


void push(OperationStack* s, Operation* o)
{
	if (isFull(s))
		return;
	s->operations[s->length++] = copyOperation(o); // copies operation

}

//////////////////////////////////////////////////////////////////////////


Operation* pop(OperationStack* s)
{
	if (isEmpty(s))
		return NULL;

	s->length--;
	return s->operations[s->length];
}
