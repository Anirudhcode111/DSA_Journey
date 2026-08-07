/*
Problem: Remove Element
Platform: LeetCode
Difficulty: Easy

Approach:
- Use two pointers.
- Read pointer traverses the array.
- Write pointer stores valid elements.
- Return the number of remaining elements.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int w = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != val) {
                nums[w] = nums[i];
                w++;
            }
        }

        return w;
    }
};