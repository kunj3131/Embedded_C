#include <stdio.h>

void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n){
    int isSorted = 0;
    for(int i=0; i<n-1;i++){
        printf("number of pass %d \n", i+1);
        printArray(a,n);
        isSorted = 1;
        for(int j=0;j<n-1-i;j++){
            if(a[j]<a[j+1]){
                int temp = 0;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

void insertionSort(int *a, int n){
    int key, j;
    for(int i=1; i <= n-1; i++){
        key = a[i];
        j = i-1;

        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void selectionSort(int *a, int n){
    for(int i=0; i<n-1; i++){
        int indexMin = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[indexMin]){
                indexMin = j;
            }
        }
        int temp = a[i];
        a[i] = a[indexMin];
        a[indexMin] = temp;
    }
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while(a[i] <= pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while(i<j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int low, int high, int n){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition(a, low, high);
        printArray(a,n);
        quickSort(a, low, partitionIndex-1, n);
        quickSort(a, partitionIndex+1, high, n);
    }
}

void merge(int a[], int mid, int low, int high){
    int i, j, k, b[100];
    i = low;
    j = mid+1;
    k = low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++; k++;
        }
        else{
            b[k] = a[j];
            j++; k++;
        }
    }
    while (i<=mid)
    {
       b[k] = a[i];
       k++; i++;
    }
    while (j<=high){
        b[k] = a[j];
        k++;
        j++;
    }
    for(int i=low; i<=high; i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, mid, low, high);
    }
}

int main(){
    // int a[] = {100,5,9,20,21};
    // int a[] = {1,2,3,4,5};
    // int a[] = {12, 54, 65, 7, 23};
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a,n);
    // bubbleSort(a,n);
    // insertionSort(a,n);
    // quickSort(a, 0, n-1, n);
    mergeSort(a, 0, n-1);
    printArray(a,n);
}