#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// Complete the following function.

void calculate_the_maximum(int n, int k)
{
    // Write your code here.
    int a, b, max_and = 0, max_or = 0, max_xor = 0;
    int temp_and, temp_or, temp_xor;
    for (a = 1; a < n; a++)
    {
        for (b = a + 1; b <= n; b++)
        {
            temp_and = a & b;
            temp_or = a | b;
            temp_xor = a ^ b;

            if (temp_and > max_and && temp_and < k)
            {
                max_and = temp_and;
            }
            if (temp_or > max_or && temp_or < k)
            {
                max_or = temp_or;
            }
            if (temp_xor > max_xor && temp_xor < k)
            {
                max_xor = temp_xor;
            }
        }
    }
    printf("%d\n%d\n%d", max_and, max_or, max_xor);
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
