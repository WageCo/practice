/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */
#include <bits/stdc++.h>
using std::regex;
using std::string;
using std::vector;
// @lc code=start
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    regex rg("\\d+,#,#");
    string newpreorder = std::regex_replace(preorder, rg, "#");
    return (newpreorder == "#") ||
           (newpreorder != preorder && isValidSerialization(newpreorder));
  }
};
// @lc code=end
