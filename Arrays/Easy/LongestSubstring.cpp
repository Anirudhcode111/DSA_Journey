/*
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode 3
Difficulty: Medium

Approach:

- Use a sliding window with two pointers:
    left  → start of the current window
    right → current character being processed.
- Use an unordered_map to store the latest index of each character.
- If the current character has already appeared, move left
  to one position after its previous occurrence.
- Use max(left, previousIndex + 1) so that left never moves backwards.
- Update the character's latest index in the hashmap.
- Calculate the current window length using:
      right - left + 1
- Keep updating maxlength with the maximum valid window length.

Important:
When a duplicate is found, left should never move backwards.

Example:
"abba"

b repeats at index 2:
left = max(0, 1 + 1) = 2

a repeats at index 3, but its old index 0 is already
outside the current window:
left = max(2, 0 + 1) = 2

Time Complexity: O(n)

Space Complexity: O(n)
(General case; bounded by the character set in fixed-character
implementations.)

Author: Anirudh Awasthi
*/

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int maxlength = 0;
        int currentlength = 0;
        int left = 0;

        for(int i = 0; i < s.size(); i++) {

            if(mp.count(s[i])) {
                left = max(left, mp[s[i]] + 1);
            }

            mp[s[i]] = i;

            currentlength = i - left + 1;

            if(currentlength > maxlength) {
                maxlength = currentlength;
            }
        }

        return maxlength;
    }
};