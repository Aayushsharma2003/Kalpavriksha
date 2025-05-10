
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_char_count(char str[]) {
    int char_count[256] = {0};
    int i;
    for(i = 0; i < strlen(str); i++) {
        char_count[str[i]]++;
    }
    for(i = 0; i < strlen(str); i++) {
        if(char_count[str[i]] != 0) {
            if(char_count[str[i]] != 1)
                printf("%c%d", str[i], char_count[str[i]]);
            else
                printf("%c", str[i]);
            char_count[str[i]] = 0;
        }
    }
}

int main() {
    char input_str[100];
    scanf("%s", input_str);
    print_char_count(input_str);
    return 0;
}

