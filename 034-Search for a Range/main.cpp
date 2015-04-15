//
//  main.cpp
//  leetcode-0034
//
//  Created by Douglas Su on 4/15/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    inline void swap(int &a, int& b) {
        auto tmp = a;
        a = b;
        b = tmp;
    }
    vector<int> foo (int *A, int left, int right, int& target) {
        vector<int> ret = {-1, -1};
        vector<int> a = ret, b = ret;
        if (right - left <= 1) {
            if (A[left] == target) ret[0] = left;
            if (A[right] == target) ret[1] = right;
        } else {
            int mid = (left + right) / 2;
            if (A[mid] <= target) a = foo(A, mid, right, target);
            if (A[mid] >= target) b = foo(A, left, mid, target);
            if (a == ret) ret = b;
            else if(b == ret) ret = a;
            else {
                ret[0] = (a[0] < b[0]) ? a[0] : b[0];
                ret[1] = (a[1] < b[1]) ? b[1] : a[1];
            }
            
        }
        if (ret[0] != -1 && ret[1] == -1) ret[1] = ret[0];
        else if (ret[0] == -1 && ret[1] != -1) ret[0] = ret[1];
        if (ret[0] > ret[1]) swap(ret[0], ret[1]);
        return ret;
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret =  foo(A, 0, n - 1, target);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int input[] = {5, 7, 7, 8, 8, 10};
//    int input[] = {1, 2, 2, 8, 8, 10};
    int target = 8;
    int n = 6;
    
    Solution *so = new Solution;
    auto re = so->searchRange(input, n, target);
    
    return 0;
}
