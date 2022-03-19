#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int toss(void) {
    time_t t;
    srand((unsigned) time(&t));
    return (rand() % 2 + 1);
} 

void displayGrid(char *arr) {
    printf("\n");
    for (int i=1;i<=9;i++) {
        if (arr[i] == 'X' | arr[i] == 'O')
            printf(" %c |",arr[i]);
        else
            printf(" %d |", i);
        if(i%3 == 0) {
            printf("\n");
            printf("___|___|___|\n\n");
        }
    }
}

int main() {
    printf("Player 1 (X) - Player 2 (o)\n");
    printf("Doing a toss: ");
    int currentPlayerNumber = toss();
    printf("Player %d won\n", currentPlayerNumber);
    int x = 0;
    char arr[10];
    arr[3] = 'X';
    arr[4] = 'O';
    arr [9] = 'X';
    while(1) {
        displayGrid(arr);
        break;
    }
    return 0;
}