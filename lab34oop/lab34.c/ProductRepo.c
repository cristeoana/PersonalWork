#include "Repo.h"
#include "Product.h"
#include "ProductRepo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>



ProductRepo* createRepo()
{
	ProductRepo* v = (ProductRepo*)malloc(sizeof(ProductRepo));
	v->products = createDynamicRepo(CAPACITY, &deleteProduct);
	return v;
}

///////////////////////////////////////////////////////////////

void destroyRepo(ProductRepo* v)
{
	if (v == NULL)
		return;

	destroy(v->products);
	free(v);
}


///////////////////////////////////////////////////////////////

int findPosOfProduct(ProductRepo* v, char* name)
{
	if (v == NULL)
		return -1;
	for (int i = 0; i < getLength(v->products); i++)
	{
		Product* prod = get(v->products, i);
		if (strcmp(prod->name, name) == 0)
			return i;
	}
	return -1;
}

///////////////////////////////////////////////////////////////


Product* find(ProductRepo* v, char* name)
{
	if (v == NULL)
		return NULL;
	int pos = findPosOfProduct(v, name);
	if (pos == -1)
		return NULL;
	return get(v->products, pos);
}

///////////////////////////////////////////////////////////////


Product* getProductOnPos(ProductRepo* v, int pos)
{
	if (v == NULL)
		return NULL;
	if (pos < 0 || pos >= getLength(v->products))
		return NULL;
	return get(v->products, pos);
}


///////////////////////////////////////////////////////////////

int addProduct(ProductRepo* v, Product* prod)
{
	if (v == NULL || prod == NULL)
		return 0;
	Product* foundProduct = find(v, prod->name);
	if (foundProduct != NULL)
	{
		foundProduct->quantity += prod->quantity;

	}
	else {
		Product* copy = copyProduct(prod);
		add(v->products, copy);
	}
	return 1;
}

///////////////////////////////////////////////////////////////


void deleteProduct(ProductRepo* v, char* name)
{
	if (v == NULL)
		return;
	int pos = findPosOfProduct(v, name);
	if (pos == -1)
		return;

	removeX(v->products, pos);
}

///////////////////////////////////////////////////////////////



void updateProduct(ProductRepo* v, Product* prod, Product* newProd)
{
	int pos = findPosOfProduct(v, prod->name);
	if (pos != -1) {
		v->products->elems[pos] = newProd;
	}
}

///////////////////////////////////////////////////////////////


int getRepoLength(ProductRepo* v)
{
	if (v == NULL)
		return -1;
	return getLength(v->products);
}

/////////////////////////////////////////////////////////////

void printProducts(ProductRepo* v)
{
	int i, length = v->products->length;
	if (length == 0)
		printf("Empty repository!\n");
	else {
		for (i = 0; i < length; i++)
		{
			Product* prod = getProductOnPos(v, i);
			printProduct(prod);
		}
	}
}


/////////////////////////////////////////////////////////////

/*void sortProductsQuant(ProductRepo* v)
{
	int length = v->products->length;
	int i, j;
	for (i = 0; i < length - 1; i++) {
		Product* prod1 = getProductOnPos(v, i);
		for (j = i + 1; j < length; j++) {
			Product* prod2 = getProductOnPos(v, j);
			if (prod1->quantity > prod2->quantity)
				swapProducts(&v->products->elems[i], &v->products->elems[j]);
		}
	}
}*/
void sortProductsName(ProductRepo* v)
{
	int length = v->products->length;
	int i, j;
	for (i = 0; i < length - 1; i++) {
		Product* prod1 = getProductOnPos(v, i);
		for (j = i + 1; j < length; j++) {
			Product* prod2 = getProductOnPos(v, j);
			if (strcmp(prod1->name , prod2->name) <= 0)
				swapProducts(&v->products->elems[i], &v->products->elems[j]);
		}
	}
}


/////////////////////////////////////////////////////////////


void sortProductsMonth(ProductRepo* v)
{
	int length = v->products->length;
	int i, j;
	for (i = 0; i < length - 1; i++) {
		Product* prod1 = getProductOnPos(v, i);
		for (j = i + 1; j < length; j++) {
			Product* prod2 = getProductOnPos(v, j);
			if (prod1->expDate.month > prod2->expDate.month)
				swapProducts(&v->products->elems[i], &v->products->elems[j]);
		}
	}
}