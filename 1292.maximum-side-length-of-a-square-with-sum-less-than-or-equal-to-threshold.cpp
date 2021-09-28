/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to
 * Threshold
 */
#include <bits/stdc++.h>
using std::vector;
// @lc code=start
class Solution {
 public:
  bool isSquare(int m, int n, int i, int j, int& maxside) {
    if (i + maxside > m || j + maxside > n) return false;
    return true;
  }
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    // 从1开始 每次尝试成功就+1,直到失败
    int maxside = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n;) {
        // i,j 为一个正方形的左上方的点
        if (isSquare(m, n, i, j, maxside)) {
          // 计算正方形元素和
          int tmp = 0;
          for (int x = i; x < i + maxside; ++x) {
            for (int y = j; y < j + maxside; ++y) {
              tmp += mat[x][y];
            }
          }
          if (tmp <= threshold) {
            ++maxside; // +1
          } else {
            ++j;
          }
        } else {
          ++j;
        }
      }
    }
    return maxside - 1;
  }
};
// @lc code=end
