#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b;
    char temp_a, temp_b;
    
    cin>>a;
    cin>>b;
    cout<<a.size()<<" "<<b.size()<<endl;
    cout<<(a+b)<<endl;
    
    temp_a = a[0];
    temp_b = b[0];
    
    a[0] = temp_b;
    b[0] = temp_a;
    
    cout<<a<<" "<<b<<endl;
    
    return 0;
}