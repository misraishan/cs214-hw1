#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;

    char *compareTo = argv[1];\
    int j = 0;
    while (compareTo[j] != '\0') {
        compareTo[j] = tolower(compareTo[j]);
        j++;
    }
    char stdInWord[4096];
    while (fgets(stdInWord, sizeof(stdInWord), stdin) != NULL) {
        char stdInWordCopy[4096];
        int i = 0;
        while (stdInWord[i] != '\0') {
            stdInWordCopy[i] = tolower(stdInWord[i]);
            i++;
        }
        if (strstr(stdInWordCopy, compareTo) != NULL) {
            printf("%s", stdInWord);
        }
    }
    return 0;
}