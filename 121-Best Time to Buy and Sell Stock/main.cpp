#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int tmp_min = prices[0];
		int profit = 0, tmp_profit = 0;
		for (int i = 0; i < prices.size(); ++i) {
			tmp_min = (prices[i] < tmp_min) ? prices[i] : tmp_min;
			tmp_profit = ((prices[i] - tmp_min) > tmp_profit) ? (prices[i] - tmp_min) : tmp_profit;
			if (tmp_profit > profit)
				profit = tmp_profit;
		}
		return profit;
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}
