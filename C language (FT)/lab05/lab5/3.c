#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *restrict pousuwaj(char *restrict a, char *restrict b) {
    int blen = strlen(b);
    char *ret = malloc((strlen(a) + 1) * sizeof(char));
    ret[0] = '\0';
    char *p = ret, *f;
    while((f = strstr(a, b)) != NULL) {
        strncat(p, a, f - a);
        p += f - a;
        a = f + blen;
    }
    strcat(p, a);
    ret = realloc(ret, strlen(ret) + 1);
    return ret;
}

int main() {
    char *input1 = NULL, *input2 = NULL;
    size_t n;
    printf("Łańcuch T_1: "); getline(&input1, &n, stdin);
    printf("\nŁańcuch T_2: "); getline(&input2, &n, stdin);
    input2[strlen(input2)-1] = '\0'; // pozbywam się '\n'
    char *output = pousuwaj(input1, input2);
    printf("\nŁańcuch T_3: %s", output);
    free(input1);
    free(input2);
    free(output);
    
}
