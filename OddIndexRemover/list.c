#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* createList(char* source) {
    Node* head = NULL;
    Node* tail = NULL;
    int temp = 0;

    while (source != NULL && *source == ' ' && *source != '\0') {
        source++;
    }

    while (sscanf(source, " %d ", &temp) == 1) {
        Node* node = malloc(sizeof(Node));
        if (node == NULL) {
            Node* current = head;
            while (current != NULL) {
                Node* tempNode = current->next;
                free(current);
                current = tempNode;
            }
            perror("Memory allocate error");
            return NULL;
        }
        node->next = NULL;
        node->value = temp;
        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        while (source != NULL && *source == ' ' && *source != '\0') {
            source++;
        }
        while (source != NULL && *source != ' ' && *source != '\0') {
            source++;
        }
    }
    return head;
}

void deleteOddIndex(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        Node* nodeToDelete = current->next; 
        current->next = nodeToDelete->next; 
        free(nodeToDelete);                

        current = current->next;          
    }
}

void freeList(Node** source) {
    if (*source == NULL) {
        return;
    }
    freeList(&((*source)->next));
    free(*source);
    *source = NULL;
}