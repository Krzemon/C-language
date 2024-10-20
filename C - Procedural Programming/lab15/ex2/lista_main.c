#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
    struct tnode* head = NULL;

    struct tnode* el1 = (struct tnode*)malloc(sizeof(struct tnode));
    el1->value = 5;
    head = add_first(head, el1);

    struct tnode* el2 = (struct tnode*)malloc(sizeof(struct tnode));
    el2->value = 3;
    head = add_first(head, el2);

    struct tnode* el3 = (struct tnode*)malloc(sizeof(struct tnode));
    el3->value = 8;
    head = add_last(head, el3);

    printf("List (next): ");
    print_list_next(head);

    printf("List (prev): ");
    print_list_prev(head);


    struct tnode* el4 = (struct tnode*)malloc(sizeof(struct tnode));
    el4->value = 4;
    add_sort(&head, el4);

    printf("List after sorted add (next): ");
    print_list_next(head);


    struct tnode* deleted_all = del_el_all(&head, 3);
    printf("Deleted all with value 3 (next): ");
    print_list_next(deleted_all);

    printf("List after deleting all 3s (next): ");
    print_list_next(head);


    struct tnode* deleted_one = del_el_one(&head, 5);
    if (deleted_one) {
        printf("Deleted one with value 5: %d\n", deleted_one->value);
        free(deleted_one);
    }

    printf("List after deleting one 5 (next): ");
    print_list_next(head);


    struct tnode* sorted_head = sort_list(&head);

    printf("Even list (next): ");
    print_list_next(sorted_head);

    printf("Odd list (next): ");
    print_list_next(head);


    free_list(&sorted_head);
    free_list(&head);

    return 0;
}
