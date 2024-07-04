#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n = mid - low + 1;
    int m = high - mid;
    int LeftArr[n], RightArr[m];

    for (i = 0; i < n; i++)
        LeftArr[i] = arr[low + i];
    for (j = 0; j < m; j++)
        RightArr[j] = arr[mid + 1 + j];


    i = 0;
    j = 0;
    k = low;
    while (i < n && j < m) {
        if (LeftArr[i] <= RightArr[j]) {
            arr[k] = LeftArr[i];
            i++;
        }
        else {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < m) {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

void Sort(int arr[], int low, int high)
{
    if (low < high) {
        int mid = low + (high - low) / 2;
        Sort(arr, low, mid);
        Sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int a[10];
    int n=10;

    printf("\nUnsorted array=\n");
	for(int i=0;i<10;i++)
	{
		a[i]=rand()%11;
		printf("%d ",a[i]);
	}
	printf("\n");
	
    Sort(a, 0, n - 1);
    
    printf("\nSorted array is \n");
    for ( int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
