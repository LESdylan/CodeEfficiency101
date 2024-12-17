#include <stdlib.h>

// Fonction pour générer un tableau d'entiers aléatoires
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 2001) - 1000; // Valeurs aléatoires entre -1000 et 1000
    }
}
