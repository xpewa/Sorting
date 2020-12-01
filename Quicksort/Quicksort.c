#include <stdio.h>

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
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    Quicksort(a, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
