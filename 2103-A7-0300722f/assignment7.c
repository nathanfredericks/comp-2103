/* 
 * File: assignment7.c
 * Author: Nathan Fredericks 0300722f@acadiau.ca
 * Date: 2024/03/25
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int x;
    struct node *next;
    struct node *prev;
} NodeT, *NodeTP;

typedef struct {
    NodeTP head;
    NodeTP tail;
} ListT, *ListTP;

// Constructs a doubly-linked list and returns the list.
ListTP constructList(void) {
    ListTP p;
    if ((p = malloc(sizeof(ListT))) == NULL) {
        fprintf(stderr, "Error allocating memory for list.\n");
        exit(EXIT_FAILURE);
    }
    p->head = NULL;
    p->tail = NULL;
    return p;
}

// Prints a list from head node to last node.
void printList(ListTP this) {
    if (this->head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    // Traverse from head node to last node, printing each node.
    NodeTP current;
    for (current = this->head; current != NULL; current = current->next)
        printf("%d ", current->x);
    printf("\n");
}

// Prints a list from last node to head node.
void printListReverse(ListTP this) {
    if (this->head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    NodeTP current;
    // Traverse from tail node to head node, printing each node.
    for (current = this->tail; current != NULL; current = current->prev)
        printf("%d ", current->x);
    printf("\n");
}

// Add node to the end of the list.
int addNode(ListTP this, int x) {
    NodeTP node;
    if ((node = malloc(sizeof(NodeT))) == NULL) {
        fprintf(stderr, "Error allocating memory for node.\n");
        return 0;
    };
    node->x = x;
    node->next = NULL;
    if (this->head == NULL) {
        this->head = node;
        this->tail = node;
        node->prev = NULL;
        return 1;
    }
    // Set the tail's next pointer to the new node.
    this->tail->next = node;
    // Set the new node's previous pointer to the tail.
    node->prev = this->tail;
    // Set the tail to the new node
    this->tail = node;
    return 1;
}

// Add a node to the start of the list.
int addToStartOfList(ListTP this, int x) {
    NodeTP node;
    if ((node = malloc(sizeof(NodeT))) == NULL) {
        fprintf(stderr, "Error allocating memory for node.\n");
        return 0;
    };
    if (this->head == NULL) {
        this->head = node;
        this->tail = node;
        node->x = x;
        node->next = NULL;
        node->prev = NULL;
    } else {
        // Set the head's previous pointer to the new node.
        this->head->prev = node;
        // Set the new node's next pointer to the current head.
        node->next = this->head;
        // Set the head to the new node.
        this->head = node;
        node->x = x;
        node->prev = NULL;
    }
    return 1;
}

// Add a node to a position in the list.
int addNodePosition(ListTP this, int x, int pos) {
    if (pos < 0) {
        fprintf(stderr, "Error adding node to position less than zero.\n");
        return 0;
    }
    NodeTP aux, node;
    if ((aux = malloc(sizeof(NodeT))) == NULL) { // Used for traversal through the list.
        fprintf(stderr, "Error allocating memory for aux.\n");
        return 0;
    };
    if ((node = malloc(sizeof(NodeT))) == NULL) {
        fprintf(stderr, "Error allocating memory for node.\n");
        return 0;
    };
    // If the position is the head node.
    if (pos == 0) {
        addToStartOfList(this, x);
        free(node);
        node = NULL;
        free(aux);
        aux = NULL;
        return 1;
    }
    // If the list is empty.
    if (this->head == NULL) {
        this->head = node;
    } else {
        int curr = 0; // Current position.
        // Traverse to the node at the position.
        for (aux->next = this->head; aux->next != NULL && curr != pos; aux = aux->next)
            curr++;
        if (curr != pos) {
            fprintf(stderr, "Error adding node to position exceeding list length.\n");
            return 0;
        }
    }
    node->x = x;
    // Set the node's next pointer to the node after the position.
    node->next = aux->next;
    // Set the node's previous pointer to the node before the position.
    node->prev = aux;
    // If the node after the position is NOT NULL.
    if (aux->next != NULL)
        // Set the node after the position's previous pointer to the new node.
        aux->next->prev = node;
    // Set the node after the position's next pointer to the new node.
    aux->next = node;
    // If the new node is the new tail, set the tail to the new node.
    if (node->next == NULL) {
        this->tail = node;
    }
    return 1;
}

// Delete the head node from the list.
int deleteHeadNode(ListTP this) {
    NodeTP current = this->head;
    if (current == NULL)
        return 0;
    // Set the new head to the node after the current head.
    this->head = current->next;
    // If the new head is NOT NULL, set the new head's previous pointer to NULL.
    if (this->head != NULL)
        this->head->prev = NULL;
    // Free the old head.
    free(current);
    current = NULL;
    return 1;
}

// Delete the first node in the list with value.
int deleteNode(ListTP this, int value) {
    // Check if head node has value
    if (this->head->x == value) {
        deleteHeadNode(this);
        return 1;
    }
    NodeTP aux;
    if ((aux = malloc(sizeof(NodeT))) == NULL) { // Used for traversal through the list.
        fprintf(stderr, "Error allocating memory for aux.\n");
        return 0;
    };
    // Traverse to the node before the node to delete
    for (aux->next = this->head; aux->next != NULL && aux->next->x != value; aux = aux->next)
        ;
    NodeT* del = aux->next; // Node to delete.
    // If the node to delete is NULL, the node cannot be found.
    if (del == NULL) {
        fprintf(stderr, "Error deleting non-existent node.\n");
        return 0;
    }
    // Set the node before the node to delete's next pointer to the node after the node to delete.
    aux->next = aux->next->next;
    // If the next node is NOT NULL, set the next node's previous pointer to the current node.
    if (aux->next != NULL)
        aux->next->prev = aux;
    // If the tail is the node to delete, set the tail to the node.
    if (this->tail == del)
        this->tail = aux;
    free(del);
    del = NULL;
    return 1;
}

// Delete entire list.
int clearList(ListTP this){
    if (this->head == NULL) {
        return 1;
    }
    while (deleteHeadNode(this))
        ;
    this->head = NULL;
    this->tail = NULL;
    return 1;
}

// Delete a node from the list by position.
int deleteNodePosition(ListTP this, int pos) {
    if (pos < 0) {
        fprintf(stderr, "Error deleting node from position less than zero.\n");
        return 0;
    }
    if (pos == 0) {
        // Deleting the head node
        return deleteHeadNode(this);
    }
    NodeTP aux;
    if ((aux = malloc(sizeof(NodeT))) == NULL) { // Used for traversal through the list.
        fprintf(stderr, "Error allocating memory for aux.\n");
        return 0;
    };
    int curr = 0; // Current position.
    // Traverse to the node before the node to be deleted.
    for (aux->next = this->head; aux->next != NULL && curr != (pos); aux = aux->next)
        curr++;
    if (curr != (pos)) {
        fprintf(stderr, "Error deleting node from position exceeding list length.\n");
        return 0;
    }
    NodeT* del = aux->next; // Node to delete.
    // Set the node before the node to delete's next pointer to the node after the node to delete.
    aux->next = aux->next->next;
    // If the next node is NOT NULL, set the next node's previous pointer to the current node.
    if (aux->next != NULL)
        aux->next->prev = aux;
    // If the tail is the node to delete, set the tail to the node.
    if (this->tail == del)
        this->tail = aux;
    free(del);
    del = NULL;
    return 1;
}

int main(void) {
    ListTP p = constructList();

    printf("Print empty list:\n");
    printList(p);

    printf("Add nodes (10, 20, 30, 40, 50) to list:\n");
    addNode(p, 10);
    addNode(p, 20);
    addNode(p, 30);
    addNode(p, 40);
    addNode(p, 50);
    printList(p);

    printf("Print list in reverse:\n");
    printListReverse(p);

    printf("Add node (5) to the start of list:\n");
    addToStartOfList(p, 5);
    printList(p);
    
    printf("Add node (25) at position 2:\n");
    addNodePosition(p, 25, 2);
    printList(p);

    printf("Add node (15) at position 0 (should add to start):\n");
    addNodePosition(p, 15, 0);
    printList(p);

    printf("Add node (35) at negative position (should fail):\n");
    addNodePosition(p, 35, -1);
    printList(p);

    printf("Delete node with value 25:\n");
    deleteNode(p, 25);
    printList(p);

    printf("Delete node with value 100 (non-existent node):\n");
    deleteNode(p, 100);
    printList(p);

    printf("Delete node at position 3:\n");
    deleteNodePosition(p, 3);
    printList(p);

    printf("Delete node at position 0 (should delete head):\n");
    deleteNodePosition(p, 0);
    printList(p);

    printf("Deleting node at negative position (should fail):\n");
    deleteNodePosition(p, -1);
    printList(p);

    printf("Clear list:\n");
    clearList(p);
    printList(p);

    return 0;
}
