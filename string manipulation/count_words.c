#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_words(char input_sentence[]) {
    int start = 0;
    while(input_sentence[start] == ' ') {
        start++;
    }

    int end = strlen(input_sentence) - 1;
    while(input_sentence[end] == ' ') {
        end--;
    }

    int i;
    int space_count = 0;
    for(i = start; i <= end; i++) {
        if(input_sentence[i] == ' ') {
            while(input_sentence[i] == ' ') {
                i++;
            }
            space_count++;
        }
    }
    return space_count + 1;
}

int main() {
    char input_sentence[1000];
    scanf("%[^\n]", input_sentence);
    
    int total_word_count = count_words(input_sentence);
    printf("%d\n", total_word_count);
    
    return 0;
}

