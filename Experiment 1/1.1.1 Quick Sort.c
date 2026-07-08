/*Write a program to sort an array of length n using the Quick Sort algorithm. The program should read the array elements and print the array before and after sorting.*/

#include <stdio.h>


void quickSort(int arr[], int low, int high) {
	if (low < high){
		int pivot = arr[high];
		int i = low - 1, temp;

		for ( int j = low; j < high; j++){
			if (arr[j] < pivot){
				i++;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		
		temp = arr[i+1];
		arr[i +1] = arr[high];
		arr[high] = temp;

		int pi = i + 1;

		quickSort(arr, low, pi -1);
		quickSort(arr, pi + 1, high);
	}
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    printArray(arr, n);


    quickSort(arr, 0, n - 1);
    
   
    printArray(arr, n);

    return 0;
}
