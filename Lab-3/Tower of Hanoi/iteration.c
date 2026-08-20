#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void movedisk(int n, char source, char destination) {
    printf("Move disk %d from %c to %c\n", n, source, destination);
}
void towersofhanoi(int n, char source, char destination, char auxiliary) {
    int num_moves = pow(2, n) - 1;
    if(n % 2 == 0){
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }
    for (int i = 1; i <= num_moves; i++) {
        int disk = __builtin_ctz(i) + 1; 
        if (disk % 3 == 1) {
            movedisk(disk, source, destination);
        } else if (disk % 3 == 2) {
            movedisk(disk, source, auxiliary);
        } else {
            movedisk(disk, auxiliary, destination);
        }
    }
}

    int main() {
        int n;
        printf("Enter the number of disks: ");
        scanf("%d", &n);
        printf("The sequence of moves involved in the Tower of Hanoi are:\n");
        towersofhanoi(n, 'A', 'C', 'B');
        return 0;
    }