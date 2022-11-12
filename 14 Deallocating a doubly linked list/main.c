#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int x;
    struct Node* next;
};
typedef struct Node Node;

void deallocate(Node** tail, Node** head);

int main(int argc, char* argv[])
{
    Node* tail = malloc(sizeof(Node));

    if (tail == NULL) {
        return 1;
    }
    tail->x = 1;
    tail->prev = NULL;    
    tail->next = malloc(sizeof(Node));

    if (tail->next == NULL) {
        return 2;
    }
    tail->next->x = 3;
    tail->next->prev = tail;
    tail->next->next = malloc(sizeof(Node));
    
    if (tail->next->next == NULL)
    {
        return 3;
    }
    tail->next->next->x = 7;
    tail->next->next->prev = tail->next;
    tail->next->next->next = NULL;
    Node* head = tail->next->next;
    
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