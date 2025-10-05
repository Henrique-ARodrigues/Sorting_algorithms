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
    int comp, swap;//compara as verificacoes; recebe a quantidade de trocas;
    clock_t start, end;
    double cpu_time; //Recebe o tempo de uso da cpu em cada chamada de funcao

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
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", cpu_time, comp, swap);

    // Selection Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Selection_sort(arr, SIZE, &comp, &swap);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", cpu_time, comp, swap);

    // Insertion Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Insertion_sort(arr, SIZE, &comp, &swap);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", cpu_time, comp, swap);

    // Merge Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Merge_sort(arr, 0, SIZE - 1, &comp, &swap);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", cpu_time, comp, swap);

    // Quick Sort
    memcpy(arr, arr_og, sizeof(arr_og));
    comp = swap = 0;
    start = clock();
    Quick_sort(arr, SIZE, &comp, &swap);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %.6f seconds | Comparisons: %d | Swaps: %d\n", cpu_time, comp, swap);

    return 0;
}

