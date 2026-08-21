/*
Problem: Top K Frequent Elements
Platform: LeetCode 347
Difficulty: Medium

Approach:

- Use an unordered_map to count the frequency of each element.
- Use a min-heap (priority_queue) of size k.
- Store each element in the heap as:
      {frequency, number}
- For every element in the frequency map:
    - Push {frequency, number} into the min-heap.
    - If heap size becomes greater than k, remove the
      element with the smallest frequency.
- This ensures that only the k most frequent elements
  remain in the heap.
- Finally, extract the numbers from the heap into the result.

Why Min-Heap?

We only need the top k elements. The smallest frequency
among the current k elements stays at the top, so when a
better (more frequent) element arrives, we can remove the
smallest one.

Time Complexity: O(n log k)

Space Complexity: O(n)

where:
n = number of elements in the input array.

Author: Anirudh Awasthi
*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto &it : mp) {

            pq.push({it.second, it.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {

            result.push_back(pq.top().second);

            pq.pop();
        }

        return result;
    }
};