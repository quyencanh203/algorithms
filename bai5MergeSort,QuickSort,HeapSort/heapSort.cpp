#include<iostream>
using namespace std;

void sink(int arr[], int k, int n) // thuat toan sap xep va hoan doi vi tri
{
	while(2*k+1 < n){
		int j = 2*k + 1;
		if(j+1 < n && arr[j] < arr[j+1]) j++;
		if (arr[j] < arr[k]) break;
		swap(arr[j], arr[k]);
		k = j;
	}
} 

void heap_sort(int arr[],int n) {
	
	for(int k = n/2 ; k>=0; --k) // het vong for nay thi cay heap da ve dung vi tri
	    sink(arr,k,n);
	
	while(n > 1) // dua phan tu max ve cuoi mang arr va tiep tuc sap xep lai cay heap
	{
		swap(arr[0], arr[--n]); //dua phan tu cuoi cay len dau va tiep tuc sx lai
		sink(arr, 0, n);
	}
}

int main(){
	int arr[] = {7, 3, 6, 5, 4, 10, 2};
		int n = sizeof(arr) / sizeof(int) ;
	heap_sort(arr, n);
	
	for(int i = 0; i< n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
