/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */
#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;
// @lc code=start
class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    unordered_map<int, int> distance_map;
    int sum = 0;
    for (auto &i : points) {
      for (auto &j : points) {
        if (&i == &j) continue;
        int dx = i[0] - j[0];
        int dy = i[1] - j[1];
        int tmp = dx * dx + dy * dy;
        auto it = distance_map.find(tmp);
        if (it != distance_map.end()) {
          ++it->second;
        } else {
          distance_map.insert(std::make_pair(tmp, 1));
        }
      }
      for (auto i : distance_map) {
        if (i.second >= 2) {
          sum += i.second * (i.second - 1);
        }
      }
      distance_map.clear();
    }
    return sum;
  }
};
// @lc code=end

