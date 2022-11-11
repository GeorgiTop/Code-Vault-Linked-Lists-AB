#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int x;
    struct Node* next;
};
typedef struct Node Node;

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
    
    for(Node* curr = tail; curr != NULL; curr = curr->next){
        printf("%d\n", curr->x);
    }

    return 0;

}