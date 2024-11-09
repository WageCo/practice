/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */
#include <bits/stdc++.h>
using std::vector;
// @lc code=start
class Solution {
 public:
  int rotatedDigits(int n) {
    int count = 0;
    vector<int> f = {1, 1, 2, 0, 0, 2, 2, 0, 1, 2};
    // 1 is 0 1 8
    // 2 is 2 5 6 9
    // 0 is 3 4 7
    int temp = 0;
    for (int i = 1; i <= n; ++i) {
      temp = i;
      int flag = 1;
      while (temp) {
        flag *= f[temp % 10]; // judgment for each digits
        temp /= 10;
      }
      if (flag >= 2) ++count;
    }
    return count;
  }
};
// @lc code=end
