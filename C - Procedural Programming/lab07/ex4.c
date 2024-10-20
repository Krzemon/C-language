#include <stdio.h>
#include <string.h>

// W programie należy wykorzystać  funkcje z biblioteki string.h (strstr, strtok, strlen, strcmp) 
void search(char* string, char* sub, int* a, int* b);

int main(int argc, char* argv[]){
    char* str1 = argv[1];
    char* str2 = argv[2];
    int wyraz, lancuch;
    char* find = "we";

    search(str1, find, &wyraz, &lancuch);
    printf("wyraz we pojawil sie razy: %d\n", wyraz);
    printf("lancuch we pojawil sie razy: %d\n", lancuch);

    return 0;
}


void search (char *string, char *sub, int* a, int* b) {
    char *match;
    char chars[] = { ',', ' ', ';','.', ':'};
    int len = strlen(sub);
    char* temp = match;
    for(int i = 0; i < 5; ++i){
        temp = match;
        for(int j = 0; j < 5; ++j){
            temp = strstr(string, sub);
            while (temp){
                if(*match-1 == chars[i] && *match+1 == chars[j]){
                    ++b;
                }
                else if(*match-1 == ' ' && *match+1 == ' '){
                    ++a;
                }
            }
        }
    }
}


