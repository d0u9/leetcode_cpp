#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;


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


#include <iostream>
#include <vector>

using namespace std;


class Solution {
	bool F(vector<vector<char>> &board, int x, int y) {
		if (board[x][y] == 'X') return false;
		if (board[x][y] == '+') return true;
        
		board[x][y] = '+';
        
		if (x > 0) F(board, x - 1 ,y);
		if (y > 0) F(board, x, y - 1);
		if (x + 1 < board.size() - 1) F(board, x + 1, y);
		if (y + 1 < board[0].size() - 1) F(board, x, y + 1);
        
		return true;
	}
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		auto num_rows = board.size();
		auto num_cols = board[0].size();
		for (int i = 0; i < num_rows; ++i) {
			F(board, i, 0);
			F(board, i, num_cols - 1);
		}
        
		for (int j = 0; j < num_cols; ++j) {
			F(board, 0, j);
			F(board, num_rows - 1, j);
		}
        
		for (int i = 0; i < num_rows; ++i)
			for (int j = 0; j < num_cols; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '+') board[i][j] = 'O';
                
			}
	}
};




int main(void)
{
//    vector<vector<char>> board = {
//        {'O', 'X', 'X', 'O', 'X'},
//        {'X', 'O', 'O', 'X', 'O'},
//        {'X', 'O', 'X', 'O', 'X'},
//        {'O', 'X', 'O', 'O', 'O'},
//        {'X', 'X', 'O', 'X', 'O'}
//    };
    
//    vector<vector<char>> board = {
//        {'X', 'O', 'X', 'O', 'X', 'O'},
//        {'O', 'X', 'O', 'X', 'O', 'X'},
//        {'X', 'O', 'X', 'O', 'X', 'O'},
//        {'O', 'X', 'O', 'X', 'O', 'X'}
//    };
    
	vector<vector<char>> board = {
		{'X', 'O', 'X', 'O', 'X', 'O'},
		{'O', 'X', 'O', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'O', 'X', 'O'},
		{'O', 'X', 'O', 'X', 'O', 'X'}
	};
    
	Solution *so = new Solution;
	so->solve(board);
    
	return 0;
}


