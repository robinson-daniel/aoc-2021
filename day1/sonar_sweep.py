#
# Author: Daniel Robinson
# Date: 02/12/2021
# Purpose: Advent of Code 2021 - Day 1
#   Part 1: Compare individual depth values and count each time a value increases
#   Part 2: Compare a window of 3 depth values and count each time the sum of the window increases
#

import sys

data = []
depth = 0
count = 0
input_size = 2000
window_size = 3

#
# Part 1
#

# read in depth values
try:
    with open('/home/dan/src/adventofcode-2021/day1/input', 'r') as file:
        for depth in file.read().splitlines():
            data.append(depth)
except FileNotFoundError:
    sys.exit('File not found!')

# Compare individual depth values
for index, current_depth in enumerate(data):
    if index == 0:
        print(f'{data[index]} (N/A - no previous measurement)')
    else: 
        prev_depth = data[index-1]
        if int(current_depth) > int(prev_depth):
            print(f'{data[index]} (increased)')
            count+=1
        else:
            print(f'{data[index]} (decreased)')

# Print part 1 result
print(f'There are {count} measurements that are larger than the previous measurement')


#
# Part 2
# 

# Compare three-measurement sliding window of depth values
index=0
current_depth=0

for index, current_depth in enumerate(data):
    if index == 0:
        if (index < 1997): current_window = current_depth + data[index+1] + data[index+2]
        print(f'{current_window} (N/A - no previous measurement)')
    else:
        if (index < 1997): 
            current_window = current_depth + data[index+1] + data[index+2]
            next_window = data[index+1] + data[index+2] + data[index+3]

        if int(current_window) < int(next_window):
            print(f'{current_window} (decreased)')
        else:
            print(f'{current_window} (increased)')
            count+=1

# Print part 1 result
print(f'There are {count} sums that are larger than the previous sum')