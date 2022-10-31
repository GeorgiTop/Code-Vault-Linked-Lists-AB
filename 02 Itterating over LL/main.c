#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

int main(int argc, char* argv[]) {
    Node root;
    root.x = 15;
    root.next = malloc(sizeof(Node));
    root.next->x = -2;
    root.next->next = malloc(sizeof(Node));
    root.next->next->x = 22;
    root.next->next->next = NULL;
    
    /* While Loop */
    {
        Node* curr = &root;
        while (curr != NULL) {
            printf("%d\n", curr->x);
            curr = curr->next;
        }

    }
    
    /* For Loop*/
    for (Node* curr = &root; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->x);
    }
    
    free(root.next->next);
    free(root.next);
    
    return 0;
}