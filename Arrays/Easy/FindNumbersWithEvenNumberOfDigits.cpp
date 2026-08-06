/*
Problem: Find Numbers with Even Number of Digits
Platform: LeetCode
Difficulty: Easy

Approach:
- Traverse each number in the array.
- Count the number of digits using a while loop.
- If the digit count is even, increment the answer.
- Return the total count.

Time Complexity: O(n × d)
where d = number of digits in each number (at most 5 for this problem)

Space Complexity: O(1)

Author: Anirudh Awasthi
*/

#include <vector>
using namespace std;

class Solution {
    public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;

        for(int i = 0 ; nums.size() ; i++){

            int digitCount = 0;
            int num = nums[i];

            while(num > 0){
                digitCount++;
                num /= 10;
            }

            if(digitCount % 2 == 0){
                answer++;
            }
        }
        return answer;
    }
};