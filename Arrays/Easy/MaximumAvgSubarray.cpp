/*
Problem: Maximum Average Subarray I
Platform: LeetCode 643
Difficulty: Easy

Approach:

- Use a fixed-size sliding window of size k.
- First calculate the sum of the first k elements.
- Store this sum as the maximum sum.
- Slide the window one position at a time.
- Remove the outgoing element and add the incoming element.
- Update the maximum sum after every slide.
- Finally, divide the maximum sum by k to get the maximum average.

Time Complexity: O(n)

Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int currentSum = 0;

        for(int i = 0; i < k; i++){
            currentSum += nums[i];
        }

        int maxSum = currentSum;

        for(int i = 0; i < nums.size() - k; i++){
            currentSum = currentSum + nums[i + k] - nums[i];

            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }

        double maxAvg = (double)maxSum / k;

        return maxAvg;
    }
};