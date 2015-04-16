//
//  main.cpp
//  leetcode-0035
//
//  Created by Douglas Su on 4/16/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left != right) {
            int mid = (right + left) / 2;
            if (A[mid] == target) return mid;
            if (left == mid) {
                if (target <= A[left]) return left;
                if (target <= A[right]) return right;
                return right + 1;
            }
            if (target < A[mid]) right = mid - 1;
            else if (target > A[mid]) left = mid + 1;
        }
        if (target <= A[left]) return left;
        return left + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    int input[] = {1,3,5,6};
    int input[] = {1,3,7,9,10};
    int target = 4;
    int n = 2;
    
    Solution *so = new Solution;
    cout << so->searchInsert(input, n, target);
    
    return 0;
}
