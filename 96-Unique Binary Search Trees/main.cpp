#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> T(n + 1, 0);
		T[0] = 1;
		T[1] = 1;
		for (i = 2; i < n; i++) {
			for (j = 0; j < i; j++)
				T[i] += T[j] + T[i - j - 1];
		}

		return T[n];
	}
};


int main(int argc, char *argv[])
{
	Solution *so = new Solution;

	auto re = so->numTrees(3);

	return 0;
}




