#include <iostream>
#include <set>
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
    int n;
    cin >> n;

    multiset<int> set;

    while (n--)
    {
        int a;
        cin >> a;
        set.insert(a);
    }

    int cost = 0;

    while (set.size() != 1)
    {
        int a = *set.begin();
        set.erase(set.begin());

        int b = *set.begin();
        set.erase(set.begin());

        cost += a + b;

        set.insert(a + b);
    }

    cout << cost << "\n";
}