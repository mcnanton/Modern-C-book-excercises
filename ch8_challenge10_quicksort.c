// Quick sort in C
// Function by https://www.programiz.com/dsa/quick-sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// main function
int main() {
  
    int my_array[100000];
    srand(123);
    int i;
    for (i = 0; i < 100000; i++) {
        my_array[i] = rand();
    }
    int arr_size = sizeof(my_array)/sizeof(my_array[0]); 
  
    // printf("Unsorted Array\n");
    // printArray(my_array, arr_size);
    
    clock_t start = clock();
    // perform quicksort on data
    quickSort(my_array, 0, arr_size - 1);
    clock_t end = clock();
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
  
    // printf("Sorted array in ascending order: \n");
    // printArray(my_array, arr_size);
}