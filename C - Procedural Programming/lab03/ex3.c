#include <stdio.h>
#include <string.h>

void DELETE(char* string, char* sub);

int main(){

    char text_input[] = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";

    char* to_delete = "sie";

    printf("przed:%s\n", text_input);
    
    DELETE(text_input, to_delete);

    printf("po:%s\n", text_input);

    return 0;
}


void DELETE (char *string, char *sub) {
    char *match;
    int len = strlen(sub);
    while (match = strstr(string, sub)) {
        *match = '\0';
        strcat(string, match+len+1);
    }
}
 

