#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    int i, ascii_value;
    char *s;
    
    s = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    i = 0;
    while(s[i]!='\0'){
        ascii_value = s[i];
        if(ascii_value>=48 && ascii_value<=57){
            arr[(int)s[i] - 48] = arr[(int)s[i] - 48] + 1; 
        }
        i++;
    }

    for(i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
