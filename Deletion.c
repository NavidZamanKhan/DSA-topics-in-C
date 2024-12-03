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

// Delete from the beginning
struct Node *deleteFromBeginning(struct Node *head)
{
    if (head == NULL)
        return NULL;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from the end
struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete from a specific position
struct Node *deleteFromPosition(struct Node *head, int position)
{
    if (head == NULL)
        return NULL;
    if (position == 1)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of range!\n");
        return head;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

int main()
{
    struct Node *head = createNode(10);
    head = createNode(20);
    head = createNode(30);

    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    head = deleteFromPosition(head, 2);

    traverseLinkedList(head);
    return 0;
}
