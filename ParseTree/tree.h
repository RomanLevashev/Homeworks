#pragma once
#include <stdio.h>

typedef struct Node {
    union {
        int value;
        char operation;
    };
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

 Node* buildTree(FILE* file);
 int evaluateFromTree(Node* node);
 void freeTree(Node* node);