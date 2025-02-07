#include <stdio.h>

int main(int atgc, char* argv[]){
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'S';
    char first_name[] = "Daniil";
    char last_name[] = "Lyazgin";

    printf("You are %d kilometers away.\n", distance);
    printf("You have %f levels of super power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);
    printf("My whole name is %d %d. %d.\n", first_name, initial, last_name);

    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at imaginary rate of %f.\n", bugs, bug_rate);

    long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    printf("The entire universe has %ld bugs.\n", universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n", expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n", part_of_universe);

    //this makes no sense, just a demo for something weird
    //creates a nul byte character. This is effectively the number 0
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("nul_byte as char %c.\n", nul_byte);
    printf("nul_byte as string %s.\n", nul_byte);
    printf("nul_byte as dec %d.\n", nul_byte);
    //%% to print a percent character
    printf("Which means you should care %d%%.\n", care_percentage);

    return 0;
}