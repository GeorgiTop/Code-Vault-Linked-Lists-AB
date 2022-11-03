#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Node
{
    int x;
    struct _Node *next;
};

typedef struct _Node Node;

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
    Node *root = malloc(sizeof(Node));
    if (root == NULL)
    {
        exit(2);
    }

    insert_end(&root, 15);
    insert_end(&root, -2);
    insert_end(&root, 11);
    /* While Loop */
    // {
    //     Node* curr = &root;
    //     while (curr != NULL) {
    //         printf("%d\n", curr->x);
    //         curr = curr->next;
    //     }
    // }

    /* For Loop*/
    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);
    }

    //Havent deallocated the mallocs

    return 0;
}