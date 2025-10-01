#include <stdio.h>
#include <stdlib.h>

struct Noeud {
    int data;
    struct Noeud* next;
};

// Fonction pour afficher la liste circulaire
void afficher(struct Noeud* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    struct Noeud* temp = tete;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tete);
    printf("\n");
}

// Insertion en tête
struct Noeud* inserer_tete(struct Noeud* tete, int valeur) {
    struct Noeud* nouveau = malloc(sizeof(struct Noeud));
    nouveau->data = valeur;
    
    if (tete == NULL) {
        nouveau->next = nouveau; // Pointe vers lui-même
        return nouveau;
    }
    
    // Trouver le dernier nœud
    struct Noeud* temp = tete;
    while (temp->next != tete) {
        temp = temp->next;
    }
    
    nouveau->next = tete;
    temp->next = nouveau;
    return nouveau;
}

// Insertion en queue
struct Noeud* inserer_queue(struct Noeud* tete, int valeur) {
    struct Noeud* nouveau = malloc(sizeof(struct Noeud));
    nouveau->data = valeur;
    
    if (tete == NULL) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    // Trouver le dernier nœud
    struct Noeud* temp = tete;
    while (temp->next != tete) {
        temp = temp->next;
    }
    
    temp->next = nouveau;
    nouveau->next = tete;
    return tete;
}

int main() {
    struct Noeud* liste = NULL;
    int choix, valeur;
    
    // Créer liste initiale: 2 -> 3 -> 4 (circulaire)
    liste = inserer_queue(liste, 2);
    liste = inserer_queue(liste, 3);
    liste = inserer_queue(liste, 4);
    
    printf("Liste circulaire initiale: ");
    afficher(liste);
    
    printf("\n1. Insérer en tête\n2. Insérer en queue\nChoix: ");
    scanf("%d", &choix);
    
    printf("Entrez la valeur: ");
    scanf("%d", &valeur);
    
    if (choix == 1) {
        liste = inserer_tete(liste, valeur);
        printf("Après insertion en tête: ");
    } else {
        liste = inserer_queue(liste, valeur);
        printf("Après insertion en queue: ");
    }
    
    afficher(liste);
    
    return 0;
}