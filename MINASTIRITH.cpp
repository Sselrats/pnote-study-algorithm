#include <iostream>
#include <cmath>
using namespace std;
void solve();
double calc_theta(double r);

int R = 8;
const double pi = 3.14159265358979;

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
    int n;
    cin >> n;
    double y[101], x[101], r[101];
    double angle[101]; // -1 ~ 1의 값
    for (int i = 0; i < n; i++)
    {
        cin >> y[i] >> x[i] >> r[i];
        angle[i] = atan2(y[i], x[i]) / pi;
        cout << calc_theta(r[i]);
    }
}

double calc_theta(double r)
{
    if (r >= 2 * R)
        return 2;

    return 4 * asin(r / (2 * R)) / pi;
}