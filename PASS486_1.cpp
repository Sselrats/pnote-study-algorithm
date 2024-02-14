#include <iostream>
#include <map>
using namespace std;
void solve();
int n, l, h;
const int MAX = 10000001;
void setDivision();
int division[MAX];
int main()
{
    int C;
    cin >> C;
    setDivision();
    while (C--)
    {
        solve();
    }
}
void solve()
{
    int count = 0;
    cin >> n >> l >> h;
    for (int i = l; i <= h; i++)
    {
        if (division[i] == n)
        {
            count++;
        }
    }
    cout << count << "\n";
}
void setDivision()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX / i; j++)
        {
            division[i * j]++;
        }
    }
}