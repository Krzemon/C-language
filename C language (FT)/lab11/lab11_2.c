#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *va_cat(int count, ...) {
    va_list args;
    va_start(args, count);
    va_list args_copy;
    va_copy(args_copy, args);
    int len = 0;
    for (int i = 0; i < count; ++i)
        len += strlen(va_arg(args, const char *));
    va_end(args);
    char *r = malloc(len+1);
    r[0] = 0;
    for (int i = 0; i < count; ++i)
        strcat(r, va_arg(args_copy, const char *));
    va_end(args_copy);
    return r;
}
int main() {    
    FILE *fp = fopen("plik.txt", "w");
    if(!fp) { printf("open to write failed"); exit(1); }
    char *a = va_cat(3, "If you never did You should.", " These things are fun", " and Fun is good.");
    printf("%s\n", a); // out: "If you never did You should. These things are fun and Fun is good."
    char *b = va_cat(4, "Sometimes ", "you will never know ", "the value of a moment ", "until it becomes a memory.");
    printf("%s\n", b); // out: "Sometimes you will never know the value of a moment until it becomes a memory."
    fprintf(fp, "%s\n%s\n", a, b);
    fclose(fp); // valgrind haha
    free(a); free(b);
}
