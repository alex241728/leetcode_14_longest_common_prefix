#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN (32)
#define MAX_STRS_LEN (10)

char* longestCommonPrefix(char**, int);
static int compare(const void *, const void *);
void sort(char* arr[], int arr_len);

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

    strcpy(strs[0], "reflower");
    strcpy(strs[1], "flow");
    strcpy(strs[2], "flight");
    printf("%s\n", longestCommonPrefix(strs, 3));

    // free memory for strings inside and strs
    for (int i = 0; i < MAX_STRS_LEN; i++) {
        free(strs[i]);
    }
    free(strs);

    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    sort(strs, strsSize);
    char* s1 = malloc(sizeof(char) * (strlen(strs[0]) + 1));
    strcpy(s1, strs[0]);
    char* s2 = malloc(sizeof(char) * (strlen(strs[strsSize-1]) + 1));
    strcpy(s2, strs[strsSize-1]);
    char* result = malloc(sizeof(char) * (strlen(strs[0]) + 1));

    int i = 0;
    while (i < strlen(s1) && i < strlen(s2)) {
        if (s1[i] != s2[i]) {
            break;
        }
        else {
            i++;
        }
    }
    strncpy(result, s1, i);
    result[i] = '\0';
    free(s1);
    free(s2);
    return result;
}

static int compare(const void* a, const void* b) {
    return strcmp(a, b);
}

void sort(char* arr[], int arr_len) {
    qsort(arr, arr_len, sizeof(const char*), compare);
}