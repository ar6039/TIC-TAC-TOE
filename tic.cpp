#include <iostream>
#include <vector>

using namespace std;

// Initialize the board with empty spaces
vector<char> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

// Function to print the current state of the board
void print_board() {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

// Function to check if there is a winner
bool check_win(char symbol) {
    // Check for horizontal lines
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == symbol && board[i+1] == symbol && board[i+2] == symbol)
            return true;
    }

    // Check for vertical lines
    for (int i = 0; i < 3; i++) {
        if (board[i] == symbol && board[i+3] == symbol && board[i+6] == symbol)
            return true;
    }

    // Check for diagonal lines
    if (board[0] == symbol && board[4] == symbol && board[8] == symbol)
        return true;

    if (board[2] == symbol && board[4] == symbol && board[6] == symbol)
        return true;

    // If no winning line is found, return false
    return false;
}

int main() {
    char player1_symbol, player2_symbol;
    int player1_choice, player2_choice;

    // Get the symbols for each player
    cout << "Player 1, choose your symbol (X or O): ";
    cin >> player1_symbol;

    // Set the symbol for player 2 based on player 1's choice
    player2_symbol = (player1_symbol == 'X') ? 'O' : 'X';

    // Print the initial state of the board
    print_board();

    // Start the game loop
    while (true) {
        // Player 1's turn
        cout << "Player 1's turn (symbol " << player1_symbol << "): ";
        cin >> player1_choice;

        // Check if the chosen cell is empty
        if (board[player1_choice-1] == ' ') {
            board[player1_choice-1] = player1_symbol;
            print_board();

            // Check if player 1 has won
            if (check_win(player1_symbol)) {
                cout << "Player 1 wins!" << endl;
                break;
            }
        } else {
            cout << "That cell is already occupied. Please choose another one." << endl;
            continue;
        }

        // Check if the board is full (tie)
        if (find(board.begin(), board.end(), ' ') == board.end()) {
            cout << "Tie game!" << endl;
            break;
        }

        // Player 2's turn
        cout << "Player 2's turn (symbol " << player2_symbol << "): ";
        cin >> player2_choice;

        // Check if the chosen cell is
