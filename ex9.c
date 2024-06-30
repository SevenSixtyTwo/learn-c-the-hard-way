#include <stdio.h>

int main(int argc, char* argv[]){
    int i = 0;
    while (i < 25) {
        printf("%d, ", i);
        i++;
    }

    printf("\n");

    while (i >= 0) {
        printf("%d, ", i);
        i--;
    }

    printf("\n");

    
    // go through each string in argv
    for (i = 1; i < argc; i++){
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {"California", "Texas", "Oregon", "Alabama"};

    int sum_states = 4;

    for (i = 0; i < sum_states; i++){
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}