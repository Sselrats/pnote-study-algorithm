#include <iostream>
#include <vector>
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
    int N, K, M, L;
    vector<int> need_lecture[12];
    vector<int> semester_lecture[10];
    int is_done_lecture[12] = {0};
    cin >> N >> K >> M >> L;
    for (int i = 0; i < N; i++)
    {
        int R;
        cin >> R;
        for (int j = 0; j < R; j++)
        {
            int r;
            cin >> r;
            need_lecture[i].push_back(r);
        }
    }

    for (int i = 0; i < M; i++)
    {
        int C;
        cin >> C;
        for (int j = 0; j < C; j++)
        {
            int c;
            cin >> c;
            semester_lecture[i].push_back(c);
        }
    }

    bool done = false;
    int semester = 1;
    int done_lecture_count = 0;

    for (semester = 1; semester <= M; semester++)
    {
        ////
        vector<int> valid_lectures = semester_lecture[semester];
        for (auto valid_lecture_iter = valid_lectures.begin(); valid_lecture_iter != valid_lectures.end(); valid_lecture_iter++)
        {
            int valid_lecture = *valid_lecture_iter;
            if (is_done_lecture[valid_lecture] == 0)
            {
                bool good = true;
                vector<int> need_lectures = need_lecture[valid_lecture];

                for (auto need_lecture_iter = need_lectures.begin(); need_lecture_iter != need_lectures.end(); need_lecture_iter++)
                {
                    int need_lecture = *need_lecture_iter;
                    if (is_done_lecture[need_lecture] == 0)
                    {
                        good = false;
                        break;
                    }
                }

                if (good)
                {
                    done_lecture_count++;
                    is_done_lecture[valid_lecture] = 1;
                }
            }
        }
        ////
        if (done_lecture_count >= K)
        {
            done = true;
            break;
        }
    }

    if (done)
    {
        cout << semester;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    cout << "\n";
}