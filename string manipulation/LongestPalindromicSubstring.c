#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void longest_palindromic_substring(char str[]) {
    int i, j;
    int str_len, max_len = 0;
    
     
    for(i = 0; str[i] != '\0'; i++) {
        for(j = i; str[j] != '\0'; j++) {
            int start_idx = i;
            int end_idx = j;
            int is_palindrome = 1;
            
             
            while(start_idx <= end_idx) {
                if(str[start_idx++] != str[end_idx--])
                    is_palindrome = 0;
            }
            
            
            if(is_palindrome) {
                str_len = j + 1 - i;
                if(str_len > max_len)
                    max_len = str_len;
            }
        }
    }

     
    for(i = 0; str[i] != '\0'; i++) {
        for(j = i; str[j] != '\0'; j++) {
            int start_idx = i;
            int end_idx = j;
            int is_palindrome = 1;
            
             
            while(start_idx <= end_idx) {
                if(str[start_idx++] != str[end_idx--])
                    is_palindrome = 0;
            }

           
            if(is_palindrome) {
                str_len = j + 1 - i;
                if(str_len == max_len) {
                    start_idx = i;
                    end_idx = j;
                    while(start_idx <= end_idx)
                        printf("%c", str[start_idx++]);
                    exit(1);  
                }
            }
        }
    }
}

int main() {
    char input_str[100];
    scanf("%s", input_str);  
    longest_palindromic_substring(input_str); 
    return 0;
}

