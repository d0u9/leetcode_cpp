#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.size() == 0) return 0;
		if (triangle.size() == 1) return triangle.front().front();
		for(auto b = triangle.rbegin() + 1, e = triangle.rend();
		    b != e; ++b) {
			for (int i = 0; i < (*b).size(); ++i) {
				(*b)[i] = min((*(b-1))[i], (*(b-1))[i + 1]) + (*b)[i];
			}
		}
		return triangle[0][0];
	}
};




