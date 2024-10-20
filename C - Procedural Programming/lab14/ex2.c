#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char surname[50];
    char name[50];
    int year;
    struct person *next_by_age;
    struct person *next_by_surname;
} Person;

Person* create_person(const char *surname, const char *name, int year) {
    Person *new_person = (Person*)malloc(sizeof(Person));
    strcpy(new_person->surname, surname);
    strcpy(new_person->name, name);
    new_person->year = year;
    new_person->next_by_age = NULL;
    new_person->next_by_surname = NULL;
    return new_person;
}

void add_person_by_age(Person **head, Person *new_person) {
    Person *current = *head, *prev = NULL;
    while (current != NULL && current->year < new_person->year) {
        prev = current;
        current = current->next_by_age;
    }
    if (prev == NULL) {
        new_person->next_by_age = *head;
        *head = new_person;
    } else {
        new_person->next_by_age = current;
        prev->next_by_age = new_person;
    }
}

void add_person_by_surname(Person **head, Person *new_person) {
    Person *current = *head, *prev = NULL;
    while (current != NULL && strcmp(current->surname, new_person->surname) < 0) {
        prev = current;
        current = current->next_by_surname;
    }
    if (prev == NULL) {
        new_person->next_by_surname = *head;
        *head = new_person;
    } else {
        new_person->next_by_surname = current;
        prev->next_by_surname = new_person;
    }
}

void print_list_by_age(Person *head) {
    printf("List by Age:\n");
    while (head != NULL) {
        printf("%s %s, %d\n", head->surname, head->name, head->year);
        head = head->next_by_age;
    }
}

void print_list_by_surname(Person *head) {
    printf("List by Surname:\n");
    while (head != NULL) {
        printf("%s %s, %d\n", head->surname, head->name, head->year);
        head = head->next_by_surname;
    }
}

int main() {
    Person *list_by_age = NULL;
    Person *list_by_surname = NULL;

    Person *p1 = create_person("Doe", "John", 1990);
    Person *p2 = create_person("Smith", "Anna", 1985);
    Person *p3 = create_person("Brown", "James", 1995);
    Person *p4 = create_person("Black", "Emily", 1988);

    add_person_by_age(&list_by_age, p1);
    add_person_by_age(&list_by_age, p2);
    add_person_by_age(&list_by_age, p3);
    add_person_by_age(&list_by_age, p4);

    add_person_by_surname(&list_by_surname, p1);
    add_person_by_surname(&list_by_surname, p2);
    add_person_by_surname(&list_by_surname, p3);
    add_person_by_surname(&list_by_surname, p4);

    print_list_by_age(list_by_age);
    print_list_by_surname(list_by_surname);

    // Free the lists
    while (list_by_age != NULL) {
        Person *temp = list_by_age;
        list_by_age = list_by_age->next_by_age;
        free(temp);
    }
    while (list_by_surname != NULL) {
        Person *temp = list_by_surname;
        list_by_surname = list_by_surname->next_by_surname;
        free(temp);
    }

    return 0;
}