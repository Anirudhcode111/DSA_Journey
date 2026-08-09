/*
Problem: Merge Sorted Array
Platform: LeetCode
Difficulty: Easy

Approach:
Use three pointers and merge from the back.
Compare the largest remaining elements of both arrays
and place the larger one at the end of nums1.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};