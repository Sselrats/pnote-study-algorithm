#include <iostream>
using namespace std;
void solve();
int N;
double coordx[100], coordy[100];
double dist[100][100];
bool is_valid(double value);
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
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> coordx[i] >> coordy[i];
        for (int j = 0; j <= i; j++)
        {
            dist[i][j] = dist[j][i] = (coordx[i] - coordx[j]) * (coordx[i] - coordx[j]) + (coordy[i] - coordy[j]) * (coordy[i] - coordy[j]);
        }
    }
    double l = 0;
    double h = 1000;
    for (int i = 0; i < 100; i++)
    {
        double mid = (l + h) / 2;
        if (is_valid(mid))
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << l << "\n";
}
bool is_valid(double value)
{
    int is_connected[100][100] = {
        0,
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            is_connected[i][j] = is_connected[j][i] = dist[i][j] < value * value ? 1 : 0;
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (is_connected[i][k] == 1 && is_connected[k][j] == 1)
                {
                    is_connected[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (is_connected[i][j] == 0)
            {
                return false;
            }
        }
    }

    return true;
}