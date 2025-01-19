 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find_substring_index(char string[], char substring[]) {
    int i, j, z, flag;
    int string_len = strlen(string);
    int substring_len = strlen(substring);
    
    for(i = 0; i <= string_len - substring_len; i++) {
        flag = 1;
        for(j = 0, z = i; j < substring_len; j++, z++) {
            if(string[z] != substring[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            return i;
        }
    }
    return -1;
}

int main() {
    char string[1000], substring[1000];
    scanf("%[^\n]%*c", string);
    scanf("%[^\n]", substring);
    
    int result = find_substring_index(string, substring);
    printf("%d\n", result);
    return 0;
}

