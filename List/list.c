#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Node* createNode(char* word) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->word = word;
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
        (searchingNode->count)++;
        free(word);
        return searchingNode;
    }
    Node* node = createNode(word);
    node->next = root;
    return node;
}

void freeList(Node* root) {
    if (root != NULL) {
        freeList(root->next);
        free(root->word);
        free(root);
    }
}

void printList(Node* root) {
    while (root != NULL) {
        printf("%s %d\n", root->word, root->count);
        root = root->next;
    }
}