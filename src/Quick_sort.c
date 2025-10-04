#include <stdio.h>
#include "Quick_sort.h"

void swap(int *a, int *b, int *swap) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    (*swap)++; // conta apenas a troca
}

int acharMedianaDeTres(int arr[], int esquerda, int direita, int *comp, int *swap) {
    int meio = (esquerda + direita) / 2;

    (*comp)++;
    if (arr[esquerda] > arr[meio])
        swap(&arr[esquerda], &arr[meio], swap);

    (*comp)++;
    if (arr[esquerda] > arr[direita])
        swap(&arr[esquerda], &arr[direita], swap);

    (*comp)++;
    if (arr[meio] > arr[direita])
        swap(&arr[meio], &arr[direita], swap);

    return meio; // indice da mediana
}

int particionar(int arr[], int esquerda, int direita, int *comp, int *swap) {
    int i_mediana = acharMedianaDeTres(arr, esquerda, direita, comp, swap);
    int pivo = arr[i_mediana];

    swap(&arr[i_mediana], &arr[direita], swap); // coloca o pivo no fim

    int i = esquerda;
    int j = direita - 1;

    while (j >= i) {
        (*comp)++;
        while (arr[i] < pivo && j >= i) {
            i++;
            (*comp)++;
        }

        (*comp)++;
        while (arr[j] > pivo && j >= i) {
            j--;
            (*comp)++;
        }

        if (j >= i) {
            swap(&arr[i], &arr[j], swap);
            i++;
            j--;
        }
    }

    swap(&arr[i], &arr[direita], swap); // coloca o pivo na posicao final
    return i; // retorna o indice do pivo
}

void ordenarParticao(int arr[], int esquerda, int direita, int *comp, int *swap) {
    if (esquerda < direita) {
        int i_pivo = particionar(arr, esquerda, direita, comp, swap);
        ordenarParticao(arr, esquerda, i_pivo - 1, comp, swap);
        ordenarParticao(arr, i_pivo + 1, direita, comp, swap);
    }
}

void Quick_sort(int arr[], int tamanho, int *comp, int *swap) {
    *comp = 0;
    *swap = 0;
    ordenarParticao(arr, 0, tamanho - 1, comp, swap);
}

