//
//  main.cpp
//  leetcode-0049
//
//  Created by Douglas Su on 4/20/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        map<string, pair<string, int>> hash;
        for (auto beg = strs.begin(); beg != strs.end(); ++beg) {
            auto origin = *beg;
            sort((*beg).begin(), (*beg).end());
            auto re = hash.find((*beg));
            if (re == hash.end()) hash.insert(make_pair(*beg, make_pair(origin, 0)));
            else {
                if (re->second.second == 0) {
                    ret.push_back(re->second.first);
                    re->second.second = 1;
                }
                ret.push_back(origin);
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<string> input = {"ate", "bab", "bba", "eat",  "!23122"};
    Solution *so = new Solution;          
    auto re = so->anagrams(input);
    return 0;
}
