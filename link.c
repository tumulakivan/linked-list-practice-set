#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "link.h"

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *currNode = head;
    while (currNode != NULL)
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

void displayReverse(node *head)
{
}

int count(node *head)
{
    int ctr = 0;
    node *currNode = head;
    while (currNode != NULL)
    {
        ctr++;
        currNode = currNode->next;
    }

    return ctr;
}

int sum(node *head)
{
    int sum = 0;
    node *currNode = head;
    while (currNode != NULL)
    {
        sum += currNode->data;
        currNode = currNode->next;
    }

    return sum;
}

int product(node *head)
{
    int product = 1;
    node *currNode = head;

    if (currNode == NULL)
        return 0;

    while (currNode != NULL)
    {
        product *= currNode->data;
        currNode = currNode->next;
    }

    return product;
}

bool search(node *head, int num)
{
    node *currNode = head;
    while (currNode != NULL)
    {
        if (currNode->data == num)
            return true;
        currNode = currNode->next;
    }

    return false;
}

node *insertEnd(node *head, int num)
{
    node *newNode, *currNode;
    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Malloc failed\n");
        return head;
    }
    newNode->data = num;

    if (head == NULL)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    currNode = head;
    while (currNode->next != NULL)
        currNode = currNode->next;
    newNode->next = currNode->next;
    currNode->next = newNode;

    return head;
}

node *insertFront(node *head, int num)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Malloc failed\n");
        return head;
    }

    if (head == NULL)
        insertEnd(head, num);

    newNode->data = num;
    newNode->next = head;
    head = newNode;
    return head;
}

node *insertBeforeNode(node *head, int num, int pos)
{
    node *newNode, *currNode;
    int spot = 1;
    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Malloc failed\n");
        return head;
    }

    currNode = head;
    while (spot < pos)
    {
        spot++;
        if (spot == pos)
            break;
        currNode = currNode->next;
    }
    newNode->data = num;
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}

node *insertAfterNode(node *head, int num, int pos)
{
    node *newNode, *currNode;
    int spot = 1;
    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Malloc failed\n");
        return head;
    }

    currNode = head;
    while (spot < pos)
    {
        spot++;
        currNode = currNode->next;
    }
    newNode->data = num;
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}

node *deleteFront(node *head){	
	node *tempNode;
	
	if(tempNode == NULL)
	{
		fprintf(stderr, "Nothing to delete.\n");
		return head;	
	}

	tempNode = head;
	head = head->next;
	free(tempNode);
	return head;	
}
node *deleteEnd(node *head)
{
	node *tempNode, *currNode;
	
	if(head == NULL)
	{
		fprintf(stderr, "Nothing to delete.\n");
		return head;
	}
	
	currNode = head;
	
	while(currNode->next->next != NULL)
		currNode = currNode->next;
	
	tempNode = currNode->next;
	currNode->next = NULL;
	free(tempNode);
	return head;
}


int getPos(node *head, int num)
{
    int pos = 1;
    node *currNode = head;
    while (currNode->data != num)
    {
        pos++;
        currNode = currNode->next;
    }

    return pos;
}
