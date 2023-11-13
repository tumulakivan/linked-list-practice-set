#ifndef LINK_H_
#define LINK_H_

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *head);
void displayReverse(node *head);
int count(node *head);
int sum(node *head);
int product(node *head);
bool search(node *head, int num);
node *insertEnd(node *head, int num);
node *insertFront(node *head, int num);
node *insertBeforeNode(node *head, int num, int pos);
node *insertAfterNode(node *head, int num, int pos);
int getPos(node *head, int num);

#endif