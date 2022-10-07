#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// LinkedList struct
struct linkedList {
    char *key;
    int value;
    struct linkedList *next;
    struct linkedList *prev;
};

int printListRev(struct linkedList *x)
{
    if(x == NULL)
    {
        printf("empty");
        return 0;
    }
    else if(x->next != NULL)
        printListRev(x->next);
    printf("%d %s\n", x->value, x->key);
    return 1;
}

int main(int argc, char** argv) {
    struct linkedList *head = NULL;
    char *line = NULL;
    size_t size = 0; // Why does this work? No clue, but it does. Thanks StackOverflow.

    // Loop through stdin and check/add to LL
    while (getline(&line, &size, stdin) != -1) {
        struct linkedList *current = head;
        line[strlen(line) - 1] = '\0';
        // If current isn't null, compare it and if it's the same then add 1
        if (current != NULL && strcmp(current->key, line) == 0) {
            current->value++;
        } else { // If it isn't the same, create a new node and add it to the LL
            struct linkedList *newNode = malloc(sizeof(struct linkedList));

            // Dump contents of the line, set val to 1, set next to null and head to the brand new node
            newNode->key = strdup(line);
            newNode->value = 1;
            newNode->next = NULL;
            newNode->next = head;
            head = newNode;
        }
    }

    // Reverse the linked list so that the output is in the correct order
    printListRev(head);

    exit(0);
}