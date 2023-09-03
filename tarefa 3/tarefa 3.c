#include <stdio.h>
#include <stdlib.h>

// Função para realizar a fusão de dois subarrays
void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

// Função principal do Merge Sort
void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return; // Array já está ordenado
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, right, mid, size - mid);
}

// Função para realizar o Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr_merge[] = {12, 11, 13, 5, 6, 7};
    int arr_bubble[] = {64, 34, 25, 12, 22, 11, 90};
    int size_merge = sizeof(arr_merge) / sizeof(arr_merge[0]);
    int size_bubble = sizeof(arr_bubble) / sizeof(arr_bubble[0]);

    // Teste 1: Aplicar o Merge Sort
    mergeSort(arr_merge, size_merge);
    printf("Array ordenado usando Merge Sort:\n");
    for (int i = 0; i < size_merge; i++) {
        printf("%d ", arr_merge[i]);
    }
    printf("\n");

    // Teste 2: Aplicar o Bubble Sort
    bubbleSort(arr_bubble, size_bubble);
    printf("Array ordenado usando Bubble Sort:\n");
    for (int i = 0; i < size_bubble; i++) {
        printf("%d ", arr_bubble[i]);
    }
    printf("\n");

    return 0;
}

