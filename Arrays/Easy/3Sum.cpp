/*
Problem: 3Sum
Platform: LeetCode 15
Difficulty: Medium

Approach:

- Sort the array first.
- Fix one element using index i.
- Use two pointers:
    left = i + 1
    right = last index
- Calculate the sum of nums[i], nums[left] and nums[right].
- If sum < 0, move left forward to increase the sum.
- If sum > 0, move right backward to decrease the sum.
- If sum == 0, store the triplet and move both pointers.
- Skip duplicate values to avoid duplicate triplets.

Why sorting?

- It allows us to decide pointer movement based on the sum.
- It places duplicate values together, making duplicate handling easier.

Time Complexity: O(n²)

Auxiliary Space: O(1)

Output Space: O(n²) in the worst case.

Author: Anirudh Awasthi
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){

            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if(sum < 0){
                    left++;
                }
                else if(sum > 0){
                    right--;
                }
                else{

                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }

                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
            }
        }

        return result;
    }
};