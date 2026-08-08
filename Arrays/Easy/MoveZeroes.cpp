/*
Problem: Move Zeroes
Platform: LeetCode
Difficulty: Easy

Approach:
- Use two pointers.
- Move all non-zero elements to the front.
- Fill the remaining positions with zero.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int w = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                nums[w] = nums[i];
                w++;
            }
        }

        while (w < nums.size()) {
            nums[w] = 0;
            w++;
        }
    }
};