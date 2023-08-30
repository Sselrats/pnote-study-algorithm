#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <limits>
#include <array>

#define MULTICASE

using namespace std;

struct coord
{
    int y, x;

    coord() : y(-1000), x(-1000) {}
    coord(int y, int x) : y(y), x(x) {}

    bool operator<(const coord &other) const
    {
        return y == other.y ? x < other.x : y < other.y;
    }

    bool operator==(const coord &other) const
    {
        return y == other.y && x == other.x;
    }
};

using block_t = vector<coord>;
using board_t = array<array<bool, 10>, 10>;

coord find(const board_t &board, int h, int w, bool value)
{
    for (auto i = 0; i < h; i++)
    {
        for (auto j = 0; j < w; j++)
        {
            if (board[i][j] == value)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

coord first_empty_cell(const board_t &board, int h, int w)
{
    return find(board, h, w, false);
}

coord first_non_empty_cell(const board_t &board, int h, int w)
{
    return find(board, h, w, true);
}

struct input
{
    board_t board;
    int h, w;
    vector<block_t> blocks;

    static input get()
    {
        int h, w, r, c;

        cin >> h >> w >> r >> c;

        return {get_board(h, w), h, w, get_blocks(r, c)};
    }

    static board_t get_board(int h, int w)
    {
        board_t result;

        for (auto i = 0; i < h; i++)
        {
            for (auto j = 0; j < w; j++)
            {
                char c;
                cin >> c;

                result[i][j] = c == '#';
            }
        }

        return result;
    }

    static vector<block_t> get_blocks(int r, int c)
    {
        auto block = get_board(r, c);
        vector<block_t> result;
        for (auto i = 0; i < 4; i++)
        {
            result.emplace_back(to_block(block, r, c));

            block = rotate(block, r, c);
            swap(r, c);
        }

        sort(begin(result), end(result));
        result.erase(unique(begin(result), end(result)), end(result));

        return result;
    }

    static board_t rotate(const board_t &block, int r, int c)
    {
        board_t result;

        for (auto i = 0; i < r; i++)
        {
            for (auto j = 0; j < c; j++)
            {
                result[j][r - i - 1] = block[i][j];
            }
        }

        return result;
    }

    static block_t to_block(const board_t &board, int r, int c)
    {
        block_t result;

        const auto origin = first_non_empty_cell(board, r, c);

        for (auto i = 0; i < r; i++)
        {
            for (auto j = 0; j < c; j++)
            {
                if (!board[i][j])
                {
                    continue;
                }

                result.emplace_back(i - origin.y, j - origin.x);
            }
        }

        sort(begin(result), end(result));

        return result;
    }
};

struct solution
{
    board_t board;
    int h, w;
    vector<block_t> blocks;

    solution(const input &input) : board(input.board), h(input.h), w(input.w), blocks(input.blocks) {}
    solution(input &&input) : board(move(input.board)), h(input.h), w(input.w), blocks(std::move(input.blocks)) {}

    bool is_placeable(const block_t &block, int y, int x)
    {
        for (const auto &coord : block)
        {
            const auto cy = y + coord.y;
            const auto cx = x + coord.x;

            if (cy < 0 || cy >= h || cx < 0 || cx >= w || board[cy][cx])
            {
                return false;
            }
        }

        return true;
    }

    void flip(const block_t &block, int y, int x)
    {
        for (const auto &coord : block)
        {
            const auto cy = y + coord.y;
            const auto cx = x + coord.x;

            board[cy][cx] ^= 1;
        }
    }

    coord pos_to_place() const
    {
        return first_empty_cell(board, h, w);
    }

    int remain() const
    {
        auto result = 0;
        for (auto i = 0; i < h; i++)
        {
            for (auto j = 0; j < w; j++)
            {
                result += board[i][j] == false;
            }
        }

        return result;
    }

    int search(int placed, int best)
    {
        const int size = blocks[0].size();
        if (remain() / size + placed <= best)
        {
            return best;
        }

        const auto pos = pos_to_place();
        const auto y = pos.y;
        const auto x = pos.x;

        if (y == -1)
        {
            return max(placed, best);
        }

        for (const auto &block : blocks)
        {
            if (!is_placeable(block, y, x))
            {
                continue;
            }

            flip(block, y, x);
            best = max(search(placed + 1, best), best);
            flip(block, y, x);
        }

        board[y][x] = true;
        const auto result = max(best, search(placed, best));
        board[y][x] = false;

        return result;
    }

    void pp(int placed)
    {
        cout << placed << '\n';
        for (auto i = 0; i < h; i++)
        {
            for (auto j = 0; j < w; j++)
            {
                cout << (board[i][j] ? '#' : '.');
            }
            cout << '\n';
        }
    }

    void solve()
    {
        cout << search(0, 0) << '\n';
    }
};

void init();
void handle_cases();

int main(void)
{
    init();
#ifdef MULTICASE
    handle_cases();
#else
    handle_case();
#endif

    return 0;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void handle_case();
void handle_cases()
{
    int c;
    cin >> c;

    while (c--)
    {
        handle_case();
    }
}

void handle_case()
{
    solution solution(input::get());
    solution.solve();
}
