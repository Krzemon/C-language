#include <stdio.h>
#include <stdlib.h>

struct tnode {
   int value;
   struct tnode *next;
};

void print_list(struct tnode* l) {
    printf("HEAD -> ");
    if(l == NULL) { printf("NULL\n"); return; }
    struct tnode* c = l;
    int nf = 1;
    for(; nf || c != l; c = c->next, nf = 0)
        printf("%d -> ", c->value);
    printf("...\n");
}

struct tnode* gen_el(int value) {
    struct tnode* r = malloc(sizeof(struct tnode));
    r->value = value;
    r->next = NULL;
    return r;
}

struct tnode* get_last(struct tnode* head) {
    // assert head != NULL
    struct tnode* c = head;
    while(c->next != head) c = c->next;
    return c;
}

struct tnode* add_el(struct tnode* head, struct tnode* el) {
    if(head == NULL) {
        el->next = el;
        return el;
    }
    get_last(head)->next = el;
    el->next = head;
    return el;
}

void del_el(struct tnode** head, int var) {
    // jeżeli mamy kilka elementów o podanym kluczu usuwamy wszystkie
    // => musimy przejść się po całej liście
    if(*head == NULL) return;
    struct tnode *l = *head;
    struct tnode *c = l->next, *bc = l;
    for(; c != l; c = c->next, bc = bc->next) {
        if(c->value == var) {
            bc->next = c->next;
            free(c);
            c = bc->next;
        }
    } // bc = last
    if(l->value != var) return;
    if(bc == l) {
        free(l);
        *head = NULL;
        return;
    }
    bc->next = l->next;
    free(l);
    *head = bc->next;
}

struct tnode* add_list(struct tnode* head1, struct tnode* head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    struct tnode *e1 = get_last(head1), *e2 = get_last(head2);
    e1->next = head2;
    e2->next = head1;
    return head1;
}

void free_list(struct tnode** head) {
    struct tnode *l = *head;
    if(l == NULL) return;
    struct tnode *c = l->next, *bc;
    while(c != l) {
        bc = c;
        c = c->next;
        free(bc);
    }
    free(l);
    *head = NULL;
}

int main() {
    struct tnode *l = NULL, *r = NULL;
    l = add_el(l, gen_el(1));
    l = add_el(l, gen_el(3));
    l = add_el(l, gen_el(2));
    l = add_el(l, gen_el(1));
    r = add_el(r, gen_el(6));
    r = add_el(r, gen_el(5));
    r = add_el(r, gen_el(4));
    print_list(l); // 1 2 3
    print_list(r); // 4 5 6
    del_el(&l, 1);
    print_list(l); // 2 3
    l = add_el(l, gen_el(1));
    l = add_list(l, r); // unset r (moved/consumed) -- duplikuje się i wskazuje na tą samą listę
    r = NULL;
    print_list(l);
    free_list(&l); // r was unset
}
