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

void add_end(struct tnode **lista, char val) {
    struct tnode *xd = malloc(sizeof(struct tnode));
    xd->next = NULL; // default?
    xd->value = val;
    if(*lista == NULL)
        *lista = xd;
    else {
        struct tnode *end = *lista;
        for(; end->next != NULL; end = end->next);
        end->next = xd;
    }
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
    add_end(&head, 'a');
    add_end(&head, 'c');
    add_end(&head, 'v');
    add_end(&head, 'f');
    add_end(&head, 't');
    
    print(head);
    // head -> ['t'] -> ['f'] -> ['v'] -> ['c'] -> ['a'] -> NULL
    free_list(head);
}
