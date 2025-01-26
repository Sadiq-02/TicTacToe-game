#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

char currentMarker; 
int currentPlayer;  

// Function to print the board
void printBoard() {
    cout << "Tic Tac Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to place a marker
bool placeMarker(int slot) {
    int row = (slot - 1) / 3; 
    int col = (slot - 1) % 3; 

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false; 
    }
}

bool checkWinner() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false; 
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}



int main() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;

    
    if (currentMarker != 'X' && currentMarker != 'O') {
        cout << "Invalid marker! Please restart the game and choose 'X' or 'O'.\n";
        return 0;
    }

    currentPlayer = 1;

    printBoard();

    int slot;
    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot (1-9): ";
        cin >> slot;

        
        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            i--;
            continue;
        }

        
        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        printBoard();

        
        if (checkWinner()) {
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            return 0;
        }

        
        switchPlayer();
    }

    cout << "It's a draw!\n";
    return 0;
}
