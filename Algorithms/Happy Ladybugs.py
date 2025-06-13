#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'happyLadybugs' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING b as parameter.
#

def happyLadybugs(b):
    # Write your code here
    record = {}
    flag = True
    for key in b:
        if key not in record:
            record[key] =1
        else:
            record[key]+=1
            
    if "_" not in record.keys():
        flag2 = True
        for i in range(len(b)):
            if (i > 0 and b[i] == b[i - 1]) or (i < len(b) - 1 and b[i] == b[i + 1]):
                continue
            else:
                flag2 = False
                break
                
        if flag2 is False:
            return "NO"
        else:
            return "YES"
    else:
        for key in record:
            if record[key] == 1 and key != "_":
                flag = False
                break
                
        if flag is True:
            return "YES"
        else:
            return "NO"
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g = int(input().strip())

    for g_itr in range(g):
        n = int(input().strip())

        b = input()

        result = happyLadybugs(b)

        fptr.write(result + '\n')

    fptr.close()
