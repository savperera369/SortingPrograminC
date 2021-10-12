#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bTree.h"

#define false 0 // Definitions for true and false
#define true !false
#define MAXLEN 50

char* readLine();

int main (int argc, char *argv[]){

	printf("Text Sorting Program: ECSE 202 Assignment 2 \n");
	printf("Enter text to be sorted, line by line. A blank line terminates.\n");
	printf("You can cut and paste text into this window.\n");

	initTree();

	while(true){
		char *input = readLine();
		if(strlen(input)<=1) break;
		addNode(input);
	}

	printf("Enter the character's d or D to sort the text in Reverse Order.\n");
	printf("Enter any other character to sort in Sort Order.\n");
	printf(">>");

	char arg;
	fgets(&arg,1,stdin);
	char** arr = makeSortIndex(arg);
	for (int i=0; i<getNumNodes(); i++){
		printf("%s",arr[i]);
	}
}

char* readLine(){
	char* buffer = (char*)malloc(MAXLEN);
	if(buffer==NULL){
		printf("Can't allocate buffer.\n");
		return NULL;
	}
	fgets(buffer,MAXLEN,stdin);
	return buffer;
}



