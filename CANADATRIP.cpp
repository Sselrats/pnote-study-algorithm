#include <iostream>
using namespace std;
long N;
long K;
long L[5000];
long M[5000];
long G[5000];
void solve();
long count(long mid);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
void solve()
{
    cin >> N >> K;
    for (long i = 0; i < N; i++)
    {
        cin >> L[i] >> M[i] >> G[i];
    }
    long l = 0;
    long h = 8030000;
    for (long i = 0; i < 100; i++)
    {
        if (l == h || l + 1 == h)
        {
            break;
        }
        long mid = (l + h) / 2;
        if (count(mid) < K)
        {
            l = mid;
        }
        else
        {
            h = mid;
        }
    }
    cout << h << "\n";
}
long count(long mid)
{
    long num = 0;
    for (long i = 0; i < N; i++)
    {
        if (L[i] - M[i] <= mid && mid <= L[i])
        {
            num += 1 + (mid - (L[i] - M[i])) / G[i];
        }
        else if (L[i] < mid)
        {
            num += 1 + M[i] / G[i];
        }
    }
    return num;
}