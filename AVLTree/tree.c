#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isDigit(char* str) {
    int i = 0;
    char current = str[i];
    while (current != 0) {
        if (current <= 57 && current >= 48) {
            i += 1;
            current = str[i];
        }
        else {
            return false;
        }
    }
    return true;
}

void preOrder(Node* root) {
    if (root == NULL) return;

    printf("Key: %s, Value: %s, Height: %u\n", root->key, root->value, root->height);

    preOrder(root->left);
    preOrder(root->right);
}

int lenDigit(char* str) {
    int i = 0;
    char current = str[i];
    int length = 0;
    while (current == '0') {
        i += 1;
        current = str[i];
    }
    while (current != 0) {
        length += 1;
        i += 1;
        current = str[i];
    }
    return length;
}

int compare(char* first, char* second, const int length) {
    if (isDigit(first) && isDigit(second)) {
        if (lenDigit(first) > lenDigit(second)) {
            return 1;
        }
        if (lenDigit(first) < lenDigit(second)) {
            return -1;
        }
    }
    for (int i = 0; i < length; ++i) {
        int firstElement = first[i];
        int secondElement = second[i];

        if (firstElement == 0) {
            if ((secondElement != 0)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (secondElement == 0) {
            if ((firstElement != 0)) {
                return -1;
            }
            else {
                return 0;
            }
        }

        if (firstElement > secondElement) {
            return 1;
        }
        if (firstElement < secondElement) {
            return -1;
        }
    }
    return 0;
}

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int updateHeight(Node** nodePointer) {
    Node* node = *nodePointer;
    if (!node) return 0; 

    int leftHeight = updateHeight(&(node->left));
    int rightHeight = updateHeight(&(node->right));

    node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    balanceTree(nodePointer);

    return node->height;
}

int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right): 0;
}

void rightRotate(Node** oldRoot, Node** newRoot) {
    Node* tempRoot = *oldRoot;
    *oldRoot = *newRoot;
    Node* tempRightSubTree = (*newRoot)->right;
    (*oldRoot)->right = tempRoot;
    tempRoot->left = tempRightSubTree;
}

void leftRotate(Node** oldRoot, Node** newRoot) {
    Node* tempRoot = *oldRoot;
    *oldRoot = *newRoot;
    Node* tempLeftSubTree = (*newRoot)->left;
    tempRoot->right = tempLeftSubTree;
    (*oldRoot)->left = tempRoot;
}

Node* balanceTree(Node** nodePointer) {
    Node* node = *nodePointer;
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        int subTreeBalanceFactor = getBalanceFactor(node->left);
        if (subTreeBalanceFactor == 1 || balanceFactor == 0) {
            rightRotate(nodePointer, &(node->left));
        }
        if (subTreeBalanceFactor == -1) {
            leftRotate(&(node->left), &((node->left)->right));
            rightRotate(nodePointer, &(node->left));
            node = *nodePointer;
            updateHeight(nodePointer);
        }
    }
    if (balanceFactor < -1) {
        int subTreeBalanceFactor = getBalanceFactor(node->right);
        if (subTreeBalanceFactor == -1 || balanceFactor == 0) {
            leftRotate(nodePointer, &(node->right));
        }
        if (subTreeBalanceFactor == 1) {
            rightRotate(&(node->right), &((node->right)->left));
            leftRotate(nodePointer, &(node->right));
            node = *nodePointer;
        }
        updateHeight(nodePointer);
    }
    return node;
}

void deleteLeaf(Node* parentDeletedElement, Node* deletedElement) {
    if (parentDeletedElement->left == deletedElement) {
        parentDeletedElement->left = NULL;
    }
    if (parentDeletedElement->right == deletedElement) {
        parentDeletedElement->right = NULL;
    }
    free(deletedElement->value);
    free(deletedElement->key);
    free(deletedElement);
}

void deleteNodeWithOneChild(Node* parentDeletedElement, Node* deletedElement) {
    if (parentDeletedElement->left == deletedElement) {
        if (deletedElement->left != NULL) {
            parentDeletedElement->left = deletedElement->left;
        }
        else {
            parentDeletedElement->left = deletedElement->right;
        }
    }
    if (parentDeletedElement->right == deletedElement) {
        if (deletedElement->left != NULL) {
            parentDeletedElement->right = deletedElement->left;
        }
        else {
            parentDeletedElement->right = deletedElement->right;
        }
    }
    free(deletedElement->value);
    free(deletedElement->key);
    free(deletedElement);
}

