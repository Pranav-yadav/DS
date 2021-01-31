/*
* Program: Stack ADT Implementation using Array
* Author: Pranav Yadav
*
*/
#include<stdlib.h>
#include<stdio.h>
#define size 5
/* size should be pre-defined in source code*/
//Stack of Integers :

int stack[size];
int top = -1;

void push(int val)
{
	if (top == size - 1)
		printf("\nStack is Overflow !!\n");
	else
	{
		top++;
		stack[top] = val;
	}
}

void pop()
{

	if (top == -1)
		printf("\nStack Empty!!\n");
	else
	{
		printf("\nElement removed=%d", stack[top--]);
	}
}

void peep()
{
	int val;
	if (top == -1)
		printf("\nStack is Empty!!\n");
	else
	{
		printf("Element at the top = %d", stack[top]);

	}
}

void display()
{
	int i;
	/*If value of top is -1, it implies
	that stack is either empty or underflow
	*/
	if (top == -1)
		printf("\nStack is Empty!!\n");
	else
	{
		printf("\nStack elements :\n");
		// 'for loop' is used to traverse through the array
		for (i = top; i >= 0; i--)
			printf("%d\t", stack[i]);

	}
}

int main()
{
	int choice;
	int val;
	// 'while loop' and 'switch case' is used for
	// menu driven program for stack ADT
	while (1)
	{
		printf("\n\t\t\tMENU\n");
		printf("——————————————————");
		printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\n");
		printf("——————————————————");
		//choice should be an Integer
		printf("\nEnter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		  //value should be an Integer
			printf("Enter value to push: ");
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
