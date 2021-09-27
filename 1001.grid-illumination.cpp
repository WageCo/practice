/*
 * @lc app=leetcode id=1001 lang=cpp
 *
 * [1001] Grid Illumination
 */
#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;
using std::unordered_set;
// think like votrubac
// @lc code=start
class Solution {
public:
    #define make_coordinate(x, y) std::make_pair(x, y)
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ret;
        unordered_map<int, int> x, y, a_d, d_d;
        unordered_map<int, unordered_set<int>> ls;
        for (auto l : lamps) {
            auto i = l[0];
            auto j = l[1];
            // 记录灯的位置 计数+1
            if (ls[i].insert(j).second)
                ++x[i], ++y[j], ++a_d[i + j], ++d_d[i - j];
        }
        std::for_each(
            queries.cbegin(), queries.cend(),
            [&](const vector<int> &coordinate_) { // 2D
                auto v0 = make_coordinate(coordinate_[0], coordinate_[1]);
                if (x[v0.first] || y[v0.second] || a_d[v0.first + v0.second] ||
                    d_d[v0.first - v0.second]) {
                    ret.emplace_back(1);
                    for (auto li = v0.first - 1; li <= v0.first + 1; ++li)
                        for (auto lj = v0.second - 1; lj <= v0.second + 1;
                             ++lj) {
                            if (ls[li].erase(lj)) {
                                // 计数-1
                                --x[li]; 
                                --y[lj];
                                --a_d[li + lj]; 
                                --d_d[li - lj];
                            }
                        }
                } else {
                    ret.emplace_back(0);
                }
            });
        return ret;
    }
};
// @lc code=end

