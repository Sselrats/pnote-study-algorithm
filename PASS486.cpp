#include <iostream>
#include <vector>
#include <map>
using namespace std;
void solve();
int n, l, h;
const int MAX = 10000001;
void setData();
typedef vector<int> VEC;
int min_div[MAX];
int min_div_exp[MAX];
int div_count[MAX];
vector<int> primes;
int main()
{
    int C;
    cin >> C;
    setData();
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
        if (div_count[i] == n)
        {
            count++;
        }
    }
    cout << count << "\n";
}
void setData()
{
    for (int i = 1; i < MAX; i++)
    {
        bool done = false;

        if (i == 1)
        {
            vector<int> v;
            min_div[i] = 0;
            min_div_exp[i] = 0;
            div_count[i] = 1;
            done = true;
            continue;
        }

        if (i == 2)
        {
            min_div[i] = i;
            min_div_exp[i] = 1;
            div_count[i] = 2;
            done = true;
            primes.push_back(i);
            continue;
        }

        for (int j = 0; primes[j] * primes[j] <= i; j++)
        {
            int prime = primes[j];
            if (i % prime == 0)
            {
                int exp = min_div[i / prime] == prime ? min_div_exp[i / prime] + 1 : 1;

                min_div[i] = prime;
                min_div_exp[i] = exp;
                div_count[i] = div_count[i / prime] * (exp + 1) / exp;
                done = true;
                break;
            }
        }

        if (!done)
        {
            min_div[i] = i;
            min_div_exp[i] = 1;
            div_count[i] = 2;
            primes.push_back(i);
        }
    }
}