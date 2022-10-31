#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Thing {
    int x;
    struct Thing* next;
} Thing;

int main(int argc, char* argv[]) {
    Thing root;
    root.x = 15;
    root.next = malloc(sizeof(Thing));
    root.next->x = -2;
    root.next->next = malloc(sizeof(Thing));
    root.next->next->x = 22;
    root.next->next->next = NULL;
    
    /* While Loop */
    {
        Thing* curr = &root;
        while (curr != NULL) {
            printf("%d\n", curr->x);
            curr = curr->next;
        }

    }
    
    /* For Loop*/
    for (Thing* item = &root; item != NULL; item = item->next) {
        printf("%d\n", item->x);
    }
    
    free(root.next->next);
    free(root.next);
    
    return 0;
}