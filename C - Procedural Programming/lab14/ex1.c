#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct elem {
    char var;
    int count;
    struct elem *next;
} Elem;

Elem* create(char var) {
    Elem *new_elem = (Elem*)malloc(sizeof(Elem));
    new_elem->var = var;
    new_elem->count = 1;
    new_elem->next = NULL;
    return new_elem;
}

void add_list(Elem **head, char var) {
    Elem *current = *head, *prev = NULL;
    while (current != NULL && tolower(current->var) < tolower(var)) {
        prev = current;
        current = current->next;
    }
    if (current != NULL && tolower(current->var) == tolower(var)) {
        current->count++;
    } else {
        Elem *new_elem = create(var);
        if (prev == NULL) {
            new_elem->next = *head;
            *head = new_elem;
        } else {
            new_elem->next = current;
            prev->next = new_elem;
        }
    }
}

void print_list(Elem *head) {
    printf("head ->");
    while (head != NULL) {
        printf(" [%c: %d] ->", head->var, head->count);
        head = head->next;
    }
    printf(" NULL\n");
}

void save_list_to_text_file(Elem *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file");
        return;
    }
    while (head != NULL) {
        fprintf(file, "%c: %d\n", head->var, head->count);
        head = head->next;
    }
    fclose(file);
}

void save_list_to_binary_file(Elem *head, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file");
        return;
    }
    while (head != NULL) {
        fwrite(head, sizeof(Elem) - sizeof(Elem*), 1, file);
        head = head->next;
    }
    fclose(file);
}

void read_list_from_binary_file(Elem **head, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }
    Elem temp;
    while (fread(&temp, sizeof(Elem) - sizeof(Elem*), 1, file)) {
        add_list(head, temp.var);
        (*head)->count = temp.count;
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <output_text_file> <output_binary_file>\n", argv[0]);
        return 1;
    }
    const char *output_text_file = argv[1];
    const char *output_binary_file = argv[2];
    const char *input_text = "Sometimes you will never know the value of a moment until it becomes a memory";

    Elem *head = NULL;
    for (const char *ptr = input_text; *ptr != '\0'; ++ptr) {
        if (isalpha(*ptr)) {
            add_list(&head, *ptr);
        }
    }

    print_list(head);
    save_list_to_text_file(head, output_text_file);
    save_list_to_binary_file(head, output_binary_file);

    // Read from binary file and print
    Elem *new_head = NULL;
    read_list_from_binary_file(&new_head, output_binary_file);
    print_list(new_head);

    // Free the lists
    while (head != NULL) {
        Elem *temp = head;
        head = head->next;
        free(temp);
    }
    while (new_head != NULL) {
        Elem *temp = new_head;
        new_head = new_head->next;
        free(temp);
    }

    return 0;
}
