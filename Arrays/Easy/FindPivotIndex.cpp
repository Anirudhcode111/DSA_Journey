/*
Problem: Find Pivot Index
Platform: LeetCode
Difficulty: Easy

Approach:
- Calculate the total sum of the array.
- Initialize leftSum as 0.
- Traverse the array.
- Calculate rightSum = totalSum - leftSum - current element.
- If leftSum == rightSum, return the current index.
- Otherwise, update leftSum.
- If no pivot exists, return -1.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};