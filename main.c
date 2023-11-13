#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "link.h"

int main(int argc, char **argv)
{
    node *head = NULL;
    int choice, data, flag;

    while (1)
    {
        printf("1.) Display\n");
        printf("2.) Display in reverse order\n");
        printf("3.) Show number of nodes\n");
        printf("4.) Sum of all nodes\n");
        printf("5.) Product of all nodes\n");
        printf("6.) Search if a node exists\n");
        printf("7.) Insert a node at the end of the list\n");
        printf("8.) insert a node at the beginning of the list\n");
        printf("9.) Insert a node before a specified node\n");
        printf("10.) Insert a node after a specified node\n");
        printf("11.) Get position of specified data\n");
        printf("0.) Exit the program\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            system("cls");
            printf("Exiting...");
            return 1;
            break;
        case 1:
            system("cls");
            printf("Linked list:\n");
            display(head);
            break;
        case 3:
            system("cls");
            if (count(head) == 1)
            {
                printf("%d node present\n", count(head));
                break;
            }
            printf("%d nodes present\n", count(head));
            break;
        case 4:
            system("cls");
            printf("Sum of present nodes is %d\n", sum(head));
            break;
        case 5:
            system("cls");
            printf("Product of present nodes is %d\n", product(head));
            break;
        case 6:
            system("cls");
            printf("Enter node data to search for: ");
            scanf("%d", &data);
            if (!search(head, data))
            {
                printf("Node not found.\n");
                break;
            }
            printf("Node with data %d found.\n", data);
            break;
        case 7:
            system("cls");
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertEnd(head, data);
            break;
        case 8:
            system("cls");
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertFront(head, data);
            break;
        case 9:
            system("cls");
            printf("Enter specific node to insert behind: ");
            scanf("%d", &flag);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertBeforeNode(head, data, getPos(head, flag));
            break;
        case 10:
            system("cls");
            printf("Enter specific node to insert after: ");
            scanf("%d", &flag);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertAfterNode(head, data, getPos(head, flag));
            break;
        case 11:
            system("cls");
            printf("Enter data to locate: ");
            scanf("%d", &data);
            int pos = getPos(head, data);
            printf("Node with data %d is at position %d\n", data, pos);
            break;
        default:
            system("cls");
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}