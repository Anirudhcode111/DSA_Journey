/*
Problem: Product of Array Except Self
Platform: LeetCode 238
Difficulty: Medium

Approach:

- Use the output array to store the product of all elements to the left of each index.
- Traverse the array from left to right while maintaining a leftProduct.
- Then traverse the array from right to left while maintaining a rightProduct.
- Multiply the stored left product by the right product to get the final answer.
- No division is used.

Time Complexity: O(n)

Space Complexity: O(1) extra
(The output array is not considered extra space.)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> answer(nums.size());

        int leftProduct = 1;

        for(int i = 0; i < nums.size(); i++){
            answer[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            answer[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return answer;
    }
};