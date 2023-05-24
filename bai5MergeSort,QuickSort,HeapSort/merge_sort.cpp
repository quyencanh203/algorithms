#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, vector<int> &aux, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;
    for(int k = lo; k <= hi; k++) 
    {
        aux[k] = arr[k]; //copy.
    }
    for(int k = lo; k <= hi; ++k) 
    {
        if     (i > mid)         arr[k] = aux[j++];
        else if(j > hi)          arr[k] = aux[i++];
        else if(aux[j] < aux[i]) arr[k] = aux[j++];
        else                     arr[k] = aux[i++];
    }
}

void merge_sort(vector<int> &arr, vector<int> &aux, int lo, int hi)
{
    if(lo >= hi) return;// base case
    int mid = lo + (hi - lo)/2;
    merge_sort(arr, aux, lo, mid);
    merge_sort(arr, aux, mid + 1, hi);
    merge(arr, aux, lo, mid, hi);
}

int main()
{
vector<int> arr = {3, 2, 1, 4, 2, 5, 6, 3};
vector<int> aux(arr.size());
merge_sort(arr, aux, 0, arr.size() - 1); // sort the entire array

    // print the sorted array
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}