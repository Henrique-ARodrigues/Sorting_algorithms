#include <stdio.h>
#include "Bubble_sort.h"


void Bubble_sort(int arr[], int n, int* comp, int* swap) {
    int aux = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            (*comp)++;
            if(arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                (*swap)++;
            }
        }
    }
}
