 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

void remove_duplicate_characters(char* input_string);

int main() {
    char* input_string = (char*)malloc(1000 * sizeof(char));
    scanf("%[^\n]", input_string);
    
    remove_duplicate_characters(input_string);
    
    free(input_string);
    
    return 0;
}

void remove_duplicate_characters(char* input_string) {
    char hash_counting_characters[256] = {0};
    int unique_character_count = 0;
    int i;
    
    for(i = 0; input_string[i] != '\0'; i++) {
        if(hash_counting_characters[input_string[i]] == 0) {
            hash_counting_characters[input_string[i]]++;
            unique_character_count++;
        }
    }
    
    char* output_string = (char*)malloc(unique_character_count * sizeof(char));
    int output_string_length = 0;
    
    for(i = 0; input_string[i] != '\0'; i++) {
        if(hash_counting_characters[input_string[i]] == 1) {
            output_string[output_string_length++] = input_string[i];
            hash_counting_characters[input_string[i]]--;
        }
    }
    
    for(i = 0; i < output_string_length; i++) {
        printf("%c", output_string[i]);
    }
    
    free(output_string);
}

