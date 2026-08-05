/*
Problem: Richest Customer Wealth
Platform: LeetCode
Difficulty: Easy

Approach:
- Traverse each customer's accounts.
- Calculate the total wealth of each customer.
- Keep track of the maximum wealth.
- Return the maximum wealth.

Time Complexity: O(m × n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int maxWealth = 0;

        for (int i = 0; i < accounts.size(); i++) {

            int sum = 0;

            for (int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }

            if (sum > maxWealth) {
                maxWealth = sum;
            }
        }

        return maxWealth;
    }
};