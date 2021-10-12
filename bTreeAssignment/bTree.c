#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bTree.h"

bNode *root;
int numNodes;
int recCount = 0;
char **indexArray;

void initTree(){
	root = NULL;
	numNodes = 0;
}

bNode *makeNode(char *data){
	bNode *node = (bNode*)malloc(sizeof(bNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void addNode(char *data){
	bNode *current;
	if (root==NULL){
		root = makeNode(data);
		numNodes++;
	} else {
		current = root;
		while(true){
			if(strcasecmp(data,current->data)<0){
				if(current->left==NULL){
					current->left=makeNode(data);
					numNodes++;
					break;
				} else {
					current = current->left;
				}
			} else {
				if (current->right==NULL){
					current->right=makeNode(data);
					numNodes++;
					break;
				} else {
					current = current->right;
				}
			}
		}
	}
}

void inOrder(bNode *root){
	if (root->left!=NULL) inOrder(root->left);
	indexArray[recCount++] = root->data;
	if (root->right!=NULL) inOrder(root->right);
}

void inReverseOrder(bNode *root){
	if (root->right!=NULL) inReverseOrder(root->right);
	indexArray[recCount++] = root->data;
	if (root->left!=NULL) inReverseOrder(root->left);
}

void postOrder(bNode *root){
	if (root->left!=NULL) postOrder(root->left);
	if (root->right!=NULL) postOrder(root->right);
	indexArray[recCount++] = root->data;
}

char **makeSortIndex(char arg){
	indexArray = (char **)malloc(sizeof(char *)*numNodes);
	if(arg!='d'||arg!='D'){
		inOrder(root);
	} else {
		recCount=0;
		inReverseOrder(root);
	}
	recCount=0;
	return indexArray;
}

int getNumNodes(){
	return numNodes;
}



