#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
struct p {
    char f[SIZE];
    char l[SIZE];
    int y;
    struct p *na;
    struct p *nl;
};

struct p *gen(char *f, char *l, int y) {
    struct p *r = malloc(sizeof(struct p));
    strcpy(r->f, f);
    strcpy(r->l, l);
    r->y = y;
    r->na = NULL;
    r->nl = NULL;
    return r;
};

struct lista {
    struct p *sa;
    struct p *sl;
};

void free_list(struct lista l) {
    struct p *c = l.sa, *n;
    while(c != NULL) {
        n = c->na;
        free(c);
        c = n;
    }
}

void add(struct lista *l, struct p *p) {
    if(l->sa == NULL) { // both are NULLs
        l->sa = p, l->sl = p;
        p->na = NULL, p->nl = NULL;
        return;
    }
    
    if(strcmp(l->sl->l, p->l) > 0) {
        p->nl = l->sl;
        l->sl = p;
    } else {
        for(struct p *bc = l->sl, *c = l->sl->nl; ; bc = bc->nl, c = c->nl) {
            if(c == NULL || strcmp(c->l, p->l) > 0) {
                bc->nl = p;
                p->nl = c;
                break;
            }
        }
    }
    
    if(l->sa->y < p->y) {
        p->na = l->sa;
        l->sa = p;
    } else {
        for(struct p *bc = l->sa, *c = l->sa->na; ; bc = bc->na, c = c->na) {
            if(c == NULL || c->y < p->y) {
                bc->na = p;
                p->na = c;
                break;
            }
        }
    }
}


int main() {
    struct lista l;
    l.sa = NULL, l.sl = NULL;
    add(&l, gen("B", "b", 2003));
    add(&l, gen("A", "a", 2000));
    add(&l, gen("D", "d", 2002));
    add(&l, gen("C", "c", 2001));
    printf("[");
    for(struct p *c = l.sl; c != NULL; c = c->nl) {
        printf("(%s, %s, %d), ", c->f, c->l, c->y);
    } printf("]\n");
    printf("[");
    for(struct p *c = l.sa; c != NULL; c = c->na) {
        printf("(%s, %s, %d), ", c->f, c->l, c->y);
    } printf("]\n");
    free_list(l);
}
