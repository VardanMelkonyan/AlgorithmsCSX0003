#include <stdio.h>

void mergeSort(int *nums, int numsSize);

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7, 0, 8, 2 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, arr_size);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return (0);
}
