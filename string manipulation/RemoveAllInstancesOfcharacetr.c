#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void remove_char(char str[], char ch) {
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ch)
            continue;
        else
            printf("%c", str[i]);
    }
}

int main() {
    char input_str[100];
    char char_to_remove;
    scanf("%[^\n]%*c", input_str);
    scanf("%c", &char_to_remove);
    remove_char(input_str, char_to_remove);
    return 0;
}

