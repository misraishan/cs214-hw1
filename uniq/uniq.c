#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char** argv) {
    struct node {
        char *key;
        int value;
        struct node *next;
    };
    struct node *head = NULL;
    

    char *line = NULL;
    char *previousLine = NULL;
    size_t size = 0;
    while (getline(&line, &size, stdin) != -1) {
        struct node *current = head;
        line[strlen(line) - 1] = '\0';
        if (current != NULL && strcmp(current->key, line) == 0) {
            current->value++;
        } else {
            struct node *newNode = malloc(sizeof(struct node));
            newNode->key = strdup(line);
            newNode->value = 1;
            newNode->next = NULL;
            newNode->next = head;
            head = newNode;
        }
    }

    struct node *current = head;
    while (current != NULL) {
        printf("%s %d\n", current->key, current->value);
        current = current->next;
    }

    exit(0);
}