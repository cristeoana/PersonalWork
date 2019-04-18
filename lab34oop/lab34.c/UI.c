#include "UI.h"
#include "Date.h"
#include <stdio.h>
#include <stdlib.h>


UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}
//////////////////////////////////////////////////////////////

void destroyUI(UI* ui)
{
	//first destroy the controller
	destroyController(ui->ctrl);
	//free the UI memory
	free(ui);
}

//////////////////////////////////////////////////////////////


void printMenu()
{
	///printf("\n**********************************************************\n");
	printf("              INTELLIGENT REFRIGERATOR\n");
	printf("\n**********************************************************\n\n");
	printf("1 - Add a product.\n");
	printf("2 - Remove a product.\n");
	printf("3 - Update a product.\n");
	printf("4 - Show products.\n");
	printf("5 - Lab 3 activity.\n");
	printf("6 - Lab 4 activity.\n");
	printf("7 - Undo.\n");
	printf("8 - Redo.\n");
	printf("0 - Exit.\n");
	///printf("\**********************************************************\n\n");

}


//////////////////////////////////////////////////////////////


int validCommand(int command)
{
	if (command >= 0 && command <= 8)
		return 1;
	return 0;
}


//////////////////////////////////////////////////////////////


int readIntegerNumber()
{
	printf("Input the command:");
	int res;
	scanf("%d", &res);
	return res;
}

//////////////////////////////////////////////////////////////


void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	int size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

//////////////////////////////////////////////////////////////

void addProductUI(UI* ui)
{
	char name[50], category[50];
	int quantity;
	Date exp;
	fgetc(stdin);
	readStringWithSpaces("Give the name: ", 50, name);
	readStringWithSpaces("Give the category: ", 50, category);
	printf("Give the quantity: ");
	scanf("%d", &quantity);
	printf("Give the expiration date: \n");
	printf("day = ");
	scanf("%d", &exp.day);
	printf("month = ");
	scanf("%d", &exp.month);
	printf("year = ");
	scanf("%d", &exp.year);
	addProductController(ui->ctrl, name, category, quantity, exp);

}

//////////////////////////////////////////////////////////////


void startUI(UI* ui)
{
	printMenu();
	while (1)
	{
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command\n");
			command = readIntegerNumber("Input command: ");
		}

		if (command == 0)
		{
			printf("Exit");
			break;
		}
		switch (command)
		{
		case 1:
		{
			addProductUI(ui);
			printf("Product successfully added.\n");

			break;
		}

		case 2:
		{	char name[50];
		fgetc(stdin);
		readStringWithSpaces("Please input the name: ", 50, name);
		removeProductController(ui->ctrl, name);
		break;

		}
		case 3:
		{
			printf("Enter data for new product:\n");
			char name[50], category[50];
			int quantity;
			Date exp;
			Product* prod;
			fgetc(stdin);
			readStringWithSpaces("Give the name: ", 50, name);
			readStringWithSpaces("Give the category: ", 50, category);
			printf("Give the quantity: ");
			scanf("%d", &quantity);
			printf("Give the expiration date: \n");
			printf("day = ");
			scanf("%d", &exp.day);
			printf("month = ");
			scanf("%d", &exp.month);
			printf("year = ");
			scanf("%d", &exp.year);
			if (validateDate(exp) == 1)
			{
				prod = createProduct(name, category, quantity, exp);
				printf("Give position:");
				int pos;
				scanf("%d", &pos);
				Product* init = getProductOnPos(ui->ctrl->repo, pos);
				updateProductController(ui->ctrl, init, prod);

			}
			break;
		}
		case 4:
		{
			printProducts(ui->ctrl->repo);
			break;
		}
		case 5:
		{

			char category[50];
			fgetc(stdin);
			readStringWithSpaces("Give the category: ", 50, category);

			ProductRepo* prodRepo = createRepo();
			prodRepo = displayProductsForCategory(ui->ctrl, category);
			if (prodRepo != NULL)
			{
				sortProductsName(prodRepo);
				printProducts(prodRepo);
			}
			break;
		}
		case 6:
		{
			char category[50];
			fgetc(stdin);
			readStringWithSpaces("Give the category: ", 50, category);

			ProductRepo* prodRepo = createRepo();
			prodRepo = displayProductsForCategory(ui->ctrl, category);
			if (prodRepo != NULL)
			{
				sortProductsMonth(prodRepo);
				printProducts(prodRepo);
			}
			break;
		}

		case 7:
		{
			if (!isEmpty(ui->ctrl->undoStack))
			{
				int checkUndo = undo(ui->ctrl);
				printProducts(ui->ctrl->repo);
			}
			break;
		}
		case 8:
		{
			if (!isEmpty(ui->ctrl->redoStack))
			{
				int checkRedo = redo(ui->ctrl);
				printProducts(ui->ctrl->repo);
			}
			break;
		}
		}
	}
}