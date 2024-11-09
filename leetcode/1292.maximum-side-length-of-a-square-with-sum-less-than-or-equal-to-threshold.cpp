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

  int squareSum(vector<vector<int>>& prefixSum, int x1, int y1, int x2,
                int y2) {
    return prefixSum[x2][y2] - prefixSum[x1][y2] -
           prefixSum[x2][y1] + prefixSum[x1][y1];
  }

  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    // 计算前缀和
    vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] -
                          prefixSum[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }
    // 从1开始 每次尝试成功就+1,直到失败
    int maxside = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n;) {
        // i,j 为一个正方形的左上方的点
        if (isSquare(m, n, i, j, maxside)) {
          // 计算正方形元素和
          int tmp = squareSum(prefixSum, i, j, i + maxside, j + maxside);
          if (tmp <= threshold) {
            ++maxside;  // +1
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
