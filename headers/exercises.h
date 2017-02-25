#ifndef H_EXERCISES
#define H_EXERCISES

// returns the number of nodes in the stack
int count();

// pop all nodes from the stack
void clear();

// returns the data of the nth node (0-indexed)
int seek(int n);

// returns the position (0-indexed) of the first node that 
// has the given value as data
int find(int value);

// returns the position (0-indexed) of the last node that 
// has the given value as data
int findLast(int value);

// returns the average of the values in the stack
float avg();

// returns the median of the values in the stack
float median();

// moves items in the stack so that a stack such as [a][c][d] becomes [d][a][c]
void rotate();

// moves items in the stack so that a stack such as [a][c][d] becomes [d][c][a]
void reverse();

#endif
