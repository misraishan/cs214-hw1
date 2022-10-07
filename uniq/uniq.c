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

// A function used to reverse the linked list
// https://qnaplus.com/c-program-to-reverse-a-linked-list/ 
void reverseLinkedList(struct linkedList **head) {
  struct linkedList *new_head = NULL;
  struct linkedList *tmp = NULL;
  while(*head != NULL) {
    tmp = *head;
    *head = (*head)->next;
    tmp->next = new_head;
    new_head = tmp;
  }
  *head = new_head;
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
    reverseLinkedList(&head);

    // Set current to new head and print the linked list
    struct linkedList *current = head;
    while (current != NULL) {
        printf("%s %d\n", current->key, current->value);
        current = current->next;
    }

    exit(0);
}