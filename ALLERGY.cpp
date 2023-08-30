#include <iostream>
#include <map>
#include <vector>
using namespace std;

int int_max = 987654321;

int T;
int pupil_num, food_num;
map<string, int> name_to_index;
vector<int> foods_eaten_by[50], pupils_who_eat[50];
int available_food_count[50];
int answer;

void solve();
void get_answer(int selected_food_number);
int get_considered();

int main()
{
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 50; i++)
        {
            foods_eaten_by[i].clear();
            pupils_who_eat[i].clear();
        }
        solve();
    }
}
void solve()
{
    cin >> pupil_num >> food_num;

    for (int i = 0; i < pupil_num; i++)
    {
        string name;
        cin >> name;
        name_to_index[name] = i;
    }

    for (int i = 0; i < food_num; i++)
    {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            string name;
            cin >> name;
            int index = name_to_index[name];
            foods_eaten_by[index].push_back(i);
            pupils_who_eat[i].push_back(index);
        }
    }

    answer = food_num;

    get_answer(0);

    cout << answer << "\n";
}
void get_answer(int selected_food_number)
{
    if (selected_food_number > answer)
    {
        return;
    }

    int considered = get_considered();

    if (considered != int_max)
    {
        for (int food : foods_eaten_by[considered])
        {
            for (int pupil : pupils_who_eat[food])
            {
                available_food_count[pupil]++;
            }

            get_answer(selected_food_number + 1);

            for (int pupil : pupils_who_eat[food])
            {
                available_food_count[pupil]--;
            }
        }
    }
    else
    {
        answer = selected_food_number;
    }
}
int get_considered()
{
    int considered = int_max;
    int min = int_max;

    for (int i = 0; i < pupil_num; i++)
    {
        if (available_food_count[i] <= 0)
        {
            int cnt = foods_eaten_by[i].size();
            if (min > cnt)
            {
                min = cnt;
                considered = i;
            }
        }
    }

    return considered;
}