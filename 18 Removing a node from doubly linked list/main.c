#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int x;
    struct Node *next;
};
typedef struct Node Node;

void deallocate(Node **tail, Node **head);
void init(Node **tail, Node **head, int value);
void insert_beggining(Node **tail, int value);
void insert_after(Node *node, int value);
void insert_end(Node **head, int value);
void remove_node(Node *node);

int main(int argc, char *argv[])
{
    Node *tail = NULL;
    Node *head = NULL;

    init(&tail, &head, 7);
    insert_beggining(&tail, 3);
    insert_beggining(&tail, 1);
    remove_node(tail->next);
    Node* aux = tail->next;
    remove_node(tail);
    tail = aux;

    // FOR LOOP ITERATION
    // for(Node* curr = tail; curr != NULL; curr = curr->next){
    //     printf("%d\n", curr->x);
    // }
    // // REVERSE FOR LOOP
    // for(Node* curr = head; curr != NULL; curr = curr->prev)
    // {
    //     printf("%d\n", curr->x);
    // }

    // WHILE LOOP ITERATION

    Node *curr = tail;
    while (curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

    // WHILE REVERSED
    // Node* curr = head;
    // while(curr != NULL)
    // {
    //     printf("%d\n", curr->x);
    //     curr = curr->prev;
    // }

    deallocate(&tail, &head);

    return 0;
}

void deallocate(Node **tail, Node **head)
{
    if (*tail == NULL)
    {
        return;
    }

    Node *curr = *tail;
    while (curr->next != NULL)
    {
        curr = curr->next;
        free(curr->prev);
    }
    free(curr);

    *tail = NULL;
    *head = NULL;
}

void init(Node **tail, Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(2);
        return;
    }
    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    *tail = new_node;
    *head = new_node;
}

void insert_beggining(Node **tail, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(3);
        return;
    }
    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = *tail;
    (*tail)->prev = new_node;
    *tail = new_node;
}

void insert_after(Node *node, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(4);
        return;
    }
    new_node->x = value;
    new_node->prev = node;
    new_node->next = node->next;

    node->next = new_node;
    
    if (node->next != NULL)
    {
        node->next->prev = new_node;
    }
}

void insert_end(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(5);
        return;
    }
    new_node->x = value;
    new_node->prev = *head;
    new_node->next = NULL;
    (*head)->next = new_node;
    *head = new_node;
}

void remove_node(Node *node)
{
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }
    free(node);
}
