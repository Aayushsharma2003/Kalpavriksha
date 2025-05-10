#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_rotated_string(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) return 0;
    
    int i, j;
    for(i = 0; i < len1; i++) {
        char temp = str1[0];
        for(j = 1; j < len1; j++) {
            str1[j - 1] = str1[j];
        }
        str1[len1 - 1] = temp;
        
        if (!strcmp(str1, str2)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input_str1[1000];
    char input_str2[1000];
    
    scanf("%[^\n]%*c", input_str1);
    scanf("%[^\n]", input_str2);
    
    if (is_rotated_string(input_str1, input_str2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}

