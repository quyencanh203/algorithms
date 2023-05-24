#include <iostream>
#include <vector>

// merge 2 sub-arrays arr[lo..mid] and arr[mid+1..hi]
template<typename T>
void merge(std::vector<T>& arr, std::vector<T>& aux, int lo, int mid, int hi) {
    // copy arr to auxiliary array aux
    for (int k = lo; k <= hi; ++k) {
        aux[k] = arr[k];
    }

    int i = lo, j = mid + 1;
    // merge the 2 sub-arrays into arr
    for (int k = lo; k <= hi; ++k) {
        if      (i > mid)         arr[k] = aux[j++]; // left half exhausted, copy from right half
        else if (j > hi)          arr[k] = aux[i++]; // right half exhausted, copy from left half
        else if (aux[j] < aux[i]) arr[k] = aux[j++]; // current element in right half is smaller, copy from right half
        else                      arr[k] = aux[i++]; // current element in left half is smaller, copy from left half
    }
}

// sort sub-array arr[lo..hi]
template<typename T> 
void merge_sort(std::vector<T>& arr, std::vector<T>& aux, int lo, int hi) {
    if (hi <= lo) return; // base case: sub-array contains at most 1 element

    int mid = lo + (hi - lo) / 2; // compute mid point  

    // recursively sort left and right halves, and merge them
    merge_sort(arr, aux, lo, mid);
    merge_sort(arr, aux, mid+1, hi);
    merge(arr, aux, lo, mid, hi); 
}

// template <typename T>
// void merge_sort(T &array)
// {
//     T aux(array.size());
//     merge_sort(array, aux, 0, array.size() - 1);
// }

int main() {
    std::vector<int> arr = {3,2,1,4,2,5,6,3};
    std::vector<int> aux(arr.size()); // auxiliary array for merge operation
    merge_sort(arr, aux, 0, arr.size() - 1); // sort the entire array

    // print the sorted array
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
