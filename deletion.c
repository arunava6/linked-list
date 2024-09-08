#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insert_node(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
        return head;
    }
}

// deletion from the beginning of the linked list
struct node *delete_start(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    struct node *current = head;
    printf("\nAfter deleting nodes from starting position: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

// deletion from the end of the linked list
struct node *delete_end(struct node *head)
{
    struct node *p = head;
    while (((p->next)->next) != NULL)
    {
        p = p->next;
    }
    struct node *temp = p->next;
    p->next = NULL;
    free(temp);
    printf("\nAfter deleting nodes from last position: ");
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

// deletion from the specific position in the linked list
struct node *delete_position(struct node *head, int value)
{
    struct node *p = head;
    for (int i = 1; i < value - 1; i++)
    {
        p = p->next;
    }
    struct node *temp = head;
    temp = p->next;
    p->next = temp->next;
    free(temp);
    struct node *current = head;
    printf("After deleting nodes from %d position: ", value);
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

// deletion of the specific elements given by user
struct node *delete_node(struct node *head, int value)
{
    struct node *p = head;
    struct node *temp = head->next;
    if (p->data == value)
    {
        head = head->next;
        free(p);
        struct node *current = head;
        printf("After deleting nodes %d from the linked list: ", value);
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    else
    {
        while (temp->data != value && temp->next != NULL)
        {
            p = p->next;
            temp = temp->next;
        }
        if (temp->data == value)
        {
            p->next = temp->next;
            free(temp);
            struct node *current = head;
            printf("After deleting nodes %d from the linked list: ", value);
            while (current != NULL)
            {
                printf("%d ", current->data);
                current = current->next;
            }
        }
        else
        {
            printf("The element is not found in the linked list.");
        }
    }
}
void display(struct node *head)
{
    struct node *current = head;
    printf("The linked list are: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
int main()
{
    struct node *head = NULL;
    int n, value;
    printf("How many nodes you want to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insert_node(head, value);
    }
    display(head);
    // delete_start(head);
    // delete_end(head);
    // int pos;
    // printf("\nenter the position for deleting element: ");
    // scanf("%d",&pos);
    // delete_position(head,pos);
    int node;
    printf("\nEnter the nodes you want to delete: ");
    scanf("%d", &node);
    delete_node(head, node);
}
