/*
 * Author: Daniel Robinson
 * Date: 01/12/2021
 * Purpose: Advent of Code 2021 - Day 1
 *   Part 1: Compare individual depth values and count each time a value increases
 *   Part 2: Compare a window of 3 depth values and count each time the sum of the window increases
 */

#include <stdio.h>
#define input_size 2000
#define window_size 3

void compare(int input[]) {
    int count=0;

    /* count how often the current value is larger than the previous */
    for (int i=0; i <= input_size-1; i++) {
        if (i == 0) {
            printf("%d (N/A - no previous measurement)\n", input[i]);
        } else if (input[i] > (input[i-1])) {
            printf("%d (increased)\n", input[++i]);
            count++;
        } else {
            printf("%d (decreased)\n", input[++i]);
        }
    }

    printf("\nThere are %d measurements that are larger than the previous measurement\n", count);
}

void compare_window(int input[]) {
    int count=0;
    int loop_count=0;
    int window_values[input_size];
    int window=0;

    /* sum the value of window_size for comparison */
    while (loop_count <= input_size-window_size) {
        window_values[loop_count] = input[window] + (input[window+1]) + (input[window+2]);
        loop_count++;
        window=loop_count;
    }

    /* reset counters */
    loop_count=0;
    window=0;
    count=0;

    /* compare each window and count the increases */
    while (loop_count < input_size-window_size) {
        if (window == 0) {
            printf("%d (N/A - no previous sum)\n",window_values[window]);
            loop_count++;
        } else if (window_values[window] < (window_values[window+1])) {
            printf("%d (increased)\n",window_values[window]);
            count++;
            loop_count++;
        } else if (window_values[window] > (window_values[window+1])) {
            printf("%d (decreased)\n",window_values[window]);
            loop_count++;
        } else {
            printf("%d (no change)\n",window_values[window]);
            loop_count++;
        }
        window=loop_count;
    }

    printf("\nThere are %d sums that are larger than the previous\n", count);
}

int main(int argc, char *argv[]) {
    int input[input_size];

    /* read depth values from input file */
    if (argc > 1) {
        FILE* file = fopen(argv[1],"r");
            int i=0;
            while (!feof(file)) {
                fscanf(file,"%d", &input[i]);
                i++;
            }
        fclose(file);
    }

    compare(input);
    compare_window(input);

    return 0;
}