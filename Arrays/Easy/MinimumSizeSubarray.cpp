/*
Problem: Minimum Size Subarray Sum
Platform: LeetCode 209
Difficulty: Medium

Approach:

- Use a variable-size sliding window with two pointers: left and right.
- Expand the window by moving the right pointer and adding elements to the current sum.
- Whenever the current sum becomes greater than or equal to the target, the window is valid.
- Store the current window length if it is smaller than the previous minimum.
- Shrink the window from the left by removing nums[left] from the sum and moving left forward.
- Continue shrinking while the sum remains greater than or equal to the target.
- Return 0 if no valid subarray exists.

Time Complexity: O(n)

Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int right = 0;
        int sum = 0;

        int minLength = nums.size() + 1;

        while(right < nums.size()){

            sum += nums[right];
            right++;

            while(sum >= target){

                int currentLength = right - left;

                if(currentLength < minLength){
                    minLength = currentLength;
                }

                sum -= nums[left];
                left++;
            }
        }

        if(minLength == nums.size() + 1){
            return 0;
        }

        return minLength;
    }
};