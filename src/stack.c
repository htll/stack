#include <stdio.h>
#include <stdlib.h>

#include "../headers/stack.h"

struct node* top = 0;

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
