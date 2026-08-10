/*
Problem: Majority Element
Platform: LeetCode 169
Difficulty: Easy

Approach:

- Use the Boyer-Moore Voting Algorithm.
- Maintain a candidate and its vote count.
- If the count becomes zero, choose the current element as the new candidate.
- If the current element matches the candidate, increase the count.
- Otherwise, decrease the count.
- The remaining candidate is the majority element.

Time Complexity: O(n)

Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){

            if(count == 0){
                candidate = nums[i];
            }

            if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }

        return candidate;
    }
};