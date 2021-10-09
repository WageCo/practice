/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */
#include <bits/stdc++.h>
using std::string;
using std::vector;
// @lc code=start
class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    string ns = std::to_string(n);
    int N = ns.size();
    int M = digits.size();
    vector<int> dp(N + 1, 0);
    dp[N] = 1;
    for (int i = N - 1; i >= 0; --i) {
      int Ni = ns.at(i) - '0';
      int temp = 0;
      for (string d : digits) {
        std::stringstream os;
        os << d;
        os >> temp;
        if (temp < Ni) {
          dp[i] += std::pow(M, N - i - 1);  // 逐个累计
        } else if (temp == Ni) {
          dp[i] += dp[i + 1];  // 若相等则当前计数为后一位的计数
        }
      }
    }
    for (int i = 1; i < N; ++i) {  // 除去最高位的累计和
      dp[0] += std::pow(M, i);     // 1 ~ N-1 位数
    }
    return dp[0];
  }
};
// @lc code=end
