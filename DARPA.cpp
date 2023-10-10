#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve();
double places[200];
bool is_valid(double gap);
int N, M;

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
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> places[i];
    }

    double low = 0, high = 240;
    for (int i = 0; i < 100; i++)
    {
        double mid = (low + high) / 2.0;
        if (is_valid(mid))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << low << "\n";
}
bool is_valid(double gap)
{
    double limit = 0;
    int cameras = 0;

    for (int i = 0; i < M; i++)
    {
        if (limit <= places[i])
        {
            cameras++;
            limit = places[i] + gap;
        }
    }
    return cameras >= N;
}