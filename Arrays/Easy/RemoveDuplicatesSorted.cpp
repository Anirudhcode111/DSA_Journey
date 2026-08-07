/*
Problem: Remove Duplicates from Sorted Array
Platform: LeetCode
Difficulty: Easy

Approach:
- Use two pointers.
- Write pointer keeps track of the last unique element.
- Read pointer traverses the array.
- Copy only new unique elements.
- Return the count of unique elements.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        int w = 0;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[w] != nums[i]) {
                w++;
                nums[w] = nums[i];
            }
        }

        return w + 1;
    }
};