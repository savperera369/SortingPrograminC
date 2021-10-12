#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef BTREE_H_
#define BTREE_H_

#define false 0 // Definitions for true and false
#define true !false

typedef struct bN {
	char *data; // Pointer string
	struct bN *left; // Left Successor
	struct bN *right; // Right Successor
} bNode;

void initTree(); // Initialize the bTree
void addNode(char *data); // adds a node to the bTree
bNode *makeNode(char *data); // Function that allocates a bNode
char **makeSortIndex(char arg); // returns an array of pointers to strings in sort order
void inOrder(bNode *root); // The recursive function that performs inorder traversal
void inReverseOrder(bNode *root); // same as InOrder with direction of recursion reversed
void deleteTree(); // Deletes the bTree (all allocated nodes)
void postOrder(bNode *root); // Post Order Traversal used to delete tree nodes
int getNumNodes(); // getter returns number of nodes in bTree

#endif /* BTREE_H_ */
