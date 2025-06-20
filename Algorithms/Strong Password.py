#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumNumber' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING password
#

def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"
    
    count = 0
    numFlag = False
    lcFlag = False
    ucFlag = False
    scFlag = False
    
    for letter in password:
        if letter in numbers:
            numFlag = True
        elif letter in lower_case:
            lcFlag = True
        elif letter in upper_case:
            ucFlag = True
        elif letter in special_characters:
            scFlag = True
            
        
    if numFlag is not True:
        count+=1
    if lcFlag is not True:
        count+=1
    if ucFlag is not True:
        count+=1
    if scFlag is not True:
        count+=1
        
    if (n + count)<6:
        return (6-n)
    else:
        return count 
    
            
        
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()
