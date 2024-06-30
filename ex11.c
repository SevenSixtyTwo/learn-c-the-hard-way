#include <stdio.h>

int main(int argc, char *argv[]){
    char name[4] = { 'a', 'a', 'a' };
    int numbers[4] = { 0 };
    // char name[4] = { 'a' };
    // char name[4];

    // First, print them out raw
    printf("numbers: ");
    for (int i = 0; i < 4; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("name each: ");
    for (int i = 0; i < 4; i++){
        printf("%d ", name[i]);
    }
    printf("\n");

    printf("name: %s\n", name);

    // Set up the numbers
    for (int i = 0; i < 4; i++) {
        numbers[i] = i + 1;
    }

    // set up tne name
    name[0] = 'D';
    name[1] = 65;
    name[2] = 'n';
    name[3] = 'D';

    // then print them out initialized
    printf("numbers: ");
    for (int i = 0; i < 4; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("name each: ");
    for (int i = 0; i < 4; i++){
        printf("%d ", name[i]);
    }
    printf("\n");

    printf("name: %d\n", name);

    // another way to use name
    char *another = "Dan";

    printf("another: %s\n", another);

    printf("another each: ");
    for (int i = 0; i < 3; i++){
        printf("%c ", another[i]);
    }
    printf("\n");

    return 0;
}