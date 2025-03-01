#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

Node* createNode(char* word) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        perror("Memory allocate error");
        return NULL;
    }
    node->word = strdup(word);

    if (node->word == NULL) {
        perror("Memory allocate error");
        return NULL;
    }
    node->count = 1;
    node->next = NULL;
    return node;
}

Node* findNode(Node* node, char* word) {
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

Node* insertOrIncreaseCounter(Node* root, char* word) {
    Node* searchingNode = findNode(root, word);
    if (searchingNode != NULL) {
        searchingNode->count++;
        return searchingNode;
    }
    Node* node = createNode(word);
    node->next = root;
    return node;
}

void freeList(Node** root) {
    Node* current = *root;

    while (current != NULL) {
        Node* temp = current->next;
        free(current->word);
        free(current);
        current = temp;
    }
    *root = NULL;
}

void printList(Node* root) {
    while (root != NULL) {
        printf("%s %d\n", root->word, root->count);
        root = root->next;
    }
}

Node* getNext(Node* node) {
    return node == NULL ? NULL : node->next;
}

int getCount(Node* node) {
    return node == NULL ? 0 : node->count;
}

char* getNodeWord(Node* node) {
    return node != NULL ? node->word : NULL;
}