#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//generowanie liczb losowych calkowitych z przedziału (min, max)
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}
//generowanie liczb losowych rzeczywistych z przedziału (min, max)
double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}

struct liczba {
    union {
        int i;
        double d;
    } u;
    char t;
    
};

void struct_prn(struct liczba xd) {
    switch(xd.t) {
        case 'i':
            printf("%d -> int\n", xd.u.i);
            break;
        case 'd':
            printf("%f -> double\n", xd.u.d);
            break;
        default:
            assert(0); // unreachable
    }
}

int cmp(const void *a, const void* b) {
    const struct liczba *as = a, *bs = b;
    float fa, fb;
    if(as->t != bs->t) return as->t - bs->t;
    switch(as->t) { // both have that type
        case 'i':
            return as->u.i - bs->u.i;
        case 'd':
            fa = as->u.d, fb = bs->u.d;
            return ( fa > fb ) - ( fa < fb );
        default:
            printf("\n%d\n", as->t);
            assert(0); // unreachable
    }
}

void posortuj(struct liczba *t, int len) {
    qsort(t, len, sizeof(struct liczba), cmp);
}

int policz(struct liczba *t, int len, struct liczba co) {
    struct liczba *tl, *tr, *to = bsearch(&co, t, len, sizeof(struct liczba), cmp);
    if(to == NULL) return 0;
    tl = tr = to;
    while(tl-1 >= t && cmp(tl-1, &co) == 0) --tl;
    while(tr+1 < t+len && cmp(tr+1, &co) == 0) ++tr;
    return tr - tl + 1;
    
}

int main(int argc, char **argv){
    srand(time(0));
    int len = i_rand(10, 20);
    struct liczba NUMBERS[len];
    for(int i = 0; i < len; ++i) {
        if(rand() % 2) {
            NUMBERS[i].t = 'i';
            NUMBERS[i].u.i = i_rand(-5, 5);
        } else {
            NUMBERS[i].t = 'd';
            NUMBERS[i].u.d = d_rand(-5., 5.);
        }
    }
    for(int i = 0; i < len; ++i) struct_prn(NUMBERS[i]);
    FILE *fp = fopen("test.dat", "wb");
    if(!fp) { printf("open to write failed"); exit(1); }
    fwrite(NUMBERS, sizeof(struct liczba), len, fp);
    fclose(fp); // valgrind haha
    
    fp = fopen("test.dat", "rb");
    if(!fp) { printf("open to read failed"); exit(1); }
    fseek(fp, 0, SEEK_END);
    int bytes_size = ftell(fp);
    rewind(fp);
    printf("File size: %d\n", bytes_size);
    int nlen = bytes_size / sizeof(struct liczba);
    struct liczba TAB[nlen];
    fread(TAB, sizeof(struct liczba), nlen, fp);
    fclose(fp);
    for(int i = 0; i < nlen; ++i) struct_prn(TAB[i]);
    
    posortuj(NUMBERS, nlen);
    printf("sorted:\n");
    for(int i = 0; i < len; ++i) struct_prn(NUMBERS[i]);
    if(argc < 3) {
        printf("err: too few args\n");
        return 1;
    }
    if(argc > 3) {
        printf("err: too many args\n");
        return 1;
    }
    struct liczba input;
    switch(argv[1][0]) {
        case 'i':
            input.t = 'i';
            input.u.i = atoi(argv[2]);
            break;
        case 'd':
            input.t = 'd';
            input.u.d = atof(argv[2]);
            break;
        default:
            assert(0); // unreachable haha
    }
    printf("DEBUG: wczytana liczba z wejścia: "); struct_prn(input);
    int cnt = policz(NUMBERS, nlen, input);
    if(cnt == 0) {
        printf("Nie znaleziono. :(\n");
    } else {
        printf("Znaleziono %d wynik(i).\n", cnt);
    }
}

