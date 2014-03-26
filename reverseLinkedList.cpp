// Program to reverse linked list
// Author: Amlan Chatterjee

#include <stdio.h>
//#include<conio.h>

using namespace std;

// Structure for Linked List
struct Node{
	int value;
	Node* next;
};

// Function to Print Linked List
void printLinkedList(Node* head)
{
	while(head->next != 0)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("%d ", head->value);
}

// Function to Print Linked List in Reverse Order
void printReverseLinkedList(Node* head)
{
	if(head->next != 0)
	{
		// Recursive call
		printReverseLinkedList(head->next);
	}
	printf("%d ", head->value);
}

// Function to Reverse Linked List
Node* reverseLinkedList(Node* head)
{
	Node* prev;
	Node* current;
	prev = head;
	
	// Testing if more than one node exists
	if(head->next != 0)
	{
		head = head->next;
		prev->next = 0;
	}
	else
		return head;
	
	// Do the following when multiple nodes exist	
	while(head->next != 0)
	{
		current = head;
		printf("%d ", head->value);
		head = head->next;
		current->next = prev;
		prev = current;		
	}
	head->next = prev;
	
	return head;
}


// main
int main()
{
	Node* head = new Node;
	Node a, b, c, d;
	Node* e = new Node;
	Node* f = new Node;
	head->value = 10;
	head->next = &a;
	a.value = 20;
	a.next = &b;
	b.value = 30;
	b.next = &c;

	c.value = 40;
	c.next = &d;
	d.value = 50;
	d.next = e;
	
	
	e->next = f;
	e->value = 60;
	f->next = 0;
	f->value = 70;
	
	printf("Original List:\n");
	printLinkedList(head);
	printf("\n\nOriginal List reverse printing:\n");
	printReverseLinkedList(head);
	printf("\n\nOriginal List verification:\n");
	printLinkedList(head);
	printf("\n\nWhile reversing: \n");
	head = reverseLinkedList(head);
	printf("\n\nReversed List:\n");
	printLinkedList(head);
}
