#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// maxValue - maximum number for range of array values (0 to maxValue)
void sortByCount(int* arr, int size, const int maxValue) {

    int* sortArr = (int*)calloc(maxValue, sizeof(int));

    printf("\n");
    for ( int i = 0; i < size; i++ ) {
        sortArr[arr[i]]++;
    }

    int pos = 0;
    for (int i = 0; i < maxValue; i++) {
        for (int j = 0; j < sortArr[i]; j++) {
            arr[pos] = i;
            pos++;
        }
    }

    free(sortArr);
}

int main(void) {
    int size;
    const int maxValue = 100;

    printf("Elements number: ");
    scanf("%d", &size);
    system("clear");

    int* arr = (int*)malloc(size*sizeof(int));

    srand(time(NULL));
    printf("Before: ");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxValue;
        printf("%d  ", arr[i]);
    }

    sortByCount(arr, size, maxValue);

    printf("\nAfter:  ");
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }

    free(arr);

    return 0;
}