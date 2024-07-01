#include <stdio.h>

int main(int argc, char *argv[]) {
    // Create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

    // // Pointers way
    // int *p_ages;
    // *p_ages[0] = 23;
    // *p_ages[1] = 43;
    // *p_ages[2] = 12;
    // *p_ages[3] = 89;
    // *p_ages[4] = 2;

    // Safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;
    
    // for (i = 0; i < count; i++) {
    //     printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    // }

    printf("---\n");
    // // First way using indexing
    // for (i = 0; i < count; i++) {
    //     printf("%d years.\n", p_ages[i]);
    // }

    printf("---\n");

    for (i = count-1; i >= 0; i--) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    // Set up the pointers to the start of the arrays
    // int *casted = (int)names;
    int *cur_age = ages;
    char **cur_name = names;

    // Second way using pointers
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    for (i = count - 1; i >= 0; i--) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // Third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // Fourth way with pointers in a stupid complex way
    for (cur_name = names, cur_age = ages; 
            (cur_age - ages) < count; cur_name++, cur_age++) {
                printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    printf("---\n");

    for (cur_name = &names[count - 1], cur_age = &ages[count - 1]; 
            (cur_age - ages) >= 0; cur_name--, cur_age--) {
                printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    printf("---\n");

    cur_name = names;
    cur_age = ages;

    for (i = 0; i < count; i++) {
        printf("%s lived %d years so far, %p, %p.\n", cur_name[i], cur_age[i], cur_name, cur_age);
    }

    return 0;
}