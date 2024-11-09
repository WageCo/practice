/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */
#include <bits/stdc++.h>
using std::vector;
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int beg = -1, end = -2;
        int max = nums[0], min = nums[n-1];
        for(int i = 0; i<n; ++i){
            max = std::max(max, nums[i]);
            min = std::min(min, nums[n-i-1]);
            if (max != nums[i])
                end = i;
            if (min != nums[n-i-1])
                beg = n-i-1;
        }
        return end - beg + 1;
    }
};
// @lc code=end

