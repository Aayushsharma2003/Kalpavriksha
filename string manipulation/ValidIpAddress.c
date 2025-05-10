#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validIpAddress(char *s)
{
    int dotcount = 0;
    int numcount = 0;
    int num;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '.' || (s[i] >= '0' && s[i] <= '9')) {
            continue;
        } else {
            return 0;
        }
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '.') {
            if (i != 0 && i < strlen(s) - 1) {
                dotcount++;
            } else {
                return 0;
            }
        } else if (s[i] >= '0' && s[i] <= '9') {
            num = 0;

            while (s[i] != '.' && s[i] != '\0') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            numc

