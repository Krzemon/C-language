#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void swap (char **p, char **q) { 
  char *temp = *p;
  *p = *q;
  *q = temp;
}

#define DELIM ", ;.:-"

char** podziel(char *inp, int *len) { // funkcja tworząca tablicę niepowtarzających się słów z łańcucha
    char **t = malloc(sizeof(char*)); *len = 1;
    char *slowo = t[0] = strtok(inp, DELIM);
    while((slowo = strtok(NULL, DELIM))) {
        int bylo = 0;
        for(int i = 0; i < *len; ++i)
            if(strcmp(slowo, t[i]) == 0) {
                bylo = 1;
                break;
            }
        if(bylo) continue;
        t = realloc(t, ++(*len) * sizeof(char*)); // n realloc'ów - można, jeszcze nie optymalizujemy
        t[*len - 1] = slowo;
    }
    return t;
}
void sort(char **t, int len) { // funkcja sortująca tablicę słów
    for(int i = 0; i < len - 1; ++i)
        for(int j = i + 1; j < len; ++j)
            if(strcmp(t[i], t[j]) > 0)
                swap(t+i, t+j);
}

char* sklej(char **t, int len) { // funkcja „sklejająca” słowa z tablicy (rozdzielane spacjami) w JEDEN łańcuch
    int alloc = strlen(t[0]) + 1;
    char *r = malloc(alloc);
    strcpy(r, t[0]);
    for(int i = 1; i < len; ++i) {
        alloc += strlen(t[i]) + 1;
        r = realloc(r, alloc);
        strcat(r, " ");
        strcat(r, t[i]);
    }
    return r;
}


int main(int argc, char **argv) {
    if(argc < 2) {
        printf("err: too few args\n");
        return 1;
    }
    if(argc > 2) {
        printf("err: too many args\n");
        return 1;
    }
    int tlen = 0;
    char **t = podziel(argv[1], &tlen);
    sort(t, tlen);
    char *wynik = sklej(t, tlen);
    printf("%s\n", wynik);
    free(wynik);
    // używam argv[1] wewnątrz t
    // for(int i = 0; i < tlen; ++i)
    //     free(t[i]);
    free(t);
}
