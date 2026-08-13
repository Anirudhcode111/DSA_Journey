/*
Problem: Maximum Subarray
Platform: LeetCode 53
Difficulty: Medium

Approach:

- Use Kadane's Algorithm to find the maximum sum of a contiguous subarray.
- Maintain two variables: currentSum and largestSum.
- Add each element to currentSum while traversing the array.
- If currentSum becomes greater than largestSum, update largestSum.
- If currentSum becomes negative, reset it to 0 because a negative running sum will only reduce the sum of any future subarray.
- Initialize largestSum with nums[0] so that arrays containing only negative numbers are handled correctly.

Time Complexity: O(n)

Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;
        int largestSum = nums[0];

        for(int i = 0; i < nums.size(); i++){

            currentSum += nums[i];

            if(currentSum > largestSum){
                largestSum = currentSum;
            }

            if(currentSum < 0){
                currentSum = 0;
            }
        }

        return largestSum;
    }
};