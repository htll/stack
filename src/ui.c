#include <stdio.h>
#include <stdlib.h>

#include "../headers/stack.h"
#include "../headers/exercises.h"

void printMenu() {
	printf("Main menu:\n\n");

	printf("[0] Exit\n");
	printf("[1] Push\n");
	printf("[2] Pop\n");
	printf("[3] Clear\n");
	printf("[4] Seek\n");
	printf("[5] Find\n");
	printf("[6] Find Last\n\n");

	printf("Enter your choice: ");
}

void show() {
	system("clear");

	struct node* temp = top;
	printf("top -> %p\nStack has %i nodes\n", (void *)temp, count());
	if (top)
		do printf("%p:[%03i|%p]\n", (void *)temp, temp->data, (void *)temp->next);
		while ( (temp = temp->next) );
	printf("\n");
}

void wait() {
	printf("Press [ENTER] to continue\n");
	while (getchar() != '\n');
	getchar();
}

void processInput(int res) {
	int arg = 0;
	switch (res) {
		case 1:
			printf("Value to add: ");
			if (scanf("%d", &arg))
				push(arg);
			break;
		case 2:
			pop();
			break;
		case 3:
			clear();
			break;
		case 4:
			printf("Position to seek: ");
			if (scanf("%d", &arg)) {
				int val = seek(arg);
				printf("Value of element %d is %i\n", arg, val);
				wait();
			}
			break;
		case 5:
			printf("Value to find: ");
			if (scanf("%d", &arg)) {
				int val = find(arg);
				printf("Position of element with value %d is %i\n", arg, val);
				wait();
			}
		case 6:
			printf("value to find: ");
			if (scanf("%d", &arg)) {
				int val = findLast(arg);
				printf("Position of last element with value %d is %i\n", arg, val);
				wait();
			}
	}
}
