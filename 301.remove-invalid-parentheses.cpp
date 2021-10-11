/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */
#include <bits/stdc++.h>
using std::stack;
using std::string;
using std::vector;
// @lc code=start
class Solution {
 private:
  void remove(string s, vector<string> &ans, int start, int last_remove,
              vector<char> extra) {
    for (int stack_ = 0, i = start; i < s.size(); ++i) {
      if (s.at(i) == extra[0]) ++stack_;
      if (s.at(i) == extra[1]) --stack_;
      if (stack_ >= 0) continue;
      // Mismatching
      for (int j = last_remove; j <= i; ++j) {
        if (s.at(j) == extra[1] &&
            (j == last_remove || s.at(j - 1) != extra[1]))
          // delete duplication
          remove(s.substr(0, j) + s.substr(j + 1, s.length()), ans, i, j,
                 extra);
      }
      return;
    }
    // reverse
    string s_revered;
    std::reverse_copy(s.begin(), s.end(), std::back_inserter(s_revered));
    if (extra[0] == '(')  // right to left
      remove(s_revered, ans, 0, 0, {')', '('});
    else  // finish
      ans.emplace_back(s_revered);
  }

 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    remove(s, ans, 0, 0, {'(', ')'});
    return ans;
  }
};
// @lc code=end
