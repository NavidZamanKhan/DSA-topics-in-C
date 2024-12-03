#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseLinkedList(struct Node *head)
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Insert at the end
void insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position
struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (position == 1)
    {
        newNode->next = head;
        return newNode;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range!\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main()
{
    struct Node *head = createNode(10);
    head = insertAtBeginning(head, 5);
    insertAtEnd(head, 20);
    head = insertAtPosition(head, 15, 3);

    traverseLinkedList(head);
    return 0;
}
