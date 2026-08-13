/*
Problem: Longest Consecutive Sequence
Platform: LeetCode 128
Difficulty: Medium

Approach:

- Store all elements in an unordered_set for fast existence checking.
- Iterate over the set instead of the original array so duplicate elements
  are processed only once.
- For every number x, check whether x - 1 exists in the set.
- If x - 1 does not exist, x is the starting point of a consecutive sequence.
- Starting from x, keep checking x + 1, x + 2, x + 3...
  until the next consecutive number is not found.
- Track the length of the current sequence and update the longest length.

Why start only when x - 1 does not exist?

- This ensures every consecutive sequence is traversed only from its starting point.
- It prevents repeatedly counting the same sequence.

Time Complexity: O(n) average

Space Complexity: O(n)

Author: Anirudh Awasthi
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> set;

        for(int i = 0; i < nums.size(); i++){
            set.insert(nums[i]);
        }

        int longestlength = 0;

        for(int x : set){

            if(set.count(x - 1) == 0){

                int length = 1;
                int currentElement = x;

                while(set.count(currentElement + 1) > 0){
                    currentElement++;
                    length++;
                }

                if(length > longestlength){
                    longestlength = length;
                }
            }
        }

        return longestlength;
    }
};