#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 3;

void printBoard(const vector<vector<char>>& board)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            cout << board[row][col];
            if (col < BOARD_SIZE - 1)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (row < BOARD_SIZE - 1)
        {
            cout << "-----" << endl;
        }
    }
}

bool isWin(const vector<vector<char>>& board, char player)
{
    // Proverka na redici
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        bool win = true;
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] != player)
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            return true;
        }
    }

    // Proverka na koloni
    for (int col = 0; col < BOARD_SIZE; col++)
    {
        bool win = true;
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            if (board[row][col] != player)
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            return true;
        }
    }

    // Proverka dijagonalno
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool isFull(const vector<vector<char>>& board)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, '-'));

    char player = 'X';

    while (true)
    {
        // Pecatenje na tablata
        printBoard(board);
      
        int row, col;
        cout << "Player " << player << ", enter row and column: ";
        cin >> row >> col;

        // Proverka dali cekorot e validen
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        if (board[row][col] != '-')
        {
            cout << "That space is already taken. Try again." << endl;
            continue;
        }

        // Azuriranje na tablata i proverka za pobeda
        board[row][col] = player;
        if (isWin(board, player))
        {
            cout << "Player " << player << " wins!" << endl;
            break;
        }
        if (isFull(board))
        {
            cout << "The game is a tie." << endl;
            break;
        }

        // Zamena na igracite
        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }

    return 0;
}
