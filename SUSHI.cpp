#include <iostream>
#include <map>
using namespace std;
void solve();
int best();
int sushi_n;
long money;
int price[20], value[20];
int dp[201];
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        solve();
    }
}
void solve()
{
    cin >> sushi_n >> money;
    money /= 100;
    for (int i = 0; i < sushi_n; i++)
    {
        cin >> price[i] >> value[i];
        price[i] /= 100;
    }
    cout << best() << "\n";
}
int best()
{
    dp[0] = 0;
    for (int m = 1; m <= money; m++)
    {
        int max_value = 0;
        for (int kind = 0; kind < sushi_n; kind++)
        {
            if (m >= price[kind])
            {
                int new_value = dp[(m - price[kind]) % 201] + value[kind];
                max_value = max_value > new_value ? max_value : new_value;
            }
        }
        dp[m % 201] = max_value;
    }
    return dp[money % 201];
}