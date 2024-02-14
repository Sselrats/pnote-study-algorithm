#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve();

vector<int> getPi(const string &str)
{
    vector<int> pi(str.length(), 0);
    int j = 0;

    for (int i = 1; i < str.length(); ++i)
    {
        while (j > 0 && str[i] != str[j])
        {
            j = pi[j - 1];
        }

        if (str[i] == str[j])
        {
            ++j;
            pi[i] = j;
        }
    }

    return pi;
}

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
    string inputString;
    cin >> inputString;

    string reversedString = string(inputString.rbegin(), inputString.rend());

    string concat = reversedString + inputString;
    vector<int> pi = getPi(concat);

    int last = *pi.rbegin();

    int length = inputString.length();

    int answer = 2 * length - last;

    cout << max(answer, length) << "\n";
}