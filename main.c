#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN (32)
#define MAX_STRS_LEN (10)

char* longestCommonPrefix(char**, int);

int main() {
    // allocate memory for strs and strings inside
    char** strs = malloc(sizeof(char*) * MAX_STRS_LEN);
    for (int i = 0; i < MAX_STRS_LEN; i++) {
        strs[i] = malloc(sizeof(char) * MAX_STR_LEN);
    }

    // tests
    strcpy(strs[0], "flower");
    strcpy(strs[1], "flow");
    strcpy(strs[2], "flight");
    printf("%s\n", longestCommonPrefix(strs, 3));

    strcpy(strs[0], "dog");
    strcpy(strs[1], "racecar");
    strcpy(strs[2], "car");
    printf("%s\n", longestCommonPrefix(strs, 3));

    // free memory for strings inside and strs
    for (int i = 0; i < MAX_STRS_LEN; i++) {
        free(strs[i]);
    }
    free(strs);

    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    // check if the string array has strings in it
    if (strs == NULL || strsSize == 0) {
        return "";
    }

    // check if the first string is empty string
    if (strcmp(strs[0], "") == 0) {
        return "";
    }

    char* prefix = malloc(sizeof(strs[0])+1);
    strcpy(prefix, strs[0]);
    size_t prefix_len = strlen(strs[0]);
    for (int i = 0; i < strsSize; i++) {
        while (strncmp(strs[i], prefix, strlen(prefix)) != 0) {
            prefix_len--;
            strncpy(prefix, strs[0], prefix_len);
            prefix[prefix_len+1] = '\0';
        }
    }

    free(prefix);

    return prefix;
}