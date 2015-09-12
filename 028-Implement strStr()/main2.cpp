#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
	        int i = 0, m = 0, len = 0;
	        while (m != needle.size() && haystack[i] != '\0') {
			if (haystack[i] == needle[m]) {
				i++;
				m++;
			} else {
				if (len == 0 && m == 0)
					i++;
				if (len == 0 && m != 0)
					m = 0;
				if (len != 0){
					i++;
					m = len;
					len = 0;
				}
				continue;
			}

			if (haystack[i] == needle[len])
				len++;
			else
				len = 0;

		}

	        if (haystack[i] == '\0' && m != needle.size()) return -1;
	        else return i - m;
	}
};


