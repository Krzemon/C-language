#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct elem {
    char c;
    int n;
    struct elem *next;
};

struct elem *create (char var) {
    struct elem *r = malloc(sizeof(struct elem));
    r->c = var;
    r->n = 1;
    r->next = NULL;
    return r;
}

int charcmp(char a, char b) {
    char la = tolower(a), lb = tolower(b);
    return la != lb ? (la - lb) : (b - a);
}

struct elem *add_lis (struct elem *l, char c) {
    if(l == NULL)
        return create(c);
    if(charcmp(c, l->c) < 0) {
        struct elem *r = create(c);
        r->next = l;
        return r;
    }
    struct elem *cur = l, *n;
    for(;;) {
        if(charcmp(c, cur->c) == 0) {
            ++cur->n;
            return l;
        }
        n = cur->next;
        if(n == NULL || charcmp(c, n->c) < 0) {
            struct elem *m = create(c);
            cur->next = m;
            m->next = n;
            return l;
        }
        cur = n;
    }
}

void print(const char *name, struct elem *lista) {
    printf("%s->", name);
    for(; lista != NULL; lista = lista->next)
        printf("[%c : %d]->", lista->c, lista->n);
    printf("NULL\n");
}

void free_list(struct elem *lista) {
    struct elem *n;
    while(lista != NULL) {
        n = lista->next;
        free(lista);
        lista = n;
    }
}
int main(int argc, char **argv) {
    if(argc < 4) {
        printf("err: too few args\n");
        return 1;
    }
    if(argc > 4) {
        printf("err: too many args\n");
        return 1;
    }
    // argv[1] - output text file
    // argv[2] - output binary file
    // argv[3] - input string
    struct elem *l = NULL;
    for(int i = 0; i < strlen(argv[3]); ++i) {
        char c = argv[3][i];
        if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            l = add_lis(l, c);
    }
    print("head", l);
    FILE *fp = fopen(argv[1], "w");
    if(!fp) { printf("open to write failed"); exit(1); }
    for(struct elem *lista = l; lista != NULL; lista = lista->next)
        fprintf(fp, "%c : %d\n", lista->c, lista->n);
    fclose(fp);
    
    fp = fopen(argv[2], "wb");
    if(!fp) { printf("open to write failed"); exit(1); }
    for(struct elem *lista = l; lista != NULL; lista = lista->next)
        fwrite(lista, sizeof(struct elem), 1, fp);
    fclose(fp);
    
    
    free_list(l);
    l = NULL;
    
    
    fp = fopen(argv[2], "rb");
    if(!fp) { printf("open to read failed"); exit(1); }
    fseek(fp, 0, SEEK_END);
    int bytes_size = ftell(fp);
    rewind(fp);
    printf("File size: %d\n", bytes_size);
    int nlen = bytes_size / sizeof(struct elem);
    struct elem TAB[nlen];
    fread(TAB, sizeof(struct elem), nlen, fp);
    fclose(fp);
    for(int i = 0; i < nlen; ++i) {
        struct elem *p = TAB + i;
        printf("%c %d %p\n", p->c, p->n, p->next);
    }
    
}
