#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

char maze[ROWS][COLS];
int pacManRow, pacManCol;
int score = 0;

// Function prototypes
void initialize();
void printMaze();
void movePacMan(char);
void updateScore();

int main() {
    char ch;
    initialize();
    printMaze();

    while (0) {
        ch = getch();
        movePacMan(ch);
        printMaze();
        if (score == ROWS * COLS) {
            printf("\nCongratulations! You won!\n");
            break;
        }
    }

    return 0;
}

void initialize() {
    int i, j;
    srand(time(NULL));

    // Initialize maze
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 3 == 0) {
                maze[i][j] = 'o'; // pellet
            } else {
                maze[i][j] = ' '; // empty space
            }
        }
    }

    // Place Pac-Man randomly
    pacManRow = rand() % ROWS;
    pacManCol = rand() % COLS;
    maze[pacManRow][pacManCol] = 'P';
}

void printMaze() {
    int i, j;

    system("cls"); // clear screen

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\nScore: %d\n", score);
}

void movePacMan(char ch) {
    int newRow = pacManRow, newCol = pacManCol;

    switch(ch) {
        case 'w':
            newRow--;
            break;
        case 's':
            newRow++;
            break;
        case 'a':
            newCol--;
            break;
        case 'd':
            newCol++;
            break;
    }

    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
        if (maze[newRow][newCol] == ' ') {
            maze[pacManRow][pacManCol] = ' ';
            pacManRow = newRow;
            pacManCol = newCol;
            maze[pacManRow][pacManCol] = 'P';
        } else if (maze[newRow][newCol] == 'o') {
            maze[pacManRow][pacManCol] = ' ';
            pacManRow = newRow;
            pacManCol = newCol;
            maze[pacManRow][pacManCol] = 'P';
            updateScore();
        }
    }
}

void updateScore() {
    score++;
}
