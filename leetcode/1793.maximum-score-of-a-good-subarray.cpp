/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */
#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
// @lc code=start
class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int i = k;  // left point
    int j = k;  // right point
    int minimun = nums[k];
    int distance = j - i + 1;
    int maxscore = minimun * distance;
    while (i > 0 || j < n - 1) {
      if (i == 0) {
        ++j;
      } else if (j == n - 1) {
        --i;
      } else if (nums[i - 1] > nums[j + 1]) {
        --i;
      } else {
        ++j;
      }
      if (minimun > nums[i]) minimun = nums[i];
      if (minimun > nums[j]) minimun = nums[j];
      distance = j - i + 1;
      int temp = minimun * distance;
      if (temp > maxscore) maxscore = temp;
    }
    return maxscore;
  }
};
// @lc code=end
