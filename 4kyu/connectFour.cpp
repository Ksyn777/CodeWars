#include <iostream>
#include <vector>
#include <string>
#include <bandit/bandit.h>

enum Players {
    Empty,
    A_Red,
    B_Yellow
};

std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    std::vector<std::vector<Players>> board(6, std::vector<Players>(7, Empty));

    for (const std::string& move : pieces_position_list) {
        int col = move[0] - 'A';
        Players currentPlayer = (move.substr(2) == "Red") ? A_Red : B_Yellow;

        for (int r = 5; r >= 0; r--) {
            if (board[r][col] == Empty) {
                board[r][col] = currentPlayer;
                break; 
            }
        }

        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 4; c++) {
                if (board[r][c] != Empty &&
                    board[r][c] == board[r][c+1] &&
                    board[r][c] == board[r][c+2] &&
                    board[r][c] == board[r][c+3]) 
                    return (board[r][c] == A_Red) ? "Red" : "Yellow";
            }
        }

        for (int c = 0; c < 7; c++) {
            for (int r = 0; r < 3; r++) {
                if (board[r][c] != Empty &&
                    board[r][c] == board[r+1][c] &&
                    board[r][c] == board[r+2][c] &&
                    board[r][c] == board[r+3][c])
                    return (board[r][c] == A_Red) ? "Red" : "Yellow";
            }
        }

        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 7; c++) {
                if (r <= 2 && c <= 3) {
                    if (board[r][c] != Empty &&
                        board[r][c] == board[r+1][c+1] &&
                        board[r][c] == board[r+2][c+2] &&
                        board[r][c] == board[r+3][c+3])
                        return (board[r][c] == A_Red) ? "Red" : "Yellow";
                }
                if (r >= 3 && c <= 3) {
                    if (board[r][c] != Empty &&
                        board[r][c] == board[r-1][c+1] &&
                        board[r][c] == board[r-2][c+2] &&
                        board[r][c] == board[r-3][c+3])
                        return (board[r][c] == A_Red) ? "Red" : "Yellow";
                }
            }
        }
    }

    return "Draw";
}

Describe(sample_test_cases)
{
    It(fixed_tests)
    {
        Assert::That(who_is_winner( {
                "A_Red",
                "B_Yellow",
                "A_Red",
                "B_Yellow",
                "A_Red",
                "B_Yellow",
                "G_Red",
                "B_Yellow"
        }), Equals("Yellow"));
        Assert::That(who_is_winner( {
                "C_Yellow",
                "E_Red",
                "G_Yellow",
                "B_Red",
                "D_Yellow",
                "B_Red",
                "B_Yellow",
                "G_Red",
                "C_Yellow",
                "C_Red",
                "D_Yellow",
                "F_Red",
                "E_Yellow",
                "A_Red",
                "A_Yellow",
                "G_Red",
                "A_Yellow",
                "F_Red",
                "F_Yellow",
                "D_Red",
                "B_Yellow",
                "E_Red",
                "D_Yellow",
                "A_Red",
                "G_Yellow",
                "D_Red",
                "D_Yellow",
                "C_Red"
        }), Equals("Yellow"));
        Assert::That(who_is_winner( {
                "A_Yellow",
                "B_Red",
                "B_Yellow",
                "C_Red",
                "G_Yellow",
                "C_Red",
                "C_Yellow",
                "D_Red",
                "G_Yellow",
                "D_Red",
                "G_Yellow",
                "D_Red",
                "F_Yellow",
                "E_Red",
                "D_Yellow"
        }), Equals("Red"));
        Assert::That(who_is_winner( {
                "F_Yellow",
                "G_Red",
                "D_Yellow",
                "C_Red",
                "A_Yellow",
                "A_Red",
                "E_Yellow",
                "D_Red",
                "D_Yellow",
                "F_Red",
                "B_Yellow",
                "E_Red",
                "C_Yellow",
                "D_Red",
                "F_Yellow",
                "D_Red",
                "D_Yellow",
                "F_Red",
                "G_Yellow",
                "C_Red",
                "F_Yellow",
                "E_Red",
                "A_Yellow",
                "A_Red",
                "C_Yellow",
                "B_Red",
                "E_Yellow",
                "C_Red",
                "E_Yellow",
                "G_Red",
                "A_Yellow",
                "A_Red",
                "G_Yellow",
                "C_Red",
                "B_Yellow",
                "E_Red",
                "F_Yellow",
                "G_Red",
                "G_Yellow",
                "B_Red",
                "B_Yellow",
                "B_Red"
        }), Equals("Red"));
        Assert::That(who_is_winner( {
                "C_Yellow",
                "B_Red",
                "B_Yellow",
                "E_Red",
                "D_Yellow",
                "G_Red",
                "B_Yellow",
                "G_Red",
                "E_Yellow",
                "A_Red",
                "G_Yellow",
                "C_Red",
                "A_Yellow",
                "A_Red",
                "D_Yellow",
                "B_Red",
                "G_Yellow",
                "A_Red",
                "F_Yellow",
                "B_Red",
                "D_Yellow",
                "A_Red",
                "F_Yellow",
                "F_Red",
                "B_Yellow",
                "F_Red",
                "F_Yellow",
                "G_Red",
                "A_Yellow",
                "F_Red",
                "C_Yellow",
                "C_Red",
                "G_Yellow",
                "C_Red",
                "D_Yellow",
                "D_Red",
                "E_Yellow",
                "D_Red",
                "E_Yellow",
                "C_Red",
                "E_Yellow",
                "E_Red"
        }), Equals("Yellow"));
    }
};