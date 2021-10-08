/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */
#include <bits/stdc++.h>
using std::vector;
// @lc code=start
class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>> &properties) {
    int weakers = 0;
    std::sort(properties.begin(), properties.end(),
              [](vector<int> &it1, vector<int> &it2) {
                if (it1[0] == it2[0]) {
                  return (it1[1] > it2[1]);
                }
                return (it1[0] < it2[0]);
              });
    int maximum = INT_MIN;
    for (int i = properties.size() - 1; i >= 0; --i) {
      if (properties[i][1] < maximum) {
        ++weakers;
      }
      maximum = std::max(maximum, properties[i][1]);
    }
    return weakers;
  }
};
// @lc code=end
