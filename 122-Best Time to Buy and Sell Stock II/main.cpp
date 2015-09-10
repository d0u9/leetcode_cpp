#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int profit = 0, low = prices[0];

		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > prices[i - 1])
				profit += prices[i] - prices[i - 1];
		}
		return profit;
	}
};

