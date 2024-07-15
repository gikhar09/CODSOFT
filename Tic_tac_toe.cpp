#include <iostream>

using namespace std;

class TicTacToe 
{
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() : currentPlayer('X') 
	{
        for (int i = 0; i < 3; ++i) 
		{
            for (int j = 0; j < 3; ++j) 
			{
                board[i][j] = ' ';
            }
        }
    }

    void print_board() 
	{
        for (int i = 0; i < 3; ++i) 
		{
            cout << " --- --- ---" << endl;
            for (int j = 0; j < 3; ++j) 
			{
                cout << "| " << board[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << " --- --- ---" << endl;
    }

    void switchPlayer() 
	{
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playerInput() 
	{
        int row, col;
        bool validMove = false;

        while (!validMove) 
		{
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') 
			{
                board[row - 1][col - 1] = currentPlayer;
                validMove = true;
            } 
			else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    bool checkWin() 
	{
        for (int i = 0; i < 3; ++i) 
		{
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        return false;
    }

    bool checkDraw() 
	{
        for (int i = 0; i < 3; ++i) 
		{
            for (int j = 0; j < 3; ++j) 
			{
                if (board[i][j] == ' ') 
				{
                    return false;
                }
            }
        }
        return true;
    }

    char getCurrentPlayer() const 
	{
        return currentPlayer;
    }
};

int main() 
{
    TicTacToe game;
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) 
	{
        game.print_board();
        game.playerInput();
        gameWon = game.checkWin();
        gameDraw = game.checkDraw();
        if (!gameWon && !gameDraw) 
		{
            game.switchPlayer();
        }
    }

    game.print_board();

    if (gameWon) 
	{
        cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
    } 
	else {
        cout << "The game is a draw!" << endl;
    }

}


