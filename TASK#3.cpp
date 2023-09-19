#include <iostream>
using namespace std;

void display(char arr[3][3]) {
    cout << " TIC-TAC-TOE\n";                              // display cosole
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << arr[i][j] << " ";
        }
        cout << "|\n-------------\n";
    }
}

char console(char arr[3][3], char currentPlayer) {                           // Function decide about the turn
    cout << "PLAYER " << currentPlayer << "'s TURN\n";

    int row, col;
    do {
        cout << "SELECT ROW (0-2): ";
        cin >> row;
        cout << "SELECT COLUMN (0-2): ";
        cin >> col;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || arr[row][col] != ' ');

    arr[row][col] = currentPlayer;

    return (currentPlayer == 'X') ? 'O' : 'X';                               // condition check whose current turn is 
}

char win(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ') {
            return arr[i][0]; // Horizontal win
        }
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ') {
            return arr[0][i]; // Vertical win
        }
    }

    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ') {
        return arr[0][0]; // Diagonal win (top-left to bottom-right)
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ') {
        return arr[0][2]; // Diagonal win (top-right to bottom-left)
    }

    return '/';
}

int main() {
    char arr[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    char result = '/';
    char playAgain;
    int countX = 0;
    int countO = 0;
    int countDraw = 0; // Added countDraw variable

    do {
        int count = 0;

        while (count < 9) {
            display(arr);
            currentPlayer = console(arr, currentPlayer);
            count++;

            result = win(arr);
            if (result == 'X' || result == 'O') {
                display(arr);
                cout << "PLAYER " << result << " WINS!" << endl;
                if (result == 'X') {
                    countX++;
                }
                else {
                    countO++;
                }
                break;
            }
            else if (result == '/' && count == 9) {
                display(arr);
                cout << "DRAW!" << endl;
                countDraw++; // Increment the draw count
                break;
            }

            system("pause");       
            system("cls");         // Clear the console
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            // Reset the game board and variables
            currentPlayer = 'X';
            result = '/';
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    arr[i][j] = ' ';
                }
            }
        }
        else {
            cout << "Thanks for playing! Goodbye." << endl;
        }
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Statistics: X wins: " << countX << ", O wins: " << countO << ", Draws: " << countDraw << endl;

    return 0;
}
