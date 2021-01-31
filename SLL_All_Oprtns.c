/* 
 * Program: Singly Linked List all Operations Implementation
 * Author: Pranav Yadav
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node * next;
}
node;

struct node * start = NULL;

void insert_beg() {
	node * newnode = (struct node * ) malloc(sizeof(node));
	printf("\nEnter data : ");
	scanf("%d", & newnode -> data);
	printf("\n %d inserted at begining\n", newnode -> data);
	newnode -> next = start;
	start = newnode;
}

void insert_end() {
	node * ptr;
	node * newnode = (node * ) malloc(sizeof(node));
	printf("\nEnter data : ");
	scanf("%d", & newnode -> data);
	newnode -> next = NULL;
	if (start == NULL) {
		start = newnode;
	} else {
		ptr = start;
		while (ptr -> next != NULL) {
			ptr = ptr -> next;
		}
		ptr -> next = newnode;
	}
	newnode -> next = NULL;
}

void insert_after() {
	if (start == NULL) {
		printf("\nCan't Insert : List is Empty !!\n\n");
	} else {
		node * ptr;
		int val;
		node * newnode = (node * ) malloc(sizeof(node));

		printf("\nEnter data : ");
		scanf("%d", & newnode -> data);
		newnode -> next = NULL;
		printf("\nEnter node after which newnode is to be inserted : ");
		scanf("%d", & val);

		ptr = start;
		while (ptr != NULL && ptr -> data != val) {
			ptr = ptr -> next;
		}
		if (ptr == NULL) {
			printf("\nCan't Insert : Node not found !!\n\n");
		} else {
			printf("\n%d Inserted after %d\n\n", newnode -> data, val);
			newnode -> next = ptr -> next;
			ptr -> next = newnode;
		}
	}
}

void insert_before() {
	if (start == NULL) {
		printf("\nCan't Insert : List is Empty !!\n\n");
	} else {
		node * preptr, * ptr;
		int val;
		node * newnode = (node * ) malloc(sizeof(node));
		printf("\nEnter data : ");
		scanf("%d", & newnode -> data);
		newnode -> next = NULL;
		printf("\nEnter node before which newnode is to be inserted : ");
		scanf("%d", & val);

		preptr = start;
		ptr = start;
		while (ptr != NULL && ptr -> data != val) {
			preptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr == NULL) {
			printf("\nCan't Insert : Value not found !!\n\n");
		} else {
			newnode -> next = ptr;
			if (preptr == ptr) {
				start = newnode;
			} else {
				preptr -> next = newnode;
			}
		}
	}
}

void insert_at() {
	if (start == NULL) {
		printf("\nCan't Insert : List is Empty !!\n\n");
	} else {
		int count = 1, pos;
		node * ptr;
		node * newnode = (node * ) malloc(sizeof(node));

		printf("\nEnter data : ");
		scanf("%d", & newnode -> data);
		newnode -> next = NULL;

		printf("\nEnter Position at which newnode is to be inserted : ");
		scanf("%d", & pos);
		ptr = start;

		while (count<pos - 1 && ptr != NULL) {
			ptr = ptr -> next;
			count++;
		}
		if (ptr == NULL) {
			printf("\nCan't Insert : Reached End of the List !!\n\n");
		} else {
			printf("\n%d is Inserted at %d Position\n\n", newnode -> data, pos);
			newnode -> next = ptr -> next;
			ptr -> next = newnode;
		}
	}
}

void delete_beg() {
	if (start == NULL) {
		printf("\nCan't Delete : List is Empty !!\n\n");
	} else {
		node * ptr;
		ptr = start;
		start = ptr -> next;
		free(ptr);
	}
}

void delete_end() {
	node * ptr;
	if (start == NULL) {
		printf("\nCan't Delete : List is Empty !!\n\n");
	} else {
		if (start -> next == NULL) {
			ptr = start;
			start = NULL;
			free(ptr);
		} else {
			ptr = start;
			while (ptr -> next -> next != NULL) {
				ptr = ptr -> next;
			}
			free(ptr -> next);
			ptr -> next = NULL;
		}
	}
}

void delete_after() {
	if (start == NULL) {
		printf("\nCan't Delete : List is Empty !!\n\n");
	} else {
		node * preptr, * ptr;
		int val;
		printf("\nEnter value after which; node is to be deleted : ");
		scanf("%d", & val);
		preptr = start;
		ptr = start;

		while (ptr != NULL && ptr -> data != val) {
			preptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr == NULL) {
			printf("\nCan't Delete : Value Not Found ,Reached End Of The List !!\n\n");
		} else {
			if (ptr -> next == NULL) {
				printf("\n %d is the last node : No node exists after it !!\n\n", val);
			} else {
				preptr = ptr;
				ptr = ptr -> next;
				preptr -> next = ptr -> next;
				free(ptr);
			}
		}
	}
}

void delete_before() {
	if (start == NULL) {
		printf("\nCan't Delete : List is Empty !!\n\n");
	} else {
		node * preptr, * ptr;
		int val;
		printf("\nEnter value before which; node is to be deleted : ");
		scanf("%d", & val);
		preptr = start;
		ptr = start;
		if (val == ptr -> data) {
			printf("\n Can't delete: %d is the first node, No node exists before it !!\n\n", val);
		} else if (val == ptr -> next -> data) {
			start = start -> next;
			free(ptr);
		} else {
			while (ptr != NULL && ptr -> next -> data != val) {
				preptr = ptr;
				ptr = ptr -> next;
			}
			if (ptr == NULL) {
				printf("\nCan't Delete : Value not found !!\n\n");
			} else {
				if (ptr -> data == val) {
					printf("\nCan't Delete : This is the first node; no value exist before it !!\n\n");
				} else {
					while (ptr -> next != NULL && (ptr -> next) -> data != val) {
						preptr = ptr;
						ptr = ptr -> next;
					}
					if (ptr -> next == NULL) {
						printf("\n Can't Delete : Value Not Found !!\n\n");
					} else {
						printf("\n%d is deleted; which is before %d\n\n", ptr -> data, ptr -> next -> data);
						preptr -> next = ptr -> next;
						free(ptr);
					}
				}
			}
		}
	}
}

void delete_at() {
	int count = 1, pos;
	node * preptr, * ptr;
	printf("\nEnter Position at which node is to be deleted : ");
	scanf("%d", & pos);
	if (start == NULL) {
		printf("\nCan't Delete : List is Empty !!\n\n");
	} else if (pos == 1) {
		preptr = start;
		start = start -> next;
		free(preptr);
	} else {
		preptr = start;
		ptr = start;
		while (count<pos && ptr != NULL) {
			count++;
			preptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr == NULL) {
			printf("\nCan't Delete : Reached End of the List !!\n\n");
		} else {
			if (ptr -> next == NULL) {
				printf("\n%d is Deleted at %d Position\n\n", ptr -> data, pos);
				preptr -> next = NULL;
				free(ptr);
			} else {
				printf("\n%d is Deleted at %d Position\n\n", ptr -> data, pos);
				preptr -> next = ptr -> next;
				free(ptr);
			}
		}
	}
}

node * search(int val) {
	node * ptr;
	int count = 1;
	if (start == NULL) {
		printf("\nList is Empty !!\n\n");
	} else {
		ptr = start;
		while (ptr != NULL && ptr -> data != val) {
			ptr = ptr -> next;
			count++;
		}
		if (ptr == NULL) {
			printf("\nValue Not Found !!\n\n");
			return NULL;
		} else {
			printf("\n %d, Found at position %d in the list\n", val, count);
			return ptr;
		}
	}
}

void replace() {
	int val;
	node * p;
	if (start == NULL) {
		printf("\nList is Empty !!\n\n");
	} else {
		printf("Enter value of node to be replaced : ");
		scanf("%d", & val);
		p = search(val);

		if (p != NULL) {
			printf("Enter new value : ");
			scanf("%d", & p -> data);
		}
	}
}

void display() {
	node * ptr;
	if (start == NULL) {
		printf("\nList is Empty !!!\n\n");
	} else {
		ptr = start;
		printf("\n\tList : \n");
		while (ptr != NULL) {
			printf("%d\t", ptr -> data);
			ptr = ptr -> next;
		}
		printf("\n\n");
	}
}

int main() {
	int ch, val;

	while (1) {
		printf("\t\tMenu : \n");
		printf("——————————————————————————————\n");
		printf("1. Insert at Begining\n2. Insert at End\n3. Insert At\n4. Insert Before\n5. Insert After\n6. Delete from beginning\n7. Delete from the End\n8. Delete at\n9. Delete before\n10. Delete after\n11. Search for a node\n12. Replace value of a node\n13. Display List\n14. Quit\n");
		printf("——————————————————————————————\n");
		printf(" Enter Your Choice : ");
		scanf("%d", & ch);

		switch (ch) {
			case 1:
				insert_beg();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_at();
				break;
			case 4:
				insert_before();
				break;
			case 5:
				insert_after();
				break;
			case 6:
				delete_beg();
				break;
			case 7:
				delete_end();
				break;
			case 8:
				delete_at();
				break;
			case 9:
				delete_before();
				break;
			case 10:
				delete_after();
				break;
			case 11:
				if (start == NULL) {
					printf("\nList is Empty !!\n\n");
					break;
				} else {
					printf("Enter node value to search : ");
					scanf("%d", & val);
					search(val);
					break;
				}
			case 12:
				replace();
				break;
			case 13:
				display();
				break;
			case 14:
				exit(0);
			default:
				printf("\nInvalid Input !!!\n\n");

		}
	}

	return 0;
}
