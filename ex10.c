#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc < 2) {
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    char letter;

    for (int i = 1; i < argc; i++){
        for (int j = 0; argv[i][j] != '\0'; j++){
            letter = argv[i][j];

            switch (letter) {
                case 'A' ... 'Z':
                    letter += 32;
                    break;
            
                default:
                    break;
            }
            printf("%c", letter);
        }
        printf(" ");
    }
    printf("\n");

    return 0;
}