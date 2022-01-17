#
# Author: Daniel Robinson
# Date: 02/12/2021
# Purpose: Advent of Code 2021 - Day 1
#   Part 1: Compare individual depth values and count each time a value increases
#   Part 2: Compare a window of 3 depth values and count each time the sum of the window increases
#

import sys
import time

data = []
depth = 0
count = 0


#
# Part 1
#

# read in depth values
with open('input', 'r') as file:
    for depth in file.read().splitlines():
        data.append(depth)

# Compare individual depth values
for index, current_depth in enumerate(data):
    if index == 0:
        print(data[index],' (N/A - no previous measurement)')
    else: 
        prev_depth = data[index-1]
        if int(current_depth) > int(prev_depth):
            print(data[index],' (increased)')
            count+=1
            print('count = ',count)
            print('index = ',index)
        else:
            print(data[index],' (decreased)')

print('There are ', count, ' measurements that are larger than the previous measurement')


#
# Part 2
#
