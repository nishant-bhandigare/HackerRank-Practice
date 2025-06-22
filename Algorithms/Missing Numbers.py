#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'missingNumbers' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER_ARRAY brr
#

def missingNumbers(arr, brr):
    # Write your code here
    missing = []
    brr_dictionary = {}
    arr_dictionary = {}
    
    for item in brr:
        if item not in brr_dictionary:
            brr_dictionary[item] = 1
        else:
            brr_dictionary[item] += 1
            
    for item in arr:
        if item not in arr_dictionary:
            arr_dictionary[item] = 1
        else:
            arr_dictionary[item] += 1
            
    for key in brr_dictionary:
        if key not in arr_dictionary.keys():
            missing.append(key)
        elif key in arr_dictionary.keys() and arr_dictionary[key] < brr_dictionary[key]:
            missing.append(key)
            
    missing.sort()
    return missing

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    m = int(input().strip())

    brr = list(map(int, input().rstrip().split()))

    result = missingNumbers(arr, brr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
