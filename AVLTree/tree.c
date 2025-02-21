#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    char* key;
    char* value;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Tree* createTree(void) {
    Tree* tree = calloc(1, sizeof(Tree));
    
    if (tree == NULL) {
        perror("Memory allocate error");
        return NULL;
    }

    return tree;
}

Node* createNode(char key[], char value[]) {
    Node* node = calloc(1, sizeof(Node));

    if (node == NULL) {
        perror("Memory allocate error");
        return NULL;
    }
    node->key = strdup(key);
    if (node->key == NULL) {
        perror("Memory allocate error");
        free(node);
        return NULL;
    }
    node->value = strdup(value);
    if (node->value == NULL) {
        perror("Memory allocate error");
        free(node->key);
        free(node);
        return NULL;
    }
    node->height = 1;

    return node;
}

int getBalanceFactor(Node* node) {
    int leftHeight = node->left != NULL ? node->left->height : 0;
    int rightHeight = node->right != NULL ? node->right->height : 0;

    return rightHeight - leftHeight;
}

void updateHeight(Node* node) {
    int leftHeight = node->left != NULL ? node->left->height : 0;
    int rightHeight = node->right != NULL ? node->right->height : 0;

    node->height = max(leftHeight, rightHeight) + 1;
}

void smallLeftRotate(Node** source) {
    Node* rightChild = (*source)->right;
    (*source)->right = rightChild->left;
    rightChild->left = *source;
    *source = rightChild;
    updateHeight((*source)->left);
    updateHeight(*source);
}

void smallRightRotate(Node** source) {
    Node* leftChild = (*source)->left;
    (*source)->left = leftChild->right;
    leftChild->right = *source;
    *source = leftChild;
    updateHeight((*source)->right);
    updateHeight(*source);
}

void balanceTree(Node** source) {
    int balanceFactor = getBalanceFactor(*source);
    if (abs(balanceFactor) < 2) {
        return;
    }

    if (balanceFactor > 1) {
        Node* current = (*source)->right;
        int rightBalanceFactor = getBalanceFactor(current);
        
        if (rightBalanceFactor >= 0) {
            smallLeftRotate(source);
        }
        else {
            smallRightRotate(&((*source)->right));
            smallLeftRotate(source);
        }
    }

    if (balanceFactor < -1) {
        Node* current = (*source)->left;
        int leftBalanceFactor = getBalanceFactor(current);

        if (leftBalanceFactor <= 0) {
            smallRightRotate(source);
        }
        else {
            smallLeftRotate(&((*source)->left));
            smallRightRotate(source);
        }
    }
}

void deleteNode(Node** nodePointer) {
    Node* node = *nodePointer;

    free(node->key);
    free(node->value);
    free(node);
    *nodePointer = NULL;
}

void insert(Node** source, char key[], char value[], bool* isSuccess) {
    if (*source == NULL) {
        Node* newNode = createNode(key, value);
        if (newNode == NULL) {
            *isSuccess = false;
        }
        *source = newNode;
        return;
    }

    if (strcmp((*source)->key, key) == 0) {
        char* newValue = strdup(value);
        if (newValue == NULL) {
            perror("Memory allocate error");
            *isSuccess = false;
            return;
        }

        free((*source)->value);
        (*source)->value = newValue;

        return;
    }

    if (strcmp((*source)->key, key) == 1) {
        insert(&((*source)->left), key, value, isSuccess);
    }

    if (strcmp((*source)->key, key) == -1) {
        insert(&((*source)->right), key, value, isSuccess);
    }

    if (!*isSuccess) {
        return;
    }

    updateHeight(*source);
    balanceTree(source);
}

char* search(Node* source, char* key) {
    if (source == NULL) {
        return NULL;
    }
    if (strcmp(key, source->key) == 0) {
        return source->value;
    }

    if (strcmp(key, source->key) == 1) {
        return search(source->right, key);
    }

    if (strcmp(key, source->key) == -1) {
        return search(source->left, key);
    }
}

void deleteNodeWithOneChild(Node** nodePointer) {
    Node* node = *nodePointer;
    Node* temp = node->left != NULL? node->left: node->right; 
    deleteNode(nodePointer);
    *nodePointer = temp;
}

Node* findMinInRightSubTreeAndDelete(Node** nodePointer) {
    Node* node = *nodePointer;

    if (node->left == NULL) {
        *nodePointer = node->right;
        return node;
    }

    Node* deletedNode = findMinInRightSubTreeAndDelete(&(node->left));
    updateHeight(node);
    balanceTree(nodePointer);
    return deletedNode;
}

void delete(Node** source, char key[], bool* isSuccess) {
    Node* currentNode = *source;
    if (*source == NULL) {
        *isSuccess = false;
        return;
    }

    int compareResult = strcmp(currentNode->key, key);

    if (compareResult == 0) {
        int childCount = ((*source)->left != NULL) + ((*source)->right != NULL);
        if (childCount == 0) {
            deleteNode(source);
            return;
        }

        if (childCount == 1) {
            deleteNodeWithOneChild(source);
            return;
        }

        if (childCount == 2) {
            Node* temp = findMinInRightSubTreeAndDelete(&(currentNode->right));
            free(currentNode->key);
            free(currentNode->value);
            currentNode->key = temp->key;
            currentNode->value = temp->value;
            free(temp);
        }
    }

    if (compareResult == -1) {
        delete(&(currentNode->right), key, isSuccess);
    }

    if (compareResult == 1) {
        delete(&(currentNode->left), key, isSuccess);
    }

    if (!*isSuccess) {
        return;
    }

    updateHeight(*source);
    balanceTree(source);
}

void deleteTree(Node** source) {
    if (*source == NULL) {
        return;
    }
    deleteTree(&((*source)->left));
    deleteTree(&((*source)->right));
    deleteNode(source);
}

Node** getRootPointer(Tree* tree) {
    return tree != NULL ? &(tree->root): NULL;
}

Node* getLeft(Node* node) {
    return node != NULL ? node->left : NULL;
}

Node* getRight(Node* node) {
    return node != NULL ? node->right : NULL;
}

char* getKey(Node* node) {
    return node != NULL? node->key: NULL;
}