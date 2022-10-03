#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;

    char *compareTo = argv[1];
    char stdInWord[4096];
    while (fgets(stdInWord, sizeof(stdInWord), stdin) != NULL) {
        if (strstr(stdInWord, compareTo) != NULL) {
            printf("%s", stdInWord);
        }
    }
    return 0;
}