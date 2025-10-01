#include <stdio.h>
#include <stdlib.h>

struct Noeud {
    int data;
    struct Noeud* next;
};

int main() {
    // Créer liste triée: 1 -> 3 -> 5 -> 7
    struct Noeud* n1 = malloc(sizeof(struct Noeud));
    struct Noeud* n2 = malloc(sizeof(struct Noeud));
    struct Noeud* n3 = malloc(sizeof(struct Noeud));
    struct Noeud* n4 = malloc(sizeof(struct Noeud));
    
    n1->data = 1; n1->next = n2;
    n2->data = 3; n2->next = n3;
    n3->data = 5; n3->next = n4;
    n4->data = 7; n4->next = NULL;
    
    struct Noeud* tete = n1;
    int element;

    printf("Liste triée : 1, 3, 5, 7 \n");
    printf("Entrez l'élément à insérer: ");
    scanf("%d", &element);
    
    // Afficher liste originale
    printf("Liste triée: ");
    struct Noeud* temp = tete;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    // Créer nouveau nœud
    struct Noeud* nouveau = malloc(sizeof(struct Noeud));
    nouveau->data = element;
    
    // Cas 1: Insérer au début
    if (tete == NULL || element < tete->data) {
        nouveau->next = tete;
        tete = nouveau;
    } else {
        // Cas 2: Trouver la position
        struct Noeud* actuel = tete;
        while (actuel->next != NULL && actuel->next->data < element) {
            actuel = actuel->next;
        }
        nouveau->next = actuel->next;
        actuel->next = nouveau;
    }
    
    // Afficher nouvelle liste
    printf("Après insertion de %d: ", element);
    temp = tete;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    return 0;
}