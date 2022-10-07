#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

int main(int argc, char* argv[]) {
    if (argc != 1) return 1;

    char **words = NULL;
    char *line = NULL;
    size_t size = 0;
    int idx = 0;

    while (getline(&line, &size, stdin) != -1) {
        words = realloc(words, (idx + 1) * sizeof(char*));
        words[idx] = strdup(line);
        idx++;
    }

    // Bubble sort may be inefficent but screw it
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