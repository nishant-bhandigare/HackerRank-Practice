#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'balancedSums' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def balancedSums(arr):
    # Write your code here
    first_half = 0
    second_half = sum(arr)
    
    if len(arr) == 1 or len(arr) == 0:
        return "YES"
    
    for i in range(0, len(arr)):
        item = arr[i]
        
        second_half -= item
        
        if first_half == second_half:
            return "YES"
            break
            
        first_half += item
               
    return "NO"
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = balancedSums(arr)

        fptr.write(result + '\n')

    fptr.close()
