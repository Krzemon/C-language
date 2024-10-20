#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**********************/
/* DEFINICJE STRUKTUR */
/**********************/
// struktura przechowujaca liczby
typedef struct tnode {
    char value;
    struct tnode * next;
} tnode; 

/**********************/
/* DEKLARACJE FUNKCJI */
/**********************/

// Funkcja dodająca element na początek listy
void add_front (tnode ** head, tnode  *elem);
// Funkcja tworząca nowy węzeł
tnode* createNode(int value);
// Funkcja wyświetlająca listę
void print_list(tnode* head, char* name);
// Funkcja usuwajaca elementy pierwszej listy, dodajaca je do drugiej listy
tnode* rm_list_elements(tnode** head, char c);

int main(){
    tnode* head_1 = NULL;

    char values[] = {'t', 'f', 'v', 'c', 'a'};

    int values_size = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < values_size; ++i) {
        tnode* new_node = (tnode*)malloc(sizeof(tnode));
        new_node->value = values[i];
        new_node->next = NULL;
        add_front(&head_1, new_node); 
    }
    printf("lista poczatkowa:\n");
    print_list(head_1, "head_1");

    // usuwanie elementow listy i zwracanie nowej
    tnode* left = rm_list_elements(&head_1,values[0]);

    printf("lista zredukowana element %c:\n", values[0]);
    print_list(head_1, "head");
    printf("lista stworzona z usunietego elementu  %c:\n", values[0]);
    print_list(left, "left");

    // zwolnienie pamieci
    tnode *current;
    while (head_1 != NULL) {
        current = head_1;
        head_1 = head_1->next;
        free(current);
    }
    while (left != NULL) {
        current = left;
        left = left->next;
        free(current);
    }
    printf("Pamiec zwolniona :)\n");
    return 0;
}

void add_front (tnode ** head, tnode  *elem) {
    elem->next = *head;
    *head = elem;
}

tnode* createNode(int value) {
    tnode* newNode = (tnode*)malloc(sizeof(tnode));
    if (newNode == NULL) {
        printf("Błąd alokacji pamięci!\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void print_list(tnode* head, char* head_name) {
    tnode *current = head;
    printf("%s -> ", head_name);
    while (current != NULL) {
        printf("['%c'] -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

tnode* rm_list_elements(tnode** head, char c) {
    tnode* current = *head;
    tnode* prev = NULL;
    tnode* left = NULL;

    while (current  != NULL) {
        if (tolower(current->value) == tolower(c)){
            tnode* to_remove = current;
            if (prev == NULL) {
                *head = current->next;
            }
            else{
                prev->next = current->next;
            }
            current = current->next;
            add_front(&left, to_remove);
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    return left;
}