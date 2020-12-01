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

    int* arr = (int*)malloc(size*sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxValue;
    }

    clock_t t0, t1;
    //Начать измерение
    t0 = clock()*1000/CLOCKS_PER_SEC;

    //Выполнить измеряемое действие
    sortByCount(arr, size, maxValue);

    //Завершить измерение
    t1 = clock()*1000/CLOCKS_PER_SEC;

    //Печатаем время сортировки в милисекундах
    printf("Real time for sorting %i(ms)\n", t1-t0);

    free(arr);

    return 0;
}