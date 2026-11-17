#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void numberGuessGame();
void rockPaperScissors();
void ticTacToeGame();
void quizGame();
void handCricketGame();

int main() {
    int ch;
    srand(time(0)); // For generating random numbers

    do {
        printf("\n==========================================\n");
        printf("        MINI GAME ARCADE PROJECT          \n");
        printf("==========================================\n");
        printf("1. Number Guessing Game\n");
        printf("2. Rock, Paper, Scissors\n");
        printf("3. 2-Player Tic-Tac-Toe\n");
        printf("4. C Language Quiz Game (KBC Style)\n");
        printf("5. Hand Cricket Game (vs Computer)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                numberGuessGame();
                break;
            case 2:
                rockPaperScissors();
                break;
            case 3:
                ticTacToeGame();
                break;
            case 4:
                quizGame();
                break;
            case 5:
                handCricketGame();
                break;
            case 0:
                printf("Exiting Game Arcade. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (ch != 0);

    return 0;
}

// Game 1: Number Guessing Game
void numberGuessGame() {
    int number, guess, count = 0;
    number = (rand() % 50) + 1; // Random number between 1 and 50

    printf("\n--- Guess the Number (Between 1 and 50) ---\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;

        if (guess > number) {
            printf("Too high! Guess a smaller number.\n");
        } else if (guess < number) {
            printf("Too low! Guess a bigger number.\n");
        } else {
            printf("Correct! You guessed it in %d tries!\n", count);
        }
    } while (guess != number);
}

// Game 2: Rock Paper Scissors
void rockPaperScissors() {
    int user, comp;

    printf("\n--- Rock, Paper, Scissors ---\n");
    printf("1 = Rock, 2 = Paper, 3 = Scissors\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &user);

    comp = (rand() % 3) + 1;
    printf("Computer chose: %d\n", comp);

    if (user == comp) {
        printf("Match Draw!\n");
    } else if ((user == 1 && comp == 3) || (user == 2 && comp == 1) || (user == 3 && comp == 2)) {
        printf("You Win!\n");
    } else {
        printf("Computer Wins!\n");
    }
}

// Game 3: Simple 1D Array Tic-Tac-Toe (Easy to explain in Viva!)
void ticTacToeGame() {
    char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player = 1, choice, moves = 0, win = 0;
    char mark;

    while (moves < 9 && win == 0) {
        printf("\n  %c | %c | %c \n", box[1], box[2], box[3]);
        printf(" ---|---|---\n");
        printf("  %c | %c | %c \n", box[4], box[5], box[6]);
        printf(" ---|---|---\n");
        printf("  %c | %c | %c \n\n", box[7], box[8], box[9]);

        if (player % 2 != 0) {
            player = 1;
            mark = 'X';
        } else {
            player = 2;
            mark = 'O';
        }

        printf("Player %d (%c), enter box number (1-9): ", player, mark);
        scanf("%d", &choice);

        // Place mark if box is not already taken
        if (choice >= 1 && choice <= 9 && box[choice] != 'X' && box[choice] != 'O') {
            box[choice] = mark;
            moves++;
        } else {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Simple if-else check for winning conditions
        if ((box[1] == box[2] && box[2] == box[3]) ||
            (box[4] == box[5] && box[5] == box[6]) ||
            (box[7] == box[8] && box[8] == box[9]) ||
            (box[1] == box[4] && box[4] == box[7]) ||
            (box[2] == box[5] && box[5] == box[8]) ||
            (box[3] == box[6] && box[6] == box[9]) ||
            (box[1] == box[5] && box[5] == box[9]) ||
            (box[3] == box[5] && box[5] == box[7])) {
            win = 1;
            printf("\nCongrats! Player %d (%c) Wins!\n", player, mark);
        } else {
            player++;
        }
    }

    if (win == 0) {
        printf("\nGame Draw!\n");
    }
}

// Game 4: Simple Quiz Game
void quizGame() {
    int ans, score = 0;

    printf("\n--- C Language Quiz ---\n");

    printf("\nQ1. Who invented the C Language?\n");
    printf("1. Bjarne Stroustrup  2. Dennis Ritchie  3. James Gosling  4. Guido van Rossum\n");
    printf("Enter answer: ");
    scanf("%d", &ans);
    if (ans == 2) {
        printf("Correct!\n");
        score = score + 10;
    } else {
        printf("Wrong! Correct answer is 2.\n");
    }

    printf("\nQ2. Which symbol is used for comments in C?\n");
    printf("1. //   2. ##   3. $$   4. **\n");
    printf("Enter answer: ");
    scanf("%d", &ans);
    if (ans == 1) {
        printf("Correct!\n");
        score = score + 10;
    } else {
        printf("Wrong! Correct answer is 1.\n");
    }

    printf("\nQ3. Array index in C always starts from?\n");
    printf("1. 1   2. -1   3. 0   4. Any number\n");
    printf("Enter answer: ");
    scanf("%d", &ans);
    if (ans == 3) {
        printf("Correct!\n");
        score = score + 10;
    } else {
        printf("Wrong! Correct answer is 3.\n");
    }

    printf("\nQuiz Over! Your Total Score = %d / 30\n", score);
}

// Game 5: Hand Cricket Game
void handCricketGame() {
    int userRun, compBowl, totalScore = 0;

    printf("\n--- Hand Cricket Game ---\n");
    printf("Rule: Enter runs from 1 to 6. If your number matches Computer's ball, you are OUT!\n");

    while (1) {
        printf("\nEnter your shot (1 to 6): ");
        scanf("%d", &userRun);

        if (userRun < 1 || userRun > 6) {
            printf("No ball! Please enter between 1 and 6 only.\n");
            continue;
        }

        compBowl = (rand() % 6) + 1;
        printf("Computer bowled: %d\n", compBowl);

        if (userRun == compBowl) {
            printf("OUT! Your innings is over.\n");
            break;
        } else {
            totalScore = totalScore + userRun;
            printf("Current Score: %d\n", totalScore);
        }
    }
    printf("Final Score = %d runs!\n", totalScore);
}