#include <stdio.h>
#include <stdlib.h>

/**********************/
/* DEFINICJE STRUKTUR */
/**********************/

// struktura listy jednokierunkowej
struct tnode {
    int value;
    struct tnode *next;
};

/**********************/
/* DEKLARACJE FUNKCJI */
/**********************/

// tworzy nowy element listy
struct tnode* create(int value);

// dodaje element na koniec listy
struct tnode* add_last(struct tnode* head, struct tnode* el);

// sortuje, najpierw parzyste, potem nieparzyste
void sort_list_even_odd(struct tnode** head);
// wypisuje liste kolejnoscia
void print_list_next(struct tnode* head);

// wypisuje liste kolejnoscia z adresami
void print_list_with_addresses(struct tnode* head);

// czysci liste
void free_list(struct tnode** head);



int main(void) {
    struct tnode* head = NULL;
    int values[] = {5, 5, 14, 7, 3, 3, 4, 14, 10, 4, 2, 11};
    int num_elem = sizeof(values) / sizeof(*values);
    
    for (int i = 0; i < num_elem; ++i) {
        struct tnode* elem = create(values[i]);
        head = add_last(head, elem);
    }
    printf("address\t\tvalue\tnext\n");
    print_list_with_addresses(head);

    printf("\nsortujemy...\n\n");
    sort_list_even_odd(&head);

    printf("address\t\tvalue\tnext\n");
    print_list_with_addresses(head);

    free_list(&head);

    return 0;
}
// ----------------------------------------------

struct tnode* create(int value) {
    struct tnode* new_node = (struct tnode*)malloc(sizeof(struct tnode));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void print_list_next(struct tnode* head) {
    struct tnode* current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

struct tnode* add_last(struct tnode* head, struct tnode* el) {
    if (!head) {
        el->next = NULL;
        return el;
    }
    struct tnode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = el;
    el->next = NULL;
    return head;
}

void print_list_with_addresses(struct tnode* head) {
    struct tnode* current = head;
    while (current) {
        printf("%p\t%d\t%p\n", current, current->value, current->next);
        current = current->next;
    }
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

void sort_list_even_odd(struct tnode** head) {
    if (!head || !*head) return;

    struct tnode* even_head = NULL;
    struct tnode* even_tail = NULL;
    struct tnode* odd_head = NULL;
    struct tnode* odd_tail = NULL;
    struct tnode* current = *head;

    while (current) {
        struct tnode* next = current->next;
        current->next = NULL;
        if (current->value % 2 == 0) {
            // Dodaj do listy parzyste
            if (even_tail) {
                even_tail->next = current;
                even_tail = current;
            } else {
                even_head = even_tail = current;
            }
        } else {
            // Dodaj do listy nieparzyste
            if (odd_tail) {
                odd_tail->next = current;
                odd_tail = current;
            } else {
                odd_head = odd_tail = current;
            }
        }
        current = next;
    }

    // Połącz listy
    if (even_tail) {
        even_tail->next = odd_head;
    } else {
        even_head = odd_head;
    }

    *head = even_head;
}
