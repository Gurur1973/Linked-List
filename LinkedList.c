#include "stdio.h"
#include "stdlib.h"

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s
{
	LINKED_LIST_NODE next;
	int data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s
{
	LINKED_LIST_NODE head; 
} LINKED_LIST_t[1], *LINKED_LIST;

LINKED_LIST_NODE newNode(int data)
{
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	node->next = NULL;
	node->data = data;
	return node;
}

LINKED_LIST newList() // Creating new list with first node null
{
	LINKED_LIST list = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));
	list->head = NULL;
	return list;
}

void addLast(LINKED_LIST list, LINKED_LIST_NODE node) // Insert the given node to the end of the given list
{
	LINKED_LIST_NODE root = list->head;
	if (root == NULL)
	{
		list->head = node;
		list->head->next = NULL;
	}
	else
	{
		while (root->next != NULL)
		{
			root = root->next;
		}
		root->next = node;
		node->next = NULL;
	}
}

void addFirst(LINKED_LIST list, LINKED_LIST_NODE node)
{
	LINKED_LIST_NODE root = list->head;
	if (root == NULL)
	{
		list->head = node;
	}
	else
	{
		node->next = root;
		list->head = node;
	}
}

void removeNode(LINKED_LIST list, int value) // Depends on the location ( first, between, last ) remove the node from list
{
	LINKED_LIST_NODE root = list->head;

	if (root->data == value)
	{
		list->head = list->head->next;
		free(root);
	}

	else
	{
		while (root->next->next != NULL)
			root = root->next;
		if (root->next->data == value) // last element is value
			root->next = NULL;

		else
		{
			root = list->head;
			while (root->next->next != NULL && root->next->data != value)
				root = root->next;

			if (root->next->data == value)
			{
				LINKED_LIST_NODE tmp = root->next;
				root->next = root->next->next;
				free(tmp);
			}
		}
	}
}

void printList(LINKED_LIST list) // Print the given list
{
	LINKED_LIST_NODE root = list->head;

	while (root != NULL)
	{
		printf("%d ", root->data);

		root = root->next;
	}
}




int main()
{
	LINKED_LIST list = newList(); // Create a list
	
	addFirst(list,newNode(10)); 
	addFirst(list,newNode(20));
	addFirst(list,newNode(30));
	addFirst(list,newNode(40));
	addFirst(list,newNode(50));		// Give the list and node as parameters to add
	addLast(list,newNode(1)); 
	addLast(list,newNode(2));
	addLast(list,newNode(3));
	addLast(list,newNode(4));
	addLast(list,newNode(5));


	printf("Initial list : \n");
	printList(list);

	removeNode(list,50); // first element
	removeNode(list,2); // middle element         Give the list and node as parameters to remove node
	removeNode(list,5); // last element

	printf("\nDeleted list : \n");
	printList(list);

	


    return 0;
}

