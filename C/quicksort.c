#include <stdio.h>

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int x[20], size, i;

    printf("Enter size of an array:");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &x[i]);
    }

    quicksort(x, 0, size - 1);

    printf("Sorted Elements:");
    for (i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }

    return 0;
}

void quicksort(int x[], int first, int last) {
    int mid;

    if (first < last) {
        mid = partition(x, first, last);
        quicksort(x, first, mid - 1);
        quicksort(x, mid + 1, last);
    }
}
int partition(int x[], int p, int r) {
    int value, i, j, temp;
    value = x[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++) {
        if (x[j] <= value) {
            i = i + 1;
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }
    temp = x[i + 1];
    x[i + 1] = x[r];
    x[r] = temp;

    return (i + 1);
    
}
