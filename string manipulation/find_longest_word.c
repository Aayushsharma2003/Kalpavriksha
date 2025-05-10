#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_longest_word(char sentence[]) {
    char temp[1000];
    strcpy(temp, sentence);
    
    char *word = strtok(sentence, " ");
    int max_len = 0;
    
    while(word != NULL) {
        if(strlen(word) > max_len)
            max_len = strlen(word);
        word = strtok(NULL, " ");
    }
    
    char *token = strtok(temp, " ");
    while(token != NULL) {
        if(strlen(token) == max_len) {
            printf("%s\n", token);
            exit(1);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input_sentence[1000];
    scanf("%[^\n]", input_sentence);
    print_longest_word(input_sentence);
    return 0;
}

