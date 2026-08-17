/*
Problem: Subarray Sum Equals K
Platform: LeetCode 560
Difficulty: Medium

Approach:

- Maintain a running prefix sum using currentSum.
- Use an unordered_map to store the frequency of
  previously seen prefix sums.
- For every currentSum, calculate:
      required = currentSum - k
- If required exists in the map, its frequency tells us
  how many subarrays ending at the current index have sum k.
- Add that frequency to the answer.
- Then store/increment the frequency of the current prefix sum.
- Initialize mp[0] = 1 so that subarrays starting from index 0
  are counted correctly.

Important:

currentSum is the running sum and should NOT be modified
while calculating currentSum - k. The required sum is stored
separately.

Time Complexity: O(n)

Space Complexity: O(n)

Author: Anirudh Awasthi
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int currentSum = 0;
        int count = 0;

        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {

            currentSum += nums[i];

            int required = currentSum - k;

            if(mp.count(required)) {
                count += mp[required];
            }

            mp[currentSum]++;
        }

        return count;
    }
};