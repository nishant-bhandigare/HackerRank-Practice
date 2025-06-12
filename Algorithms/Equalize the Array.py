#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equalizeArray' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def equalizeArray(arr):
    # Write your code here
    dictionary = {}
    for key in arr:
        if key not in dictionary:
            dictionary[key] = 1
        else:
            dictionary[key]+=1
            
    maximum = 0
    for key in arr:
        if dictionary[key] > maximum:
            maximum = dictionary[key]
    
    return len(arr) - maximum

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = equalizeArray(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
