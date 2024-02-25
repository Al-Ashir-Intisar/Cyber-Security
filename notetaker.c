#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

void usage(char *prog_name, char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename); 
    exit(0);

}

// void fatal(char *); //A function for fatal errors
// void *ec_malloc(unsigned int); // An errorchecked malloc() wrapper

int main(int argc, char *argv[]) { 
    int userid, fd; // file descriptor 
    char *buffer, *datafile;
    buffer = (char *) ec_malloc(100); 
    datafile = (char *) ec_malloc(20); 
    strcpy(datafile, "varnotes");

    if(argc < 2) // If there aren't commandline arguments,
        usage(argv[0], datafile); // display usage message and exit. 
    strcpy(buffer, argv[1]); // Copy into buffer.
    
    printf("[DEBUG] buffer @ %p : \'%s\'\n", buffer, buffer); 
    printf("[DEBUG] data file § %p: \'%s\'\n", datafile, datafile);

    strncat(buffer, "\n", 1); // Add a newline on the end.

    // Opening file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR); 
    if(fd == -1)
        fatal("in main() while opening file"); 
    printf("[DEBUG] file descriptor is %d\n", fd);

    userid = getuid(); // get the real user id

    // Writing data
    if(write(fd, &userid, 4) == -1)  // write userid before note data
        fatal("in main() while writing userid to file");
    write(fd, "\n", 1); // terminate line

    if (write(fd, buffer, strlen(buffer)) == -1) // write note
        fatal("in main() while writing buffer to file");
    write(fd, "\n", 1); // terminate line
    

    // Closing file
    if(close(fd) == -1)
        fatal("in main() while closing file");

    printf("Note has been saved.\n"); 
    free(buffer); 
    free(datafile);
  

}

// A function to display an error message and then exit 
void fatal(char *message) { 
    char error_message[100];
    strcpy(error_message, "[!!] Fatal Error "); 
    strncat(error_message, message, 83); 
    perror(error_message); 
    exit(-1);
}

// An errorchecked malloc() wrapper function 
void *ec_malloc(unsigned int size) { 
    void *ptr; 
    ptr = malloc(size); 
    if(ptr == NULL)
        fatal("in ec_malloc() on memory allocation"); 
    return ptr;

}