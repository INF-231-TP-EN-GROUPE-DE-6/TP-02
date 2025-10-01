#include <stdio.h>
#include <stdlib.h>

// Structure du nœud
struct node {
    int data;
    struct node* next;
};

// Fonction pour ajouter un élément au début
struct node* ajouter(struct node* tete, int valeur) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = valeur;
    new->next = tete;
    return new;
}

// Fonction pour afficher la liste
void afficher(struct node* tete) {
    struct node* actuel = tete;
    while (actuel != NULL) {
        printf("%d ", actuel->data);
        actuel = actuel->next;
    }
    printf("\n");
}

// Fonction pour supprimer toutes les occurrences
struct node* supprimer_occurrences(struct node* tete, int element) {
    struct node* actuel = tete;
    struct node* precedent = NULL;
    
    // Supprimer les occurrences en début 
    while (actuel != NULL && actuel->data == element) {
        tete = actuel->next;
        free(actuel);
        actuel = tete;
    }
    
    // Supprimer les occurrences 
    while (actuel != NULL) {
        if (actuel->data == element) {
            precedent->next = actuel->next;
            free(actuel);
            actuel = precedent->next;
     } else {
            precedent = actuel;
            actuel = actuel->next;
        }
    }
    
    return tete;
}

int main() {
    struct node* liste = NULL;
    int element;
    
    // Créer la liste
    liste = ajouter(liste, 1);
    liste = ajouter(liste, 3);
    liste = ajouter(liste, 2);
    liste = ajouter(liste, 3);
    liste = ajouter(liste, 5);
    liste = ajouter(liste, 3);
    liste = ajouter(liste, 7);
    
    printf("Liste originale: ");
    afficher(liste);
    
    printf("Entrez l'élément à supprimer: ");
    scanf("%d", &element);
    
    liste = supprimer_occurrences(liste, element);
    
    printf("Liste après suppression: ");
    afficher(liste);
    
    return 0;
}