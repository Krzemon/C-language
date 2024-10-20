#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void print_list_next(struct tnode* head) {
    struct tnode* current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void print_list_prev(struct tnode* head) {
    struct tnode* current = head;
    while (current->next) {
        current = current->next;
    }
    while (current) {
        printf("%d ", current->value);
        current = current->prev;
    }
    printf("\n");
}

struct tnode* add_first(struct tnode* head, struct tnode* el) {
    if (!head) {
        el->next = NULL;
        el->prev = NULL;
    }
    else{
        head->prev = el;
        el->next = head;
        el->prev = NULL;
    }

    return el;
}

struct tnode* add_last(struct tnode* head, struct tnode* el) {
    if (!head) {
        el->next = NULL;
        el->prev = NULL;
        return el;
    }
    struct tnode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = el;
    el->prev = current;
    el->next = NULL;
    return head;
}

struct tnode* del_el_all(struct tnode** head, int var) {
    struct tnode* current = *head;
    struct tnode* result = NULL;

    while (current) {
        struct tnode* next = current->next;
        if (current->value == var) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            current->next = result;
            if (result) {
                result->prev = current;
            }
            result = current;
        }
        current = next;
    }
    return result;
}

struct tnode* del_el_one(struct tnode** head, int var) {
    struct tnode* current = *head;
    while (current) {
        if (current->value == var) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            current->next = NULL;
            current->prev = NULL;
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_sort(struct tnode** head, struct tnode* el) {
    if (!*head || (*head)->value >= el->value) {
        el->next = *head;
        el->prev = NULL;
        if (*head) {
            (*head)->prev = el;
        }
        *head = el;
        return;
    }
    struct tnode* current = *head;
    while (current->next && current->next->value < el->value) {
        current = current->next;
    }
    el->next = current->next;
    el->prev = current;
    if (current->next) {
        current->next->prev = el;
    }
    current->next = el;
}

struct tnode* sort_list(struct tnode** head) {
    struct tnode *even_head = NULL, *odd_head = NULL;
    struct tnode *current = *head;

    while (current) {
        struct tnode* next = current->next;
        if (current->value % 2 == 0) {
            even_head = add_last(even_head, current);
        } else {
            odd_head = add_last(odd_head, current);
        }
        current = next;
    }

    *head = NULL; // clear the original list head

    return even_head;
}

void free_list(struct tnode** head) {
    struct tnode* current = *head;
    while (current) {
        struct tnode* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
