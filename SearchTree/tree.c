#include "tree.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node { 
    int key;
    char* value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree { 
    Node* root;
} Tree;

Tree* getTree(void) {
    Tree* tree = calloc(1, sizeof(Tree));
    return tree;
}

Node** getRootPointer(Tree* tree) {
    return &(tree->root);
}

int getKey(Node* node) {
    return node->key;
}

Node* createNode(int key, char* value) {
    Node* newElement = malloc(sizeof(Node));
    if (newElement == NULL) {
        perror("Ошибка выделения памяти");
        return NULL;
    }
    newElement->key = key;
    newElement->value = strdup(value);
    if (newElement->value == NULL) {
        perror("Ошибка выделения памяти");
        free(newElement);
        return NULL;
    }
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
            current->value = strdup(value);
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
    deletedElement->value = strdup(minimumRightElement->value);
    deletedElement->key = minimumRightElement->key;
    deleteNodeWithOneChild(parentMinimumRightElement, minimumRightElement);
}

void freeNode(Node* node) {
    free(node->value);
    free(node);
    return;
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
                freeNode(current);
                return;
            }
            if (current->right != NULL && current->left == NULL) {
                *source = current->right;
                freeNode(current);
                return;
            }
            if (current->right == NULL && current->left == NULL) {
                freeNode(current);
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

void freeTree(Tree** tree, Node** source) {
    if (*source == NULL) {
        return;
    }
    freeTree(tree, &((*source)->left));
    freeTree(tree, &((*source)->right));
    if (&((*tree)->root) == source) {
        freeNode(*source);
        free(*tree);
        *tree = NULL;
        return;
    }
    freeNode(*source);
    *source == NULL;
}