#include <stdio.h>

// Function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to move a disk from source to destination using auxiliary rod
void move_disk(char source, char destination) {
    printf("Move disk from rod %c to rod %c\n", source, destination);
}

// Function to solve Tower of Hanoi puzzle
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        move_disk(source, destination);
    } else {
        tower_of_hanoi(n - 1, source, auxiliary, destination);
        move_disk(source, destination);
        tower_of_hanoi(n - 1, auxiliary, destination, source);
    }
}

int main() {
    int n;
    char source = 'A', destination = 'C', auxiliary = 'B';

    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    printf("Enter the number of disks for Tower of Hanoi: ");
    scanf("%d", &n);

    printf("The steps to solve Tower of Hanoi:\n");
    tower_of_hanoi(n, source, destination, auxiliary);

    return 0;
}
