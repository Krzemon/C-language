#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void add_el_end(struct tnode **lista, struct tnode *xd) {
    xd->next = NULL;
    if(*lista == NULL)
        *lista = xd;
    else {
        struct tnode *end = *lista;
        for(; end->next != NULL; end = end->next);
        end->next = xd;
    }
}

int cmp(char a, char b) {
    return tolower(a) == tolower(b);
}

struct tnode *delete_elems(struct tnode **lista, char val) {
    struct tnode *left = NULL;
    while(*lista != NULL && cmp((*lista)->value, val)) {
        struct tnode *zanim = (*lista)->next;
        add_el_end(&left, *lista);
        *lista = zanim;
    }
    if(*lista == NULL) return left;
    struct tnode *cur = *lista;
    while(cur->next != NULL) {
        if(cmp(cur->next->value, val)) {
            struct tnode *zanim = cur->next->next;
            add_el_end(&left, cur->next);
            cur->next = zanim;  
        } else cur = cur->next;
    }
    return left;
}

void print(const char *name, struct tnode *lista) {
    printf("%s -> ", name);
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

int main(int argc, char **argv) {
    struct tnode *head = NULL, *left;
    const char *input = "Ala ma kota";
    for(int i = 0; i < strlen(input); ++i)
        add_front(&head, input[i]);
    
    left = delete_elems(&head, 'a');
    print("head", head);
    print("left", left);
    free_list(head);
    free_list(left);
}
