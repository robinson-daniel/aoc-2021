/*
 * Author: Daniel Robinson
 * Date: 02/12/2021
 * Purpose: Advent of Code 2021 - Day 2
 *   Part 1: Keep track of your position and provide the multiplication of final horizontal/depth
 *   Part 2: The rules changed. Attempted to do it with minimal code then ended up playing with #ifdefs making it very ugly
 */

#include <stdio.h>
#include <string.h>
#define input_size 1000
#define max_action 8
//#define __part1__
#define __part2__

int main(int argc, char *argv[]) {
    #ifdef __part2__
        int aim=0;
    #endif

    int input[input_size];
    char action[max_action];
    int horizontal=0, depth=0;
    char forward[] = "forward", down[] = "down", up[] = "up";

    /* read sub position from input file & record values as we go */
    if (argc > 1) {
        FILE* file = fopen(argv[1],"r");
            int i=0;
            while (!feof(file)) {
                fscanf(file,"%s %d", action, &input[i]);
                if ((strcmp(action,forward)) == 0) {
                    printf("%s, %d\n", action, input[i]);
                    horizontal += input[i];
                    #ifdef __part2__
                        depth += (aim * input[i]);
                    #endif
                } else if ((strcmp(action,down)) == 0) {
                    printf("%s, %d\n", action, input[i]);
                    #ifdef __part1__
                        depth += input[i];
                    #endif
                    #ifdef __part2__
                        aim += input[i];
                    #endif

                } else if ((strcmp(action,up)) == 0) {
                    printf("%s, %d\n", action, input[i]);
                    #ifdef __part1__
                        depth -= input[i];
                    #endif
                    #ifdef __part2__
                        aim -= input[i];
                    #endif
                }
                i++;
            }
            printf("Multiply horizontal with depth: %d\n", horizontal * depth);
        fclose(file);
    }

    return 0;
}