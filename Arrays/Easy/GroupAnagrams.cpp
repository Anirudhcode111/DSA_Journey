/*
Problem: Group Anagrams
Platform: LeetCode 49
Difficulty: Medium

Approach:

- Use an unordered_map where:
    key   = sorted version of the string
    value = vector containing all anagrams having that key.
- For every string, make a copy so the original string is preserved.
- Sort the copy alphabetically.
- Use the sorted string as the key.
- Push the original string into the vector corresponding to that key.
- Finally, collect all the vectors from the hashmap into the result.

Example:

"eat" → "aet"
"tea" → "aet"
"ate" → "aet"

So:

"aet" → ["eat", "tea", "ate"]

Time Complexity: O(n × k log k)
Space Complexity: O(n × k)

where:
n = number of strings
k = average length of a string.

Author: Anirudh Awasthi
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++) {

            string key = strs[i];

            sort(key.begin(), key.end());

            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(auto &pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};