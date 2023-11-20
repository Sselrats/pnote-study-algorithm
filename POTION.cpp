#include <iostream>
using namespace std;
void solve();
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
    int n, r[201], p[201];
    // 1 <= r <= 1000 <- target
    // 0 <= p <= 1000 <- now
    cin >> n;

    int gcd = 1;
    int tester = 2;

    int min = 1001;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        if (min > r[i])
        {
            min = r[i];
        }
    }

    while (tester <= min)
    {
        bool good = true;

        for (int i = 0; i < n; i++)
        {
            if (r[i] % tester != 0)
            {
                good = false;
                break;
            }
        }

        if (good)
        {
            gcd = tester;
            tester *= 2;
        }
        else
        {
            tester += gcd;
        }
    }

    for (int i = 0; i < n; i++)
    {
        r[i] /= gcd;
    }

    int multiply = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        int need = (p[i] - 1) / r[i] + 1;
        if (multiply < need)
        {
            multiply = need;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << r[i] * multiply - p[i] << " ";
    }
    cout << "\n";
}