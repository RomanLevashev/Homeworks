#include "tree.h"
#include <stdlib.h>

Node* createNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* source, int value) {
    if (source == NULL) {
        return createNode(value);
    }

    if (value > source->value) {
        source->right = insertNode(source->right, value);
    }
    if (value < source->value) {
        source->left = insertNode(source->left, value);
    }
    if (value == source->value) {
        source->count++;
    }
    return source;
}

void inOrderTraversal(Node* source, int* array, int* index) {
    if (source == NULL) {
        return;
    }
    inOrderTraversal(source->left, array, index);
    for (int i = 0; i < source->count; ++i) {
        array[*index] = source->value;
        (*index)++;
    }
    inOrderTraversal(source->right, array, index);
}

void freeTree(Node* source) {
    if (source == NULL) {
        return;
    }
    freeTree(source->left);
    freeTree(source->right);
    free(source);
}

void treeSort(int* array, const int length) {
    Node* root = NULL;
    for (int i = 0; i < length; i++) {
        root = insertNode(root, array[i]);
    }

    int index = 0;
    inOrderTraversal(root, array, &index);
    freeTree(root);
}