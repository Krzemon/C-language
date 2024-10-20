#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#define CSIZE 7
// strlen("00-000")+1
struct person {
    char f_name[SIZE];
    char l_name[SIZE];
    char code[CSIZE];
    int age;
};

void trun(char *x) {
    int l = strlen(x) - 1;
    if(l<0) return;
    if(x[l] == '\r' || x[l] == '\n') x[l] = '\0';
    --l;
    if(l<0) return;
    if(x[l] == '\r' || x[l] == '\n') x[l] = '\0';
}

struct person* create_tab (char *filename, int *len) {
    FILE *fp = fopen(filename, "r");
    if(!fp) { printf("open to read failed"); exit(1); }
    *len = 0;
    struct person* t = NULL;
    while(!feof(fp)) {
        ++*len;
        t = realloc(t, *len * sizeof(struct person));
        fgets(t[*len-1].f_name, SIZE, fp);
        fgets(t[*len-1].l_name, SIZE, fp);
        fgets(t[*len-1].code, CSIZE, fp);
        fscanf(fp, "%d\n", &t[*len-1].age);
        trun(t[*len-1].f_name); trun(t[*len-1].l_name); trun(t[*len-1].code);
    }
    fclose(fp);
    return t;
}
int main() {
    int len = 0;
    struct person *t = create_tab("plik.txt", &len);
    printf("[");
    for(int i = 0; i < len; ++i) {
        printf("(%s, %s, %s, %d), ", t[i].f_name,t[i].l_name,t[i].code,t[i].age);
    } printf("]\n");
    
    
    FILE *fp = fopen("dane.dat", "wb");
    if(!fp) { printf("open to write failed"); exit(1); }
    fwrite(t, sizeof(struct person), len, fp);
    fclose(fp); // valgrind haha
    
    free(t); t = NULL;
    
    fp = fopen("dane.dat", "rb");
    if(!fp) { printf("open to read failed"); exit(1); }
    fseek(fp, 0, SEEK_END);
    int bytes_size = ftell(fp);
    rewind(fp);
    printf("File size: %d\n", bytes_size);
    int nlen = bytes_size / sizeof(struct person);
    struct person dane[nlen];
    fread(dane, sizeof(struct person), nlen, fp);
    fclose(fp);
    printf("[");
    for(int i = 0; i < nlen; ++i) {
        printf("(%s, %s, %s, %d), ", dane[i].f_name,dane[i].l_name,dane[i].code,dane[i].age);
    } printf("]\n");
}
