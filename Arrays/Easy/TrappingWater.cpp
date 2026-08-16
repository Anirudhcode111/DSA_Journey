/*
Problem: Trapping Rain Water
Platform: LeetCode 42
Difficulty: Hard

Approach:

- Use two pointers, left at the beginning and right at the end.
- Maintain leftMax = maximum height seen from the left.
- Maintain rightMax = maximum height seen from the right.
- Compare the CURRENT boundary heights:
    height[left] <= height[right] → process left
    height[left] > height[right]  → process right
- When processing the left:
    update leftMax
    water = leftMax - height[left]
    move left forward
- When processing the right:
    update rightMax
    water = rightMax - height[right]
    move right backward.
- Continue until left and right meet.

Important:
We compare height[left] and height[right],
NOT leftMax and rightMax, to decide which pointer to process.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int totalWater = 0;

        while(left < right) {

            if(height[left] <= height[right]) {

                leftMax = max(leftMax, height[left]);

                totalWater += leftMax - height[left];

                left++;
            }
            else {

                rightMax = max(rightMax, height[right]);

                totalWater += rightMax - height[right];

                right--;
            }
        }

        return totalWater;
    }
};