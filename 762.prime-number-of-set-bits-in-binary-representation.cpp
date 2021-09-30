/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */
#include <bits/stdc++.h>
using std::bitset;
// @lc code=start
class Solution {
 public:
  int countPrimeSetBits(int left, int right) {
    int count = 0;
    for (int i=left; i<=right; ++i) {
      count += 545925292 >> bitset<32>(i).count() & 0x01;
    }
    return count;
  }
};
// @lc code=end
