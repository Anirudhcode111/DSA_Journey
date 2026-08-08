/*
Problem: Best Time to Buy and Sell Stock
Platform: LeetCode
Difficulty: Easy

Approach:
- Keep track of the minimum price seen so far.
- Calculate the profit for selling on each day.
- Update the maximum profit whenever a better profit is found.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minSoFar = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] < minSoFar) {
                minSoFar = prices[i];
            }

            int currentProfit = prices[i] - minSoFar;

            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }

        return maxProfit;
    }
};