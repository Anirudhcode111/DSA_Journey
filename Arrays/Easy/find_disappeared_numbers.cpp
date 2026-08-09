/*
Problem: Find All Numbers Disappeared in an Array
Platform: LeetCode
Difficulty: Easy

Approach:
Use the input array itself as a marking structure.
For every number x, mark index x-1 as negative.
After marking, any positive index i means i+1 is missing.

Time Complexity: O(n)
Space Complexity: O(1) extra
*/

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                answer.push_back(i + 1);
            }
        }

        return answer;
    }
};