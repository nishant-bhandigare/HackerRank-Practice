#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q, k, a, b;
    cin>>n;
    cin>>q;
    
    vector<vector<int>> vec(n);
    
    for(int i=0;i<n;i++){
        cin>>k;
        vec[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>vec[i][j];
        }
    }
    
    for(int i=0;i<q;i++){
        cin>>a;
        cin>>b;
        cout<<vec[a][b]<<endl;
    }
    
    return 0;
}