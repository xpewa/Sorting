#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a1, int *a2){
    int temp;
    temp=*a1;
    *a1=*a2;
    *a2=temp;
}

void Quicksort(int *a,int first,int last){
    int i, j, pivot;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(a[i]<=a[pivot]&&i<last)
            i++;
            while(a[j]>a[pivot])
            j--;
            if(i<j){
                swap(&a[i], &a[j]);
            }
        }

        swap(&a[pivot], &a[j]);
        Quicksort(a,first,j-1);
        Quicksort(a,j+1,last);
    }
}

int main()
{
    int size;

    printf("Elements number: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size*sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; //любые числа
    }

    clock_t t0, t1;
    //Начать измерение
    t0 = clock()*1000/CLOCKS_PER_SEC;

    //Выполнить измеряемое действие
    Quicksort(arr, 0, size-1);

    //Завершить измерение
    t1 = clock()*1000/CLOCKS_PER_SEC;

    //Печатаем время сортировки в милисекундах
    printf("Real time for sorting %i(ms)\n", t1-t0);

    free(arr);

    return 0;
}