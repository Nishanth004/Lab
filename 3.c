//Pivot at last position
#include <stdio.h> 
#include <stdlib.h>  
#include<time.h>

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(int arr[], int low, int high) 
{
  int pivot = arr[high];  // select the last element as pivot
  int i = (low - 1);
  for (int j = low; j < high; j++) 
    if (arr[j] <= pivot) 
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
int main() 
{ 
    int n,l=1;
    clock_t s,e;
    double t;
    printf("How many elements in array?:");
    scanf("%d",&n);
    int arr[1000];
    for(int i = 0 ; i < n ; i++)
    {
     arr[i]=rand()%n-l+1;
    }
    printf("Original array: "); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d ", arr[i]); 
    } 
    s=clock();
    quickSort(arr, 0, n - 1); 
    e=clock();
    printf("\nSorted array: "); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d ", arr[i]); 
    } 
    t=(double)(e-s)/CLOCKS_PER_SEC;
    printf("\n the time taken by pivot at 1st position %lf \n",t);
    return 0; 
}
