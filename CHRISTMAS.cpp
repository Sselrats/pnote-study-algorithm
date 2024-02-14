#include <iostream>
#include <set>
using namespace std;
void solve();
int mod = 20091101;
int doll[100001];
int doll_sum[100001];
set<int> memo[100001];
void set_memo();
int N, K;
int T;
int get_order_count(int end);
int main()
{
    cin >> T;
    while (T--)
    {
        solve();
    }
}
void solve()
{
    cin >> N >> K;

    doll[0] = 0;
    doll_sum[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        int d;
        cin >> d;
        doll[i] = d % K;
        doll_sum[i] = (doll_sum[i - 1] + doll[i]) % K;
    }

    int ans_1 = 0;

    int doll_sum_mod_k[100001];
    for (int i = 0; i <= N; i++)
    {
        ans_1 += doll_sum_mod_k[doll_sum[i] % K];
        ans_1 %= mod;

        doll_sum_mod_k[doll_sum[i] % K]++;
    }

    set_memo();
    int ans_2 = get_order_count(N);

    cout << ans_1 << " " << ans_2 << "\n";
}
void set_memo()
{
    for (int i = 0; i < K; i++)
    {
        memo[i].clear();
    }

    for (int i = 0; i <= N; i++)
    {
        memo[doll_sum[i] % K].insert(i);
    }
}
int get_order_count(int end)
{
    if (end == 0)
    {
        return 0;
    }

    memo[doll_sum[end] % K].erase(end);

    int ans;

    if (memo[doll_sum[end] % K].empty())
    {
        ans = get_order_count(end - 1);
    }
    else
    {
        set<int>::iterator it = memo[doll_sum[end] % K].end();
        --it;

        int candidate1 = get_order_count(end - 1);
        int candidate2 = get_order_count(*it) + 1;

        ans = max(candidate1, candidate2);
    }

    memo[doll_sum[end] % K].insert(end);

    return ans;
}