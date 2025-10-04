#include "Selection_sort.h"
#include <stdio.h>


void Selection_sort(int arr[], int n, int* comp, int* swap) {
    int aux = 0;

    for(int i = 0; i < n; i++){
        int atualM = i;
        for(int j = i + 1; j < n; j++) {
            (*comp)++;
            if(arr[j] < arr[atualM]) {
                atualM = j;
            }
        }
        
        aux = arr[atualM];
        arr[atualM] = arr[i];
        arr[i] = aux;
        (*swap)++;
    }
}
