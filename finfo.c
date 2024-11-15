/**
 **********************************************************
 * @file    finfo.c
 * @author  Spencer Thacker <thackers@msoe.edu>
 * @class   CPE 2600 121
 * @date    11/12/2024
 * @brief   File information
 * @note    Takes in a lineparameter of a file's name
 **********************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // checks to see if a file name is given.
    if (argc != 2) {
        // If not, provides corrent format
        printf("Format: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    struct stat fileStat;

    // Retrieve file information using stat
    if (stat(filename, &fileStat) == -1) {
        // if equal to -1, an error acured 
        printf("Error retrieving file information\n");
        return 1;
    }

    // Print file type
    if (S_ISREG(fileStat.st_mode)){
        printf("File Type: Regular File\n");
    }else if (S_ISDIR(fileStat.st_mode)){
        printf("File Type: Directory\n");
    }else if (S_ISCHR(fileStat.st_mode)){
        printf("File Type: Character Device\n");
    }else if (S_ISBLK(fileStat.st_mode)){
        printf("File Type: Block Device\n");
    }else if (S_ISFIFO(fileStat.st_mode)){
        printf("File Type: FIFO (Named Pipe)\n");
    }else if (S_ISLNK(fileStat.st_mode)){
        printf("File Type: Symbolic Link\n");
    }else if (S_ISSOCK(fileStat.st_mode)){
        printf("File Type: Socket\n");
    }else {
        printf("File Type: Unknown\n");
    }

    // Print file permissions
    printf("Permissions: ");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");;

    // Print file owner UID
    printf("Owner UID: %d\n", fileStat.st_uid);

    // Print file size in bytes
    printf("Size: %ld bytes\n", fileStat.st_size);

    // Print last modification time
    char timeBuf[256];
    struct tm *timeInfo = localtime(&fileStat.st_mtime);
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", timeInfo);
    printf("Last Modified: %s\n", timeBuf);

    return 0;
}