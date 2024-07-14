#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int *arr, int n){
    for(int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1]; 
        arr[n-i-1] = temp;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    int *a = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    reverse(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}