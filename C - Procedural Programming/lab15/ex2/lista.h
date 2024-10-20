#ifndef LISTA_H
#define LISTA_H

struct tnode {
    int value;
    struct tnode *next;
    struct tnode *prev;
};
// wypisywanie listy według next i prev
void print_list_next(struct tnode* head);
void print_list_prev(struct tnode* head);

// dodawanie elementu do listy na początku i koncu
struct tnode* add_first(struct tnode* head, struct tnode* el);
struct tnode* add_last(struct tnode* head, struct tnode* el);

// wyciąganie elementów z listy (wczytanie wartości klucza do wyboru elementu), 
// jeżeli mamy kilka elementów o podanym kluczu zwracamy wszystkie jako listę 
struct tnode* del_el_all(struct tnode** head, int var);

// wyciąganie elementu z listy (wczytanie wartości klucza do wyboru elementu), 
// jeżeli mamy kilka elementów o podanym kluczu zwracamy pierwszy
struct tnode* del_el_one(struct tnode** head, int var);

// dokładanie w porządku rosnącym według next
void add_sort(struct tnode** head, struct tnode* el);

// sortowanie listy na część parzystą i nieparzystą
struct tnode* sort_list(struct tnode** head);

// zwalnianie listy
void free_list(struct tnode** head);

#endif // LISTA_H
