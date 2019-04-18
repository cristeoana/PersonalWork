#pragma once

#include "Controller.h"

typedef struct
{
	Controller* ctrl;
}UI;


/// DESCRIPTION: creates a new UI
/// INPUT: c - Controller type
/// OUTPUT:  pointer to UI struct
UI* createUI(Controller* c);


/// DESCRIPTION: destroys UI
/// INPUT: pointer to UI
/// OUTPUT:  -
void destroyUI(UI* ui);


/// DESCRIPTION: displays the menu and other UI functionalities
/// INPUT: pointer to UI
/// OUTPUT:  -
void startUI(UI* ui);



/// DESCRIPTION: checks if a certain command is valid or not
/// INPUT: command - integer value
/// OUTPUT:  1: is valid,  0: otherwise
int validCommand(int command);



/// DESCRIPTION: reads a number until a valid one is introduced
/// INPUT: message - message to be displayed when asking user for input
/// OUTPUT: returns a number
int readIntegerNumber(const char* message);




/// DESCRIPTION: reads data and adds material in controller
/// INPUT: ui - given user interface
/// OUTPUT: returns 1 if correctly added; 0- otherwise
void addProductUI(UI* ui);