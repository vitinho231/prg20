#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Pivô inicial (primeiro elemento)
    int left = low;
    int right = high;

    while (left < right) {
        while (arr[left] <= pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left < right)
            swap(&arr[left], &arr[right]);
    }
    swap(&arr[low], &arr[right]); // Coloca o pivô no lugar certo
    return right;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Índice do pivô
        quicksort(arr, low, pivotIndex - 1); // Ordena a sublista esquerda
        quicksort(arr, pivotIndex + 1, high); // Ordena a sublista direita
    }
}

int main() {
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array desordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    clock_t start_cpu = clock(); // Início da medição de tempo de CPU
    time_t start_time = time(NULL); // Início da medição de tempo real

    quicksort(arr, 0, n - 1);

    clock_t end_cpu = clock(); // Fim da medição de tempo de CPU
    time_t end_time = time(NULL); // Fim da medição de tempo real

    double cpu_time_used = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
    double real_time_used = difftime(end_time, start_time);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTempo de CPU usado: %f segundos\n", cpu_time_used);
    printf("Tempo de execução real: %f segundos\n", real_time_used);

    return 0;
}
