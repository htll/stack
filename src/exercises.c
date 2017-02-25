#include <stdio.h>
#include <stdlib.h>

#include "../headers/stack.h"

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
