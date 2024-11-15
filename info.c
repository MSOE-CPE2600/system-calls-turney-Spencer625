/**
 **********************************************************
 * @file    info.c
 * @author  Spencer Thacker <thackers@msoe.edu> 
 * @class   CPE 2600 121
 * @date    11/12/2024
 * @brief   System call tester that gets info about this PC
 **********************************************************
 */

#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    // The current time of day - in nanoseconds
    printf("The current time of day in nanoseconds\n");
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    long long seconds_since_midnight = time.tv_sec % 86400; // Gets the remainder of the total seconds when dividing by the number of seconds in a day
    long long total_nanoseconds = (long long)seconds_since_midnight * 1e9 + time.tv_nsec; // Converts seconds to nanoseconds and adds the remaining nano seconds
    printf("Nanoseconds: %lld \n\n", total_nanoseconds);

    printf("Test Seconds: %ld \n\n", (time.tv_sec*10^9 ));
    printf("Test Nanoseconds: %ld \n\n", time.tv_nsec);

    // The system's network name
    printf("System's Network (Hostname)\n");
    char net[256];
    gethostname(net, sizeof(net));
    printf("Hostname: %s \n\n", net);

    // The operating system name
    struct utsname name;
    uname(&name);
    printf("The operating system name\n");
    printf("OS Name: %s \n\n", name.sysname);

    // The operating system release and version
    printf("The operating system release\n");
    printf("OS Release: %s \n\n", name.release);
    printf("The operating system version\n");
    printf("OS Version: %s \n\n", name.version);

    // The system’s hardware type
    printf("The system’s hardware type\n");
    printf("Hardware Type: %s \n\n", name.machine);

    // The number of CPUs on the system
    printf("The number of CPUs on the system\n");
    int cpus = get_nprocs();
    printf("Number of CPUs: %d \n\n", cpus);

    // The total amount of physical memory IN BYTES
    printf("The total amount of physical memory IN BYTES\n");
    struct sysinfo sysInfo;
    sysinfo(&sysInfo);
    printf("Total Physical Memory: %lu bytes \n\n", sysInfo.totalram);

    // The total amount of free memory IN BYTES
    printf("The total amount of free memory IN BYTES\n");
    printf("Free Memory: %lu bytes \n\n", sysInfo.freeram);

    return 0;
}