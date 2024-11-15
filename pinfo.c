/**
 **********************************************************
 * @file    pinfo.c
 * @author  Spencer Thacker <thackers@msoe.edu>
 * @class   CPE 2600 121
 * @date    11/12/2024
 * @brief   Gets PID information
 * @note    Takes in a lineparameter of a PID
 **********************************************************
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    // Take a single command lineparameter that is a process identifier
    if (argc == 2) {
        pid = atoi(argv[1]);
    } else if (argc == 1) {
        // If the user does NOT specify a process identifier, print the information for the CURRENT executing process.
        pid = getpid();
    }

    // For that process identifier, print out:
    // The process priority
    int priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1) {
        printf("Error RetrievingPr iority\n");
        return 1;
    }
    printf("Process Priority: %d \n", priority);
    //- The scheduling method

    int scheduling = sched_getscheduler(pid);
    if (scheduling == -1) {
        printf("Error retrieving scheduling method\n");
        return 1;
    }

    // uses variables included in the sched.h package to find what scheduling Method is used
    switch (scheduling) {
        case SCHED_OTHER:
            printf("Scheduling Method: Normal \n");
            break;
        case SCHED_FIFO:
            printf("Scheduling Method: FIFO \n");
            break;
        case SCHED_RR:
            printf("Scheduling Method: Round Robin \n");
            break;
        case SCHED_BATCH:
            printf("Scheduling Method: Batch \n");
            break;
        case SCHED_IDLE:
            printf("Scheduling Method: Idle \n");
            break;
        case SCHED_DEADLINE:
            printf("Scheduling Method: Deadline \n");
            break;
        default:
            printf("Unknown Scheduling Method \n");
    }
    return 0;
}

