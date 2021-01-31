/*
* Program: Singly Linked List Implementation
* Author: Pranav Yadav
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;	
}node;

struct node * start = NULL;

void insert() {
	// insert() is used to insert an element in a list
	node * ptr;
	node * newnode = (node *)malloc(sizeof(node));
	
	printf("\nEnter data : ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	
	if(start == NULL) {
		start = newnode;
	}
	else {
		ptr = start;
		while(ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newnode;
	}	
	newnode->next = NULL;
}

void delete() {
	// delete() is used to delete an element from list
	node *ptr;
	
	if (start == NULL) {
		printf("\nCan't Delete : List is Empty !!\n\n");
	}
	else {
		if (start->next == NULL) {
			ptr = start;
			start = NULL;
			free(ptr);
		}
		else {
			ptr = start;
			while (ptr->next->next != NULL) {
				ptr = ptr->next;
			}
			free(ptr->next);
			ptr->next = NULL;
		}
	}
}

void display() {
	// display() is used to display all elements of a list
	node *ptr;
	
	if(start == NULL) {
		printf("\nList is Empty !!!\n\n");
	}
	else {
		ptr = start;
		printf("\n\tList : \n");
		while(ptr != NULL) {
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		printf("\n\n");
	}
}

int main() {
	int ch;
	
	while(1) {
		printf("\tMenu : \n");
		printf("———————————————\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Quit\n");
		printf("———————————————\n");
		printf(" Enter Your Choice : ");
		scanf("%d",&ch);
		
		switch(ch) {
			case 1: insert();break;
			case 2: delete();break;
			case 3: display();break;
			case 4: exit(0);
			default : printf("\nInvalid Input !!!\n\n");
		}
	}
    
	return 0;
}
