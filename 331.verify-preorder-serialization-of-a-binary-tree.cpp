/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */
#include <bits/stdc++.h>
using std::string;
using std::vector;
// @lc code=start
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    std::istringstream is(preorder);
    string node;
    int diff = 1;
    while (std::getline(is, node, ',')) {
      if (--diff < 0) return false;
      if (node != "#") diff += 2;
    }
    return (diff == 0);
    // The tree is full binary tree.
  }
};
// @lc code=end
