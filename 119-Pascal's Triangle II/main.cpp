#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> *last = new(vector<int>);
		vector<int> *current = new(vector<int>);
		vector<int> *tmp = nullptr;
		if (!rowIndex) return row;
		if (rowIndex == 1) { (*current).push_back(1); return *current; }

		while ((rowIndex--) - 1) {
			tmp = last;
			last = current;
			current = tmp;
			(*current).push_back(1);
			(*current).clear();
			for (int i = 1; i < (*last).size(); ++i) {
				(*current).push_back((*last)[i - 1] + (*last)[i]);
			}
			(*current).push_back(1);
		}
		return *current;
	}
};

