#include <stdio.h>

int main(){
    int mod = 5 % 2;
    int div = 5 / 2;

    int res;

    res = (div < mod) ? mod : div;

    int bitwise = res << 1;

    printf("%d\n", mod);
    printf("%d\n", div);
    printf("%d\n", res);
    printf("%d\n", bitwise);

    return 0;
}