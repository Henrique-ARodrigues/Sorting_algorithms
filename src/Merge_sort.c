#include <stdio.h>
#include "Merge_sort.h"

void Intercalar(int arr[], int inicio1, int inicio2, int fim2, int* comp, int* swap) {    
    int fim1 = inicio2 - 1;
    int i = inicio1;
    int j = inicio2;
    int k = 0;
    int tamanho = fim2 - inicio1 + 1;
    int tmp[tamanho];

    while(i <= fim1 && j <= fim2) {
        (*comp)++;
        if(arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i++;
        }else {
            tmp[k] = arr[j];
            j++;
            (*swap)++;
        }
        k++;
    }

    while (i <= fim1) {
        tmp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= fim2) {
        tmp[k] = arr[j];
        j++;
        k++;
    }

    for (int m = 0; m < tamanho; m++) {
        arr[inicio1 + m] = tmp[m];
    }

}

void Merge_sort(int arr[], int inicio, int fim, int* comp, int* swap) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        Merge_sort(arr, inicio, meio, comp, swap);
        Merge_sort(arr, meio + 1, fim, comp, swap);
        Intercalar(arr, inicio, meio + 1, fim, comp, swap);
    }
}
