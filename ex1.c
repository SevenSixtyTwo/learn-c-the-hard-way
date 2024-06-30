/* include is used to import content from one file into this source file
.h stands for header files
header files contain functions to use in my program */
#include <stdio.h>

// argc is used for count
// argv is used for arguments
int main(int argc, char *argvp[]){
    int distance = 100;

    printf("you are %d kilometers away.\n", distance);

    // exit value for operating system
    return 0;
}