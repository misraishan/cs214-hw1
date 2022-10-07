#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

int main(int argc, char** argv) {
    if (argc == 1) {
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
    } else if (argc == 2 && strcmp(argv[1], "-n") == 0) {
        int *nums = NULL;
        char *line = NULL;
        int idx = 0;
        size_t size = 0;
        while (getline(&line, &size, stdin) != -1) {
            nums = realloc(nums, (idx + 1) * sizeof(int));
            nums[idx] = atoi(line);
            idx++;
        }

        for (int i = 0; i < idx; i++) {
            for (int j = 0; j < idx - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
        }

        for (int i = 0; i < idx; i++) {
            printf("%d\n", nums[i]);
        }
        exit(0);
    }

    printf("Invalid usage");
    return 1;
}