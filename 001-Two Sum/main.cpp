//
//  main.cpp
//  leetcode-0001
//
//  Created by Douglas Su on 3/3/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> re = {};
            vector<int> backup = numbers;

            int a = 0, b = 0;

            sort(numbers.begin(), numbers.end());

            for (auto beg = numbers.begin(), end = numbers.end(); beg != end; ++beg) {
                for (auto r_beg = numbers.rbegin(); ; ++r_beg) {
                    if (((*beg) + (*r_beg)) < target)
                        break;
                    if (((*beg) + (*r_beg)) == target) {
                        a = *beg;
                        b = *r_beg;
                        goto finish;
                    }
                }
            }

finish:
            cout << "a=" << a << " b=" << b << endl;
            auto iter1 = find(backup.begin(), backup.end(), a);
            auto iter2 = find(backup.rbegin(), backup.rend(), b);

            //        cout << (*iter1) << " " << (*iter2) << endl;

            //        cout << (iter1 - backup.begin() + 1) << " " << (backup.rend() - iter2) <<endl;

            //        cout << "index1 = " << re[0] << " index2 = " << re[1] << endl;
            re.push_back((int)(iter1 - backup.begin() + 1));
            re.push_back((int)(backup.rend() - iter2));
            if (re[0] > re[1]) {
                re.insert(re.begin(), re[1]);
                re.pop_back();
            }

            return re;
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    //    vector<int> cases = {2,3,4};
    //    vector<int> cases = {0,4,3,0};
    vector<int> cases = {-1,-2,-3,-4,-5};
    Solution *so = new Solution;

    auto re = so->twoSum(cases, -8);

    for (auto i : re) {
        cout << i << endl;
    }

    return 0;
}
