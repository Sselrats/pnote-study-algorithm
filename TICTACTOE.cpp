#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int C;
int dp[20000];
void solve();
int boardToNum(const vector<string> &board);
bool isFinished(const vector<string> &board, char currentPlayer);
int canWin(vector<string> &board, char currentPlayer);

int main()
{
    cin >> C;
    while (C--)
    {
        solve();
    }
}

void solve()
{
    int turn = 0;
    vector<string> board;
    string tmp;

    for (int i = 0; i < 19628; i++)
        dp[i] = -2;

    for (int i = 0; i < 3; i++)
    {
        cin >> tmp;
        for (int j = 0; j < 3; j++)
        {
            if (tmp[j] != '.')
                turn++;
        }
        board.push_back(tmp);
    }
    char currentPlayer = turn % 2 == 0 ? 'x' : 'o';

    int res = canWin(board, currentPlayer);
    if (res == 1)
    {
        cout << currentPlayer << "\n";
    }
    else if (res == 0)
    {
        cout << "TIE"
             << "\n";
    }
    else
    {
        char winner = (currentPlayer == 'x') ? 'o' : 'x';
        cout << winner << "\n";
    }
}

int boardToNum(const vector<string> &board)
{
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res *= 3;
            if (board[i][j] == 'o')
                ++res;
            else if (board[i][j] == 'x')
                res += 2;
        }
    }
    return res;
}
bool isFinished(const vector<string> &board, char currentPlayer)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != currentPlayer)
                break;
            if (j == 2)
                return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] != currentPlayer)
                break;
            if (j == 2)
                return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] != currentPlayer)
            break;
        if (i == 2)
            return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[i][2 - i] != currentPlayer)
            break;
        if (i == 2)
            return true;
    }
    return false;
}

// return 1 => currentPlayer win
// return -1 => otherPlayer win
// return others => 무승부

int canWin(vector<string> &board, char currentPlayer)
{
    char otherPlayer = (currentPlayer == 'x') ? 'o' : 'x';
    if (isFinished(board, otherPlayer))
        return -1;
    int &res = dp[boardToNum(board)];
    if (res != -2)
        return res;
    int minValue = 2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = currentPlayer;
                minValue = min(minValue, canWin(board, otherPlayer));
                board[i][j] = '.';
            }
        }
    }
    if (minValue == 2 || minValue == 0)
        return res = 0;
    return res = -minValue;
}
