#include <stdio.h>

void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main() {
    int x[20], size, i;

    printf("Enter size of an array:");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &x[i]);
    }
    mergesort(x, 0, size - 1);

    printf("Sorted elements:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", x[i]);  // added a space to separate elements
    }

    return 0;
}

void mergesort(int x[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergesort(x, p, q);
        mergesort(x, q + 1, r);
        merge(x, p, q, r);
    }
}

void merge(int x[20], int p, int q, int r) {
    int n1, n2, L[20], R[20], i, j, k;
    n1 = q - p + 1;
    n2 = r - q;

    for (i = 0; i < n1; i++) {
        L[i] = x[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = x[q + 1 + j];
    }

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            x[k] = L[i];
            i++;
        } else {
            x[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        x[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        x[k] = R[j];
        j++;
        k++;
    }
}
