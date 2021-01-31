/*
* Program: Stack ADT Implementation using Single Linked List (SLL)
* Author: Pranav Yadav
*/
#include<stdio.h>
#include<stdlib.h>
//Stack of Integers

typedef struct node
{
	int data;
	struct node *next;
} node;

node *start = NULL;
node *top = NULL;

void push(int val)
{
	node *ptr;
	node *newnode = (node *) malloc(sizeof(node));
	newnode->data = val;
	newnode->next = NULL;
	if (start == NULL)
	{
		start = newnode;
		top = newnode;
	}
	else
	{
		ptr = start;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
	}
	top = newnode;
	newnode->next = NULL;
}

void pop()
{
	node *ptr;
	if (start == NULL)
	{
		printf("\nNothing to Delete : Stack is Empty !!\n\n");
	}
	else
	{
		if (top == start)
		{
			printf("\n '%d' is Popped\n", top->data);
			free(top);
			start = NULL;
		}
		else
		{
			ptr = start;
			while (ptr->next->next != NULL)
			{
				ptr = ptr->next;
			}
			printf("\n %d is Popped\n", top->data);
			free(top);
			top = ptr;
			ptr->next = NULL;
		}
	}
}

void peep()
{
	if (start == NULL)
	{
		printf("\nStack is Empty !!\n\n");
	}
	else
	{
		printf("\n Element at the Top = %d\n", top->data);
	}
}

void display()
{
	node *ptr;
	/*If value of top is 'NULL', it implies
	that stack is either empty or underflow
	*/
	if (start == NULL)
	{
		printf("\nStack is Empty !!!\n");
	}
	else
	{
		ptr = start;
		printf("\nStack Elements : \n");
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

int main()
{
	int choice, val;
	// 'while loop' and 'switch case' is used for
	// menu driven program for stack ADT
	while (1)
	{
		printf("\n\t\tMENU\n");
		printf("——————————————————");
		printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\n");
		printf("——————————————————");
		printf("\nEnter your choice : ");
		//choice must be an Integer
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter integer value to push: ");
			//value must be an Integer
			scanf("%d", &val);
			push(val);
			break;
		case 2:
			pop();
			break;
		case 3:
			peep();
			break;
		case 4:
			display();
			break;
		case 5:
			// exit(0) is used to exit the program with exit code 0
			// i.e., in turn breaks the loop
			exit(0);
		default:
			printf("Enter a valid choice!!\n");
		}
	}

	return 0;
}
