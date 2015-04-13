//
//  main.cpp
//  leetcode-0027
//
//  Created by Douglas Su on 4/14/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0) return 0;
        int index = 0;
        for (int i = 0; i < n; i ++) {
            if (A[i] != elem) {
                A[index++] = A[i];
            }
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    int A[] = {2};
    
    cout << so->removeElement(A, 1, 3) << endl;
    return 0;
}
