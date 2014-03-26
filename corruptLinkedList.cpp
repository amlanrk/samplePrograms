// Program to detect a corrput linked list
// Author: Amlan Chatterjee

#include<stdio.h>

// Structure for Linked List Node
struct Node{
	int value;
	Node* next;
};

// Function to print a linked list
void printLinkedList(Node* head)
{
	while(head->next != 0)
	{
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("%d -> ", head->value);
}

// Function to detect if a linked list is circular
void detectCircularLinkedList(Node* head)
{
	// Declare two node pointers slow and fast
	Node* slow;
	Node* fast;
	// Assign both node pointers to head
	slow = head;
	fast = head;
	
	// Check if there is just a single node
	if(slow->next == 0)
	{
		printf("\nSingle node non-circular linked list\n");
		return;
	}
	
	// Check if there are just two nodes
	if(fast->next->next == 0)
	{
		printf("\nTwo nodes non-circular linked list\n");
		return;
	}
	
	// Move the two pointers and see where they meet
	while(slow->next != 0 && fast->next != 0 && fast->next->next != 0)
	{
		slow = slow->next; 
		fast = fast->next->next;
		
		if(slow == fast)
		{
			printf("\nThe linked list is circular at node value: %d", slow->value);
			return;
		}
	}
	
	printf("\nThe linked list is not circular");
	return;
}

// Function to detect if a linked list is corrupt
void detectCorruptLinkedList(Node* head)
{
	Node* slow;
	Node* fast;
	
	slow = head;
	fast = head;
	
	// Check if there is just a single node
	if(slow->next == 0)
	{
		printf("\nSingle node non-circular linked list\n");
		return;
	}
	
	// Check if there are just two nodes
	if(fast->next->next == 0)
	{
		printf("\nTwo nodes non-circular linked list\n");
		return;
	}
	
	// Move the two pointers and see where they meet
	while(slow->next != 0 && fast->next != 0 && fast->next->next != 0)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			break;
		}
	}
	
	// Check if the loop breaks because end of singly linked list
	if(slow->next == 0 || fast->next ==0 || fast->next->next == 0)
	{
		printf("\nThe linked list is neither circular or corrupt");
		return;
	}
	
	fast = head;
	while(slow->next != fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	printf("\nThe linked list is corrupt at value %d", slow->next->value);
	
	
}

int main()
{
	Node* head = new Node;
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;
	Node* d = new Node;
	Node* e = new Node;
	
	head->value = 10;
	a->value = 20;
	b->value = 30;
	c->value = 40;
	d->value = 50;
	e->value = 60;
	
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = 0;
	
	printLinkedList(head);
	
	// Make the list corrupt
	e->next = a;
	detectCorruptLinkedList(head);
	
	// Make the list circular
	//e->next = head;
	
	//printLinkedList(head);
	//detectCircularLinkedList(head);
	
	
	
}
