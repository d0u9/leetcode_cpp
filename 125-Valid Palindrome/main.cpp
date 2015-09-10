#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < s.size();) {
			if (!isalnum(s[i])) {++i; continue;}
			if (!isalnum(s[j])) {--j; continue;}
			if (tolower(s[i]) != tolower(s[j])) return false;
			++i;
			--j;
		}
		return true;
	}
};
