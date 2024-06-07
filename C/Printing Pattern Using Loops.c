#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n, i, j, k;
    scanf("%d", &n);
      // Complete the code to print the pattern.
      
    for(i=n;i>=1;i--){
        k=n;
        for(j=1;j<=(n-i);j++){
            printf("%d ", k);
            k--;
        }
        for(j=1;j<=(2*i-1);j++){
            printf("%d ", i);
        }
        k=i+1;
        for(j=1;j<=(n-i);j++){
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }
    for(i=2;i<=n;i++){
        k=n;
        for(j=1;j<=(n-i);j++){
            printf("%d ", k);
            k--;
        }
        for(j=1;j<=(2*i-1);j++){
            printf("%d ", i);
        }
        k=i+1;
        for(j=1;j<=(n-i);j++){
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }
    
    return 0;
}