void deleteNodeWithTwoChild(Node* deletedElement) {
    Node* minimumRightElement = NULL;
    Node* parentMinimumRightElement = deletedElement;
    Node* current = deletedElement->right;
    Node* previousElement = deletedElement;

    while (current != NULL) {
        char* currentKey = current->key;

        if (minimumRightElement == NULL) {
            minimumRightElement = current;
        }
        else {
            if (compare(currentKey, minimumRightElement->key, 150) == -1) {
                minimumRightElement = current;
                parentMinimumRightElement = previousElement;
            }
        }
        previousElement = current;
        current = current->left;
    }

    if (minimumRightElement->left == NULL && minimumRightElement->right == NULL) {
        free(deletedElement->value);
        free(deletedElement->key);
        deletedElement->value = calloc(150, 1);
        deletedElement->key = calloc(150, 1);
        strncpy(deletedElement->value, minimumRightElement->value, 149);
        strncpy(deletedElement->key, minimumRightElement->key, 149);
        if (parentMinimumRightElement->left == minimumRightElement) {
            parentMinimumRightElement->left = NULL;
        }
        if (parentMinimumRightElement->right == minimumRightElement) {
            parentMinimumRightElement->right = NULL;
        }
        free(minimumRightElement->key);
        free(minimumRightElement->value);
        free(minimumRightElement);
        return;
    }
    free(deletedElement->value);
    free(deletedElement->key);
    deletedElement->value = calloc(150, 1);
    deletedElement->key = calloc(150, 1);
    strncpy(deletedElement->value, minimumRightElement->value, 149);
    strncpy(deletedElement->key, minimumRightElement->key, 149);
    deleteNodeWithOneChild(parentMinimumRightElement, minimumRightElement);
}

Node* delete(Node** nodePointer, Node** root, char* key) {
    Node* node = *nodePointer;
    if (node == NULL) {
        return NULL;
    }
    Node* deletedElement = NULL;
    if (compare((*root)->key, key, 150) == 0) {
        if (node->left == NULL && node->right == NULL) {
            free(node->value);
            free(node->key);
            free(node);
            *nodePointer = NULL;
            return NULL;
        }
        if (node->left != NULL && node->right == NULL) {
            *root = node->left;
            free(node->value);
            free(node->key);
            free(node);
            return NULL;
        }
        if (node->right != NULL && node->left == NULL) {
            root = node->right;
            free(node->value);
            free(node->key);
            free(node);
            return NULL;
        }
        deletedElement = *root;
    }
    if (node == NULL) {
        return;
    }
    int result = compare(key, (*nodePointer)->key, 150);

    if (result == -1) {
        deletedElement = delete(&(node->left), root, key);
    }
    if (result == 1) {
        deletedElement = delete(&(node->right), root, key);
    }
    if (result == 0 && compare((*root)->key, key, 150) != 0) {
        return node;
    }
    if (deletedElement != NULL) {
        if (deletedElement->left == NULL && deletedElement->right == NULL) {
            deleteLeaf(node, deletedElement);
            updateHeight(nodePointer);
            return NULL;
        }

        if (deletedElement->left != NULL && deletedElement->right != NULL) {
            deleteNodeWithTwoChild(deletedElement);
            updateHeight(nodePointer);
            return NULL;
        }

        if (deletedElement->left != NULL || deletedElement->right != NULL) {
            deleteNodeWithOneChild(node, deletedElement);
            updateHeight(nodePointer);
            return NULL;
        }
    }
    return NULL;
}

Node* insert(Node** nodePointer, char* key, char* value) {
    Node* node = *nodePointer;
    if (node == NULL) {
        Node* newNode = malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->height = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        *nodePointer = newNode;
        return newNode;
    }

    int result = compare(key, node->key, 150);

    if (result == -1) {
        node->left = insert(&(node->left), key, value);
        updateHeight(nodePointer);
    }
    if (result == 1) {
        node->right = insert(&(node->right), key, value);
        updateHeight(nodePointer);
    }
    if (result == 0) {
        free(node->value);
        node->value = value;
    }
    
    return *nodePointer;
}

char* search(Node* source, char* key) {
    Node* current = source;

    while (current != NULL) {
        char* currentKey = current->key;
        if (compare(currentKey, key, 150) == 0) {
            return current->value;
        }
        if (compare(currentKey, key, 150) == -1) {
            if (current->right == NULL) {
                return NULL;
            }
            current = current->right;
        }
        if (compare(currentKey, key, 150) == 1) {
            if (current->left == NULL) {
                return NULL;
            }
            current = current->left;
        }
    }
    return NULL;
}

void freeTree(Node** source) {
    Node* node = *source;
    if (node == NULL) {
        return;
    }
    freeTree(&(node->left));
    freeTree(&(node->right));
    free(node->key);
    free(node->value);
    free(node);
    *source = NULL;
}