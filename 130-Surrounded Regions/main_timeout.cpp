#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define FILL_ALL(x, v) std::fill(ALL(x),(v))
#define FILL_PART(st, ed, v) std::fill((st), (ed), (v))

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

template<typename T>
void __dump(const char *s, T &&head) {
    cerr << s << "=" << head << endl;
}

#define dump(...) do{							\
fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
__dump(#__VA_ARGS__, __VA_ARGS__);			\
} while(0);


template<typename Iter>
ostream& __out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; ++it) s << (it == b ? "":" ") << *it;
    s << "]" << endl;
    return s;
}

template<typename T>
ostream& __out_all(ostream &s, T &t) {
    __out(s, ALL(t));
}


class Solution {
    int F(vector<vector<char>> &board, set<pair<int, int>> &none_surrend, int oi, int oj) {
        if (board[oi][oj] == 'O')
            none_surrend.insert(make_pair(oi, oj));
        if (oi - 1 >= 0  && board[oi - 1][oj] == 'O' && find(ALL(none_surrend), make_pair(oi - 1, oj)) == none_surrend.end())
            F(board, none_surrend, oi - 1, oj);
        if (oj + 1 < board[0].size() && board[oi][oj + 1] == 'O' && find(ALL(none_surrend), make_pair(oi, oj + 1)) == none_surrend.end())
            F(board, none_surrend, oi, oj + 1);
        if (oi + 1 < board.size() &&
            board[oi + 1][oj] == 'O' &&
            find(ALL(none_surrend), make_pair(oi + 1, oj)) == none_surrend.end())
            F(board, none_surrend, oi + 1, oj);
        if (oj - 1 >= 0 && board[oi][oj - 1] == 'O' && find(ALL(none_surrend), make_pair(oi, oj - 1)) == none_surrend.end())
            F(board, none_surrend, oi, oj - 1);
        
        return 0;
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        set<pair<int, int>> none_surrend;
        int num_rows = board.size();
        int num_cols = board[0].size();
        for (int i = 0; i < num_cols; ++i) {
            if (board[0][i] == 'O') {
                if (find(none_surrend.begin(), none_surrend.end(), make_pair(0, i)) == none_surrend.end()) {
                    F(board, none_surrend, 0, i);
                }
            }
        }
        
        for (int i = 0; i < num_rows; ++i) {
            if (board[i][num_cols - 1] == 'O') {
                if (find(none_surrend.begin(), none_surrend.end(), make_pair(i, num_cols - 1)) == none_surrend.end()) {
                    F(board, none_surrend, i, num_cols);
                }
            }
            
        }
        
        for (int i = 0; i < num_cols; ++i) {
            if (board[num_rows - 1][i] == 'O')
                if (find(ALL(none_surrend), make_pair(num_rows - 1, i)) == none_surrend.end())
                    F(board, none_surrend, num_rows - 1, i);
        }
        for (int i = 0; i < num_rows; ++i) {
            if (board[i][0] == 'O')
                if (find(ALL(none_surrend), make_pair(i, 0)) == none_surrend.end())
                    F(board, none_surrend, i, 0);
        }
        
        for (int i = 1; i < num_rows - 1; ++i)
            for (int j = 1; j < num_cols - 1; ++j) {
                if (board[i][j] == 'O' && find(ALL(none_surrend), make_pair(i, j)) == none_surrend.end())
                    board[i][j] = 'X';
            }
    }
};

int main(void)
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'X'}
    };
    
    Solution *so = new Solution;
    so->solve(board);
    
    return 0;
}


