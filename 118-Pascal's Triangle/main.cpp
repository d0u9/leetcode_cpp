#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		vector<int> row(1, 1);
		if (!numRows) return ret;
		ret.push_back(row);
		if (numRows == 1) return ret;

		while ((numRows--) - 1) {
			vector<int> row(1, 1);
			for (int i = 1; i < ret.back().size(); ++i) {
				vector<int> last = ret.back();
				row.push_back(last[i - 1] + last[i]);
			}
			row.push_back(1);
			ret.push_back(row);
		}
		return ret;
	}
};
