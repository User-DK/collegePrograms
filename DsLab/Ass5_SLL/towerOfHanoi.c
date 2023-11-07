#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    printf("%d\n",n);
    tower_of_hanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int num_disks = 3; // Change this to the desired number of disks
    char source = 'A', auxiliary = 'B', destination = 'C';

    printf("Tower of Hanoi with %d disks:\n", num_disks);
    tower_of_hanoi(num_disks, source, auxiliary, destination);

    return 0;
}
