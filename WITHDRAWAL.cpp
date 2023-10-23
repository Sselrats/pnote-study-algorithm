#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve();
int n, k;
struct Data
{
    int R, C;
    Data(int a, int b)
    {
        R = a;
        C = b;
    }
    bool operator<(const Data &d) const
    {
        if (R / (double)C != d.R / (double)d.C)
        {
            return R / (double)C < d.R / (double)d.C;
        }
        if (R / (double)C == d.R / (double)d.C)
        {
            return C > d.C;
        }
    }
    Data operator+(const Data &d) const
    {
        return Data(R + d.R, C + d.C);
    }
};
int main()
{
    cout << fixed;
    cout.precision(7);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
void solve()
{
    vector<Data> v;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int r, c;
        cin >> r >> c;
        v.push_back(Data(r, c));
    }
    sort(v.begin(), v.end());
    Data ans = Data(0, 0);
    for (vector<Data>::iterator it = v.begin(); it < v.begin() + k; it++)
    {
        ans = ans + *it;
    }
    cout << ans.R / (double)ans.C << "\n";
}