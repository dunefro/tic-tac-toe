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
        if (arr[i] == 'X' || arr[i] == 'O')
            printf(" %c |",arr[i]);
        else
            printf(" %d |", i);
        if(i%3 == 0) {
            printf("\n");
            printf("___|___|___|\n\n");
        }
    }
}

int verifyMove(char *arr, int grid) {
    printf("Your move is %d\n", grid);
    if (grid <=9 && grid >=1) {
        if (arr[grid] != 'X' && arr[grid] != 'O' )
            return 0;
    }
    return 1; // something wrong
}

int main() {
    printf("Player 1 (X) - Player 2 (O)\n");
    printf("Doing a toss: ");
    int currentPlayerNumber = toss();
    char currentPlayerSymbol;
    printf("Player %d won\n", currentPlayerNumber);
    int x = 0;
    char arr[10];
    int grid =0 ;
    while(1) {
        displayGrid(arr);
        if (currentPlayerNumber == 1){
            currentPlayerNumber = 2;
            currentPlayerSymbol = 'O';
        }
        else {
            currentPlayerNumber = 1;
            currentPlayerSymbol = 'X';
        }
        printf("Player %d (%c), Enter your move: ", currentPlayerNumber, currentPlayerSymbol);
        scanf("%d", &grid);
        int check = verifyMove(arr, grid);
        if (check) {
            printf("Invalid Move\n");
            return 1;
        }
        arr[grid] = currentPlayerSymbol;
    }
    return 0;
}