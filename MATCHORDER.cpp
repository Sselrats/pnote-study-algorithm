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
    multiset<int> rus;
    multiset<int> kor;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int r;
        cin >> r;
        rus.insert(r);
    }
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        kor.insert(k);
    }
    int cnt = 0;
    multiset<int>::iterator kor_it = kor.begin();
    for (multiset<int>::iterator it = rus.begin(); it != rus.end(); it++)
    {
        while (*kor_it < *it)
        {
            kor_it++;

            if (kor_it == kor.end())
            {
                cout << cnt << "\n";
                return;
            }
        }
        cnt++;
        kor_it++;

        if (kor_it == kor.end())
        {
            cout << cnt << "\n";
            return;
        }
    }
    cout << cnt << "\n";
    return;
}