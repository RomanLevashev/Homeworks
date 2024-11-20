#include "tree.h"
#include <stdlib.h>
#include <string.h>

Node* createNode(int key, char* value) {
    Node* newElement = malloc(sizeof(Node));
    if (newElement == NULL) {
        return NULL;
    }
    newElement->key = key;
    newElement->value = value;
    newElement->left = NULL;
    newElement->right = NULL;

    return newElement;
}

void insert(Node** source, int key, char* value) {
    if (*source == NULL) {
        *source = createNode(key, value);
        return;
    }
    Node* current = *source;
    while (current != NULL) {
        int currentKey = current->key;
        if (currentKey == key) {
            free(current->value);
            current->value = value;
            return;
        }
        if (currentKey < key) {
            if (current->right == NULL) {
                current->right = createNode(key, value);
                return;
            }
            current = current->right;
        }
        if (currentKey > key) {
            if (current->left == NULL) {
                current->left = createNode(key, value);
                return;
            }
            current = current->left;
        }
    }
}

char* search(Node* source, int key) {
    Node* current = source;

    while (current != NULL) {
        int currentKey = current->key;
        if (currentKey == key) {
            return current->value;
        }
        if (currentKey < key) {
            if (current->right == NULL) {
                return NULL;
            }
            current = current->right;
        }
        if (currentKey > key) {
            if (current->left == NULL) {
                return NULL;
            }
            current = current->left;
        }
    }
    return NULL;
}

void deleteLeaf(Node* parentDeletedElement, Node* deletedElement) {
    if (parentDeletedElement->left == deletedElement) {
        parentDeletedElement->left = NULL;
    }
    if (parentDeletedElement->right == deletedElement) {
        parentDeletedElement->right = NULL;
    }
    free(deletedElement->value);
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
    free(deletedElement);
}

void deleteNodeWithTwoChild(Node* deletedElement) {
    Node* minimumRightElement = NULL;
    Node* parentMinimumRightElement = deletedElement;
    Node* current = deletedElement->right;
    Node* previousElement = deletedElement;

    while (current != NULL) {
        int currentKey = current->key;

        if (minimumRightElement == NULL) {
            minimumRightElement = current;
        }
        else {
            if (currentKey < minimumRightElement->key) {
                minimumRightElement = current;
                parentMinimumRightElement = previousElement;
            }
        }
        previousElement = current;
        current = current->left;
    }

    if (minimumRightElement->left == NULL && minimumRightElement->right == NULL) {
        free(deletedElement->value);
        deletedElement->value = minimumRightElement->value;
        deletedElement->key = minimumRightElement->key;
        if (parentMinimumRightElement->left == minimumRightElement) {
            parentMinimumRightElement->left = NULL;
        }
        if (parentMinimumRightElement->right == minimumRightElement) {
            parentMinimumRightElement->right = NULL;
        }
        free(minimumRightElement);
        return;
    }
    free(deletedElement->value);
    deletedElement->value = calloc(150, 1);
    strncpy(deletedElement->value, minimumRightElement->value, 149);
    deletedElement->key = minimumRightElement->key;
    deleteNodeWithOneChild(parentMinimumRightElement, minimumRightElement);
}

void delete(Node** source, int key) {
    Node* current = *source;
    Node* deletedElement = NULL;
    Node* parentDeletedElement = NULL;

    while (current != NULL) {
        int currentKey = current->key;
        if (key == currentKey) {
            if (current->left != NULL && current->right != NULL) {
                deletedElement = current;
                break;
            }
            if (current->left != NULL && current->right == NULL) {
                *source = current->left;
                free(current->value);
                free(current);
                return;
            }
            if (current->right != NULL && current->left == NULL) {
                *source = current->right;
                free(current->value);
                free(current);
                return;
            }
            if (current->right == NULL && current->left == NULL) {
                free(current->value);
                free(current);
                *source = NULL;
                return;
            }
        }
        if (key < currentKey) {
            Node* nextElement = current->left;
            if (nextElement != NULL && nextElement->key == key) {
                deletedElement = nextElement;
                parentDeletedElement = current;
                break;
            }
            else {
                current = current->left;
            }
        }
        if (key > currentKey) {
            Node* nextElement = current->right;
            if (nextElement != NULL & nextElement->key == key) {
                deletedElement = nextElement;
                parentDeletedElement = current;
                break;
            }
            else {
                current = current->right;
            }
        }
    }
    if (deletedElement) {
        if (deletedElement->left == NULL && deletedElement->right == NULL) {
            deleteLeaf(parentDeletedElement, deletedElement);
            return;
        }
        if (deletedElement->left != NULL && deletedElement->right != NULL) {
            deleteNodeWithTwoChild(deletedElement);
            return;
        }
        if (deletedElement->left == NULL || deletedElement->right == NULL) {
            deleteNodeWithOneChild(parentDeletedElement, deletedElement);
        }
    }
}