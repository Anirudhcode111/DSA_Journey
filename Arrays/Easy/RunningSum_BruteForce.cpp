/*
Problem: Running Sum of 1D Array
Platform: LeetCode
Difficulty: Easy

Approach:
- Traverse the array from index 1.
- Add the previous running sum to the current element.
- Modify the array in-place and return it.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        return nums;
    }
};