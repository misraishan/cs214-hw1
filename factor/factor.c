#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = atoi(argv[1]);
    int i = 2;
    while (n > 1) {
        if (n % i == 0) {
            printf("%d ", i);
            n /= i;
        } else {
            i++;
        }
    }
    return 0;
}
