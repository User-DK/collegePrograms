#include <stdio.h>

int Ackermann(int a, int b) {
    if (a == 0) {
        return b + 1;
    } else if (a != 0 && b == 0) {
        return Ackermann(a - 1, 1);
    } else if (a != 0 && b != 0) {
        return Ackermann(a - 1, Ackermann(a, b - 1));
    }
}

int main() {
    printf("Enter m: ");
    int m, n;
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    int a = Ackermann(m, n);
    printf("%d\n", a);
    return 0;
}
