#include <stdio.h>
#include <stdlib.h>

/* 
  this represents an item in the stack, with a 
  data value and a reference to another node 
*/
struct node {
        int data;
        struct node* next;
};

// our top node pointer
struct node* top = 0;

/* 
  adds a node to our stack, by allocating memory 
  for a node, setting its data, setting its next pointer to 
  our top if any, and finally setting it as the new top node 
*/
void push(int p_data) {
  struct node* temp = malloc(sizeof(struct node));
  temp->data = p_data;
  temp->next = top ? top : 0;

  top = temp;
}

/* 
  removes a node from our stack, by checking if 
  the top pointer is non-null, setting the top node to 
  its next node, and of course freeing the memory 
*/
void pop() {
  if (top) {
    struct node* temp = top;
    top = top->next;
    free(temp);
  }
}

/* 
  simply shows the every node's address, data 
  and next node's address 
*/
void show() {
  struct node* temp = top;
  printf("top -> %p\n", temp);
  if (top)
    do printf("%p:[%03i|%p]\n", temp, temp->data, temp->next);
    while ( (temp = temp->next) );
  printf("\n");
}

/* basic UI for the application */
void printMenu() {
  printf("Main menu:\n\n");

  printf("[0] Exit\n");
  printf("[1] Push\n");
  printf("[2] Pop\n\n");

  printf("Enter your choice: ");
}


/* starts an input loop to push or pop element from the stack */
int main() {
  system("clear");
  printf("Hello! Welcome to the stack experiment!\n");
  printMenu();

  int res = 1;
  int add = 0;
  while (scanf("%d", &res) && res) {
    switch (res) {
      case 1:
        printf("Value to add: ");
        if (scanf("%d", &add))
          push(add);
        break;
      case 2:
        pop();
        break;
    }
    system("clear");
    show();
    printf("\n");
    printMenu();
  }

  printf("K thanks bye\n");
  return 0;
}
