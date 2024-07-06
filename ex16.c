#include <stdio.h>
// gives access to assert func
#include <assert.h>
// gives acces to malloc, free
#include <stdlib.h>
// gives acces to strdup func
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// returns a pointer to a new person struct
struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    // duplicates name from function call to struct to make sure that this structure actually owns it
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
};

void Person_destroy(struct Person *who) {
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who) {
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char **argv) {
    // make two people structers
    struct Person *Pashok = Person_create("Pavel Technique", 40, 175, 80);
    struct Person *Richard = Person_create("Richard D James", 43, 180, 73);

    // declares a struct on stack
    struct Person Joe;

    Joe.name = "Sleepy Joe";
    Joe.age = 89;
    Joe.height = 178;
    Joe.weight = 63;

    // print them out and where they are in memory
    printf("%s is at memory location %p:\n", Joe.name, Joe);
    Person_print(&Joe);
    printf("\n");

    printf("%s is at memory location %p:\n", Pashok->name, Pashok);
    Person_print(Pashok);
    printf("\n");

    printf("%s is at memory location: %p\n", Richard->name, Richard);
    Person_print(Richard);
    printf("\n");

    Joe.name = "Sleepy Joe";
    Joe.age += 9;
    Joe.height -= 30;
    Joe.weight -= 20;
    Person_print(&Joe);
    printf("\n");

    Pashok->age += 20;
    Pashok->height -= 20;
    Pashok->weight += 10;
    Person_print(Pashok);
    printf("\n");

    Richard->age += 20;
    Richard->height -= 20;
    Richard->weight += 10;
    Person_print(Richard);
    printf("\n");

    // destroy them both so we clean up
    Person_destroy(Pashok);
    Person_destroy(Richard);

    return 0;
}