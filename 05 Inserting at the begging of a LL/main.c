#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Node
{
    int x;
    struct _Node *next;
};

typedef struct _Node Node;

void deallocate(Node **root)
{
    Node *curr = *root;
    while (curr != NULL)
    {
        Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

void insert_beginning(Node **root, int value)
{
    Node *new_node = malloc(sizeof(int));
    if (new_node == NULL)
    {
        exit(3);
    }

    new_node->x = value;
    new_node->next = *root;

    *root = new_node;
}

void insert_end(Node **root, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    new_node->x = value;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    Node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int main(int argc, char *argv[])
{
    Node *root = NULL;

    insert_end(&root, -2);
    insert_end(&root, 11);
    insert_end(&root, 22);
    insert_beginning(&root, 50);
    insert_beginning(&root, 17);

    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);
    }

    deallocate(&root);

    return 0;
}