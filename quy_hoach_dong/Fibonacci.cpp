
// quy hoach dong _ dung de quy co gi nho _ fibonacci
/*
#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n);
}// Evaluate algorithms: thuat toan nay chua toi uu co cau truc giong cay nhi phan do phuc tap O(2^n).
*/ 
//==============================================================================
/*
#include<bits/stdc++.h>
using namespace std;
int res[1000]; // tao mang ghi nho 
 
int fib(int n) {
    if(n == 0 || n == 1) return n;  
    if(res[n] == 0) res[n] = fib(n-1) + fib(n-2); // neu de quy khong lap lai thi res[n] == 0=> gan res[n] cho fib(n-1) + fib(n-2)
    else return res[n]; // nguoc lai tra ve gi tri res[n] ngung de quy nhanh de quy nay
    return res[n]; // tra ve so fib can tim
}

int main() {
    
    int n;
    cin>>n;
    memset(res,0,n);
    cout<<fib(n);
    return 0;
}// Evaluate algorithms : thuat toan se co do phuc tap O(2N)
*/ 
//==============================================================================
/*
#include<bits/stdc++.h>
using namespace std;
int res[1000]; // tao mang 1000 phan tu luu cac so fib 
int fib(int n) {
    res[0] = 0; 
    res[1] = 1;
    for(int i = 2; i <= n; i++) { // dung vong for de luu cac so fib 
        res[i] = res[i-1]+ res[i-2];
    }
    return res[n];// tra ve kq can tim
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}
// Evaluate algorithms : do phuc tap bo nho O(n); do phuc tap thuat toan O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    int fibN;
    int first = 0;
    int second = 1;
    for (int i = 2; i <= n; i++) {
        fibN = first + second;
        first = second;
        second = fibN;
    }
    return fibN;
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}
// Evaluate algorithms: do phuc tap thuat toan luon la 3N do phuc tap bo nho 3.