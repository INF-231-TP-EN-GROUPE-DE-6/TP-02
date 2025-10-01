#include <stdio.h>
#include <stdlib.h>

// Structure du nœud
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Fonction pour insérer en tête
void insertAtHead(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    newNode->data = data;

    if (*head == NULL) {
        // Liste vide : le nouveau nœud pointe sur lui-même
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        // Trouver la queue (dernier élément)
        Node* tail = (*head)->prev;
        // Insérer le nouveau nœud entre la queue et la tête
        newNode->next = *head;
        newNode->prev = tail;
        (*head)->prev = newNode;
        tail->next = newNode;
        // Mettre à jour la tête
        *head = newNode;
    }
}

// Fonction pour insérer en queue
void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    newNode->data = data;

    if (*head == NULL) {
        // Liste vide : même logique qu'en tête
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        // Trouver la queue (dernier élément)
        Node* tail = (*head)->prev;
        // Insérer le nouveau nœud entre la queue et la tête
        newNode->prev = tail;
        newNode->next = *head;
        tail->next = newNode;
        (*head)->prev = newNode;
    }
}

// Fonction pour afficher la liste (pour test)
void printList(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Fonction principale pour démonstration
int main() {
    Node* head = NULL;

    // Insérer en tête
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    printf("Après insertion en tête : ");
    printList(head);

    // Insérer en queue
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    printf("Après insertion en queue : ");
    printList(head);

    return 0;
}