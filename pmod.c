/**
 **********************************************************
 * @file    pmod.c
 * @author  Spencer Thacker <thackers@msoe.edu>
 * @class   CPE 2600 121
 * @date    11/12/2024
 * @brief   System call tester, Nice and Sleep
 **********************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    int oldNice = nice(0);  // Get the current nice value
    printf("Old nice value: %d \n", oldNice);
    
    // Modifies its own priority to REDUCE it by 10
    if (nice(10) == -1) {
        // If there is an error when setting the nice
        printf("Error setting nice value \n");
        return 1;
    }
    int newNice = nice(0);  // Get the updated nice value
    printf("New nice value: %d (Priority reduced by 10) \n", newNice);

    // Set up a sleep time of 1,837,272,638 nanoseconds
    struct timespec sleepTime;
    sleepTime.tv_sec = 1;              // 1 second
    sleepTime.tv_nsec = 837272638;     // 837,272,638 nanoseconds

    printf("Sleeping for 1,837,272,638 nanoseconds... \n");
    // Sleeps for 1,837,272,638 nano seconds
    if (nanosleep(&sleepTime, NULL) == -1) {
        printf("Error with nanosleep\n");
        return 1;
    }

    // Prints a goodbye message and exits
    printf("Goodbye!\n");
    exit(1);

    return 0;
}