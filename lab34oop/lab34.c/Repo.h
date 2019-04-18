#pragma once
#define CAPACITY 20
#define cst 10

typedef void* TElement;
typedef void(*DestroyElementFunctionType)(void*);

typedef struct
{
	TElement* elems;
	int length;			// actual length of the array
	int capacity;		// maximum capacity of the array
	DestroyElementFunctionType destroyElemFct; // function pointer to the function responsible with deallocating the elements stored in the array
} DynamicRepo;


/// DESCRIPTION: removes a generic element from the dynamic repo
/// INPUT: arr = the dynamic repo to be modified
///        pos = the position of the element to be removed
///        pos>=0 and pos <arr.length
/// OUTPUT:  - 
void removeX(DynamicRepo* arr, int pos);



/// DESCRIPTION: creates an array of generic values, with a given capacity
/// INPUT: capacity = integer, positive, non-zero numerical value
///        destroyElemFct = function pointer, of type DestroyElementFunctionType; deals with deallocation of memory
/// OUTPUT:  A pointer which is the dynamically allocated repo;
DynamicRepo* createDynamicRepo(int capacity, DestroyElementFunctionType destroyElemFct);



/// DESCRIPTION: destroys the dynamic repo
/// INPUT: arr = the dynamic vector to be destroyed
/// OUTPUT:  -
void destroy(DynamicRepo* arr);



/// DESCRIPTION: adds a generic element to the dynamic repo
/// INPUT: arr = the dynamic repo to be modified
///        t   = the generic element
/// OUTPUT:  - 
void add(DynamicRepo* arr, TElement t);



/// DESCRIPTION: resizes the array, allocating more space
///              by default, twice as much space is allocated
/// INPUT: arr = the dynamic repo 
/// OUTPUT: if no more memory can be allocated, function returns 0
///         returns 1 otherwise
int resize(DynamicRepo* arr);



/// DESCRIPTION: retrieves the actual size of the dynamic repo
/// INPUT: arr = the dynamic repo
/// OUTPUT:  the arr length, if arr!=NULL
///          or -1 if arr == NULL
int getLength(DynamicRepo* arr);



/// DESCRIPTION: returns the element on a given position
/// INPUT: arr = the dynamic repo
///        pos = a valid position in the repo array
/// OUTPUT:  the element on the given position
TElement get(DynamicRepo* arr, int pos);
