#include <stdio.h>
#include <stdlib.h>

#include "../headers/stack.h"
#include "../headers/ui.h"

int main() {
	top = 0;

	push(5); push(4);
	for (int i = 0; i < 5; i++)
		push(i);

	show();
	printMenu();

	int res = 1;
	while (scanf("%d", &res) && res) {
		processInput(res);
		show();
		printMenu();
	}

	printf("K thanks bye\n");
	return 0;
}
