#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
  char value;
  struct tnode * next;
}; 

void add_front(struct tnode **lista, char val) {
    struct tnode *xd = malloc(sizeof(struct tnode));
    xd->next = *lista;
    xd->value = val;
    *lista = xd;
}

void print(struct tnode *lista) {
    printf("head -> ");
    for(; lista != NULL; lista = lista->next)
        printf("['%c'] -> ", lista->value);
    printf("NULL\n");
}

void free_list(struct tnode *lista) {
    struct tnode *n;
    while(lista != NULL) {
        n = lista->next;
        free(lista);
        lista = n;
    }
}

int main() {
    struct tnode *head = NULL;
    add_front(&head, 'a');
    add_front(&head, 'c');
    add_front(&head, 'v');
    add_front(&head, 'f');
    add_front(&head, 't');
    
    print(head);
    // head -> ['t'] -> ['f'] -> ['v'] -> ['c'] -> ['a'] -> NULL
    free_list(head);
}
