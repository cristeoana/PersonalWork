#include "Repo.h"
#include <stdlib.h>
#include <assert.h>

void removeX(DynamicRepo* arr, int pos)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;

	// deallocate the memory of the element on position pos
	arr->destroyElemFct(arr->elems[pos]);

	for (int i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];

	arr->length--;
}


DynamicRepo* createDynamicRepo(int capacity, DestroyElementFunctionType destroyElemFct)
{
	DynamicRepo* dynRepo = (DynamicRepo*)malloc(sizeof(DynamicRepo));
	// make sure that the space was allocated
	if (dynRepo == NULL)
		return NULL;

	dynRepo->capacity = capacity;
	dynRepo->length = 0;

	// allocate space for the elements
	dynRepo->elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (dynRepo->elems == NULL)
		return NULL;

	// initialize the function pointer
	dynRepo->destroyElemFct = destroyElemFct;

	return dynRepo;
}


void destroy(DynamicRepo* arr)
{
	if (arr == NULL)
		return; // we don not attemp anything if the array is empty

				// deallocate each of the elements
	for (int i = 0; i < arr->length; i++)
		arr->destroyElemFct(arr->elems[i]);

	// free the space allocated for the elements
	free(arr->elems);
	

	// free the space allocated for the dynamic array
	free(arr);
	
}


int resize(DynamicRepo* arr)
{
	if (arr == NULL)
		return;

	arr->capacity *= 2;

	TElement* aux = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));
	if (aux == NULL)
		return 0;
	arr->elems = aux;

	return 1;
}


void add(DynamicRepo* arr, TElement t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	// resize the array, if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length++] = t;
}


int getLength(DynamicRepo* arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}


TElement get(DynamicRepo* arr, int pos)
{
	return arr->elems[pos];
}