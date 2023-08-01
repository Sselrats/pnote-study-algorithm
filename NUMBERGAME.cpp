#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
void solve();
int MIN = -987654321;
int n;
int board[50];
// 선턴인 사람이 얻을 수 있는 최대 점수
int dp[51][51];
int result(int current, int start, int end, int player);
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        fill(&dp[0][0], &dp[51 - 1][51], MIN);
        solve();
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int ans = result(0, 0, n, 1);

    cout << ans << "\n";
}
// player = 1 or -1
int result(int current, int start, int end, int player)
{
    if (dp[start][end] != MIN)
    {
        return current + player * dp[start][end];
    }
    if (end - start == 0)
    {
        dp[start][end] = 0;
        return current;
    }
    if (end - start == 1)
    {
        dp[start][end] = board[start];
        return current + player * dp[start][end];
    }
    int case1 = result(current + player * board[start], start + 1, end, -player) - current;
    int case2 = result(current + player * board[end - 1], start, end - 1, -player) - current;
    int case3 = result(current, start + 2, end, -player) - current;
    int case4 = result(current, start, end - 2, -player) - current;

    dp[start][end] = max(max(player * case1, player * case2), max(player * case3, player * case4));

    return current + player * dp[start][end];
}