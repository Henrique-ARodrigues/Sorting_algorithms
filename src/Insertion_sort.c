#include <stdio.h>
#include "Insertion_sort.h"


void Insertion_sort(int arr[], int n, int* comp, int* swap) {
    int aux = 0;

    for(int i = 1; i < n; i++) {
     
        int j = i;

        while(j > 0) {
            (*comp)++;

            if(arr[j] < arr[j - 1]){
                aux = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = aux;
                (*swap)++;

                j--;
            }else {
                break;
            }
        }
    } 

}
