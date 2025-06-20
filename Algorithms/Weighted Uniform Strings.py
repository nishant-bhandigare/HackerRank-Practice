#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'weightedUniformStrings' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER_ARRAY queries
#

def weightedUniformStrings(s, queries):
    # Write your code here
    
    found = set()
    result = []
    
    i=0
    while i < len(s):
        j = i
        value = ord(s[i]) - ord('a') + 1

        # Add all weights for this run of repeated characters
        count = 1
        found.add(value)  # Single character

        while j + 1 < len(s) and s[j] == s[j + 1]:
            j += 1
            count += 1
            found.add(value * count)

        i = j + 1  # move to next segment

    for query in queries:
        if query in found:
            result.append("Yes")
        else:
            result.append("No")

    return result    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    queries_count = int(input().strip())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input().strip())
        queries.append(queries_item)

    result = weightedUniformStrings(s, queries)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
