#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gemstones' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING_ARRAY arr as parameter.
#

def gemstones(arr):
    # Write your code here
    
    num_of_rocks = len(arr)
    num_of_gemstones = 0
    minerals_list = []
    
    for i in range(0, num_of_rocks):
        for mineral in arr[i]:
            if mineral not in minerals_list:
                minerals_list.append(mineral)
    

    for mineral in minerals_list:
        
        flag = True
        
        for i in range(0, num_of_rocks):
            if mineral not in arr[i]:
                flag = False
                break
                
        if flag is not False:
            num_of_gemstones += 1
            
    return num_of_gemstones
                
        
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr_item = input()
        arr.append(arr_item)

    result = gemstones(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
