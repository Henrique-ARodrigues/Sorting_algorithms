#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Para memcpy
#include "Bubble_sort.h"
#include "Selection_sort.h"
#include "Insertion_sort.h"
#include "Merge_sort.h"
#include "Quick_sort.h"

#define SIZE 10000

int main() {
    int comp, swap;
    clock_t start, end;

    // Para salvar os resultados
    double tempo_bubble, tempo_selection, tempo_insertion, tempo_merge, tempo_quick;
    int comp_bubble, swap_bubble;
    int comp_selection, swap_selection;
    int comp_insertion, swap_insertion;
    int comp_merge, swap_merge;
    int comp_quick, swap_quick;

    int arr_og[SIZE];
    for(int i = 0; i < SIZE; i++) {
        arr_og[i] = rand() % SIZE;
    }

    int arr[SIZE];

    // Bubble Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Bubble_sort(arr, SIZE, &comp, &swap);
    end = clock();
    tempo_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    comp_bubble = comp;
    swap_bubble = swap;
    printf("Bubble Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", tempo_bubble, comp, swap);

    // Selection Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Selection_sort(arr, SIZE, &comp, &swap);
    end = clock();
    tempo_selection = ((double)(end - start)) / CLOCKS_PER_SEC;
    comp_selection = comp;
    swap_selection = swap;
    printf("Selection Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", tempo_selection, comp, swap);

    // Insertion Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Insertion_sort(arr, SIZE, &comp, &swap);
    end = clock();
    tempo_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;
    comp_insertion = comp;
    swap_insertion = swap;
    printf("Insertion Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", tempo_insertion, comp, swap);

    // Merge Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Merge_sort(arr, 0, SIZE - 1, &comp, &swap);
    end = clock();
    tempo_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    comp_merge = comp;
    swap_merge = swap;
    printf("Merge Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", tempo_merge, comp, swap);

    // Quick Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Quick_sort(arr, SIZE, &comp, &swap);
    end = clock();
    tempo_quick = ((double)(end - start)) / CLOCKS_PER_SEC;
    comp_quick = comp;
    swap_quick = swap;
    printf("Quick Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", tempo_quick, comp, swap);

    // Geracao do CSV
    FILE *f = fopen("dados.csv", "w");
    if (!f) {
        perror("Erro ao criar dados.csv");
        return 1;
    }

    fprintf(f, "Algoritmo,Tempo(s),Comparacoes,Trocas\n");
    fprintf(f, "Bubble Sort,%.6f,%d,%d\n", tempo_bubble, comp_bubble, swap_bubble);
    fprintf(f, "Selection Sort,%.6f,%d,%d\n", tempo_selection, comp_selection, swap_selection);
    fprintf(f, "Insertion Sort,%.6f,%d,%d\n", tempo_insertion, comp_insertion, swap_insertion);
    fprintf(f, "Merge Sort,%.6f,%d,%d\n", tempo_merge, comp_merge, swap_merge);
    fprintf(f, "Quick Sort,%.6f,%d,%d\n", tempo_quick, comp_quick, swap_quick);

    fclose(f);

    return 0;
}

