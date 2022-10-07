#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

int main(int argc, char* argv[]) {
    if (argc != 1) return 1;

    char *words[100];
    char *newWords[100];
    char buffer[6];
    int idx = 0;
    
    while (fgets(buffer, 4096, stdin) != NULL) {
        words[idx] = strndup(buffer, 4096);
        // printf("%s", words[idx]);
        idx++;
    }


    /*
    // TODO: Fix lowercase of words; currently seg faults
    for (int i = 0; i < idx; i++) {
        int j = 0;
        while (words[i][j] != '\0') {
            newWords[i][j] = tolower(words[i][j]);
            j++;
        }
        printf("%s", newWords[i]);
    }*/

    int i = 0;
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < idx - 1; j++) {
            if (strcasecmp(words[j], words[j + 1]) > 0) {
                char* tmp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%s", words[i]);
    }

    exit(0);
}