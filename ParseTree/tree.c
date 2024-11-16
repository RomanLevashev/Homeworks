#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

Node* createNumberNode(int number, Node* left, Node* right) {
    return;
}

Node* buildTree(FILE* file) {
    char current = 0;
    char operation = 0;
    int digit = 0;
    fscanf(file, " %c", &current);
        
    while (current == ')') {
        fscanf(file, " %c", &current);
    }

    if (current == '(') {
        fscanf(file, " %c", &operation);

        Node* node = malloc(sizeof(Node));
        node->operation = operation;
        node->left = buildTree(file);
        node->right = buildTree(file);
        return node;
    }
    else {
        ungetc(current, file);
        fscanf(file, " %d ", &digit);
        
        Node* node = malloc(sizeof(Node));
        node->value = digit;
        node->left = NULL;
        node->right = NULL;

        return node;
    }
}

void freeTree(Node* node) {
    if (node->left != NULL) {
        freeTree(node->left);
    }
    if (node->right != NULL) {
        freeTree(node->right);
    }
    free(node);
}

int evaluateFromTree(Node* node) {
    if (node->left != NULL && node->right != NULL) {
        switch (node->operation) {
        case('+'): return evaluateFromTree(node->left) + evaluateFromTree(node->right);
        case('*'): return evaluateFromTree(node->left) * evaluateFromTree(node->right);
        case('-'): return evaluateFromTree(node->left) - evaluateFromTree(node->right);
        case('/'): return evaluateFromTree(node->left) / evaluateFromTree(node->right);
        }
    }
    else {
        return node->value;
    }
}