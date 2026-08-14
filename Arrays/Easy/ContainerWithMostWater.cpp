/*
Problem: Container With Most Water
Platform: LeetCode 11
Difficulty: Medium

Approach:

- Use two pointers, left at the beginning and right at the end.
- Calculate the area between the two lines.
- The width is right - left.
- The effective height is the smaller of height[left] and height[right].
- Update the maximum area after every calculation.
- Move the pointer corresponding to the shorter line.
- The shorter line limits the amount of water, so moving it gives a chance
  to find a taller boundary while the width decreases.

Time Complexity: O(n)

Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int currentArea = 0;
        int largestArea = 0;

        int left = 0;
        int right = height.size() - 1;

        while(left < right){

            int width = right - left;
            int currentHeight = min(height[left], height[right]);

            currentArea = width * currentHeight;

            if(currentArea > largestArea){
                largestArea = currentArea;
            }

            if(height[left] > height[right]){
                right--;
            }
            else{
                left++;
            }
        }

        return largestArea;
    }
};