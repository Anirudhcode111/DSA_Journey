/*
Problem: Majority Element
Platform: LeetCode 169
Difficulty: Easy

Approach:

- Use an unordered_map to store the frequency of each element.
- Traverse the array and increment the count of each number.
- Traverse the array again and check which element appears more than n/2 times.
- Return that element.

Time Complexity: O(n)

Space Complexity: O(n)

Author: Anirudh Awasthi
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] > nums.size() / 2){
                return nums[i];
            }
        }

        return -1;
    }
};