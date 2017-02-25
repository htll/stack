#ifndef H_STACK
#define H_STACK

extern struct node* top;

struct node {
	int data;
	struct node* next;
};

// removes the top element from the stack
void pop();

// add an element on top of the stack
void push(int p_data);

#endif
