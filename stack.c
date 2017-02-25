#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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

int main() {
	push(5); push(4);
	for (int i = 0; i < 5; i++)
		push(i);
  system("clear");
	show();
  printf("Hello! Welcome to the stack experiment!\n");
  printMenu();

  int res = 1;
  int arg = 0;
  while (scanf("%d", &res) && res) {
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
    system("clear");
    show();
    printMenu();
  }

  printf("K thanks bye\n");
	return 0;
}

void push(int p_data) {
  struct node* temp = malloc(sizeof(struct node));
  temp->data = p_data;
  temp->next = top ? top : 0;

	top = temp;
}

void pop() {
  if (top) {
    struct node* temp = top;
    top = top->next;
    free(temp);
  }
}

int count() {
	struct node* temp = top;
	int cnt = 0;
	if (temp)
		do cnt++;
		while ( (temp = temp->next) );
	return cnt;
}

void clear() {
	struct node* temp = top;
	if (temp)
		do pop();
		while ( (temp = temp->next) );
}

int seek(int n) {
	struct node* temp = top;
	if (!temp) 
		return -1;

	if (n >= count() || n < 0)
		return -1;
		
	int cnt = 0;
	while ( cnt++ < n )
		temp = temp->next;

	return temp->data;
}

int find(int value) {
	struct node* temp = top;
	int cnt = 0;
	if (temp)
		do if (temp->data == value)
			return cnt;
		while ( ++cnt && ( temp = temp->next) );

	return -1;
}

int findLast(int value) {
	struct node* temp = top;
	int cnt = 0, pos = -1;
	if (temp)
		do if (temp->data == value)
			pos = cnt;
		while ( ++cnt && ( temp = temp->next) );

	return pos;
}
