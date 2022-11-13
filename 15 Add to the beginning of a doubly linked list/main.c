#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int x;
    struct Node* next;
};
typedef struct Node Node;

void deallocate(Node** tail, Node** head);
void insert_beggining(Node** tail, int value);
void init(Node** tail, Node** head, int value);

int main(int argc, char* argv[])
{
    Node* tail = NULL;
    Node* head = NULL;
    
    init(&tail, &head, 7);
    insert_beggining(&tail, 3);
    insert_beggining(&tail, 1);

    
    // FOR LOOP ITERATION

    // for(Node* curr = tail; curr != NULL; curr = curr->next){
    //     printf("%d\n", curr->x);
    // }

    // for(Node* curr = head; curr != NULL; curr = curr->prev)
    // {
    //     printf("%d\n", curr->x);
    // }

    Node* curr = head;
    while(curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->prev;
    }

    deallocate(&tail, &head);

    return 0;
}

void deallocate(Node** tail, Node** head) 
{
    if (*tail == NULL) 
    {
        return;
    }

    Node* curr = *tail;
    while(curr->next != NULL) 
    {
        curr = curr->next;
        free(curr->prev);        
    }
    free(curr);

    *tail = NULL;
    *head = NULL;
}

void insert_beggining(Node** tail, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(3);
        return;
    }
    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = *tail;
    if (*tail != NULL)
    {
        (*tail)->prev = new_node;
    }
    *tail = new_node;
}

void init(Node** tail, Node** head, int value)
{
    Node* new_node = malloc(sizeof(Node));
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