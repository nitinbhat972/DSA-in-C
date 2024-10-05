#include<stdio.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void showData(int arr[], size_t size){
    printf("Elements: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int isSorted = 1;
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr, j + 1, j);
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int item = arr[i];
        int j = i - 1;
        while(j >= 0 && item < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = item;
    }
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
}



int main(){
    int arr[] = {1, 23, 51, 12, 4, 5};
    size_t size = sizeof(arr)/sizeof(arr[0]);


    showData(arr, size);
    // bubbleSort(arr, size);
    // insertionSort(arr, size);
    selectionSort(arr, size);
    showData(arr, size);

    
    return 0;
}