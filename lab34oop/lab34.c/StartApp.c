#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include "UI.h"
#include <stdlib.h>
#include <Windows.h>
#include <crtdbg.h>

int main() {

	ProductRepo* r = createRepo();
	OperationStack* s = createStack();
	OperationStack* rs = createStack();
	Controller* ctrl = createController(r, s, rs);
	initializeController(ctrl);
	UI* ui = createUI(ctrl);
	startUI(ui);
	system("pause");
	
	destroyController(ctrl);
	
	return 0;
}