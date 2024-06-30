#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;


    char *states[] = {
        "California", "Oregon", "Texas", "Washington", NULL
    };

    int num_states = 5;

    char *tmp;
    tmp = states[0];
    states[0] = argv[1]; 
    argv[1] = tmp;

    for (i = 1; i <argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    for (i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}