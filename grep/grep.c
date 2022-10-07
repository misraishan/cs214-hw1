#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    if (argc > 3) return 1;

    char *compareTo;
    if (argc == 1) {
        printf("Non standard usage.");
        return 1;
    } else if (argc == 2) {
        compareTo = argv[1];
    } else {
        compareTo = argv[2];
    }
    
    size_t size = 0;
    char *stdInWord = NULL;
    
    while (getline(&stdInWord, &size, stdin) != -1) {
        char *stdInWordCopy = strdup(stdInWord);
        if (strcmp(argv[1], "-i") == 0) {
            int i = 0;
            while (stdInWordCopy[i] != '\0') {
                stdInWordCopy[i] = tolower(stdInWordCopy[i]);
                i++;
            }
        }
        if (strstr(stdInWordCopy, compareTo) != NULL) {
            printf("%s", stdInWord);
        }
    }
    return 0;
}