#include<iostream>
using namespace std;

void enterString(string a[], int N) {
    for(int i = 0; i < N; i++) {
        cin>>a[i];
    }
}

void radixSort(int a, string aux[], int i) {
         
}

int main() {
    int N;
    cin>>N;
    string a[N];
    enterString(a,N);
    string aux[N];
    int W = sizeof(a[0]);

    // for(int i = W - 1; i--; i>=0) {

    // }

    return 0;
}