/*
 * @lc app=leetcode id=1001 lang=cpp
 *
 * [1001] Grid Illumination
 */
#include <bits/stdc++.h>
using std::vector;
using std::queue;
// @lc code=start
class Solution {
public:
    using coordinate = std::pair<int, int>;
    #define make_coordinate(x, y) std::make_pair(x, y)
    int isLightOn(int n, vector<vector<int>>& lamps, coordinate coordinate_){
        int x1 = coordinate_.first - 1 >= 0 ? coordinate_.first - 1 : 0;
        int x2 = coordinate_.first + 1 < n ? coordinate_.first + 1 : n - 1;
        int y1 = coordinate_.second - 1 >= 0 ? coordinate_.second - 1 : 0;
        int y2 = coordinate_.second + 1 < n ? coordinate_.second + 1 : n - 1;
        int ret = 0;
        for (int i = 0; i < lamps.size(); ++i) {
            if (lamps[i][0] == -1 && lamps[i][1] == -1)
                continue;
            auto v0 = make_coordinate(lamps[i][0], lamps[i][1]);
            if (v0.first >= x1 && v0.first <= x2 && 
                v0.second >= y1 && v0.second <= y2) {
                // 有灯的点标记为无用的点
                lamps[i][0] = -1;
                lamps[i][1] = -1;
            }
            if (v0.first == coordinate_.first ||
                v0.second == coordinate_.second ||
                v0.first - v0.second ==
                    coordinate_.first - coordinate_.second ||
                v0.first + v0.second ==
                    coordinate_.first + coordinate_.second) {
                // 判断是否亮
                ret = 1;
            }
        }
        return ret;
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ret;
        std::for_each(queries.cbegin(), queries.cend(),
                      [=, &ret, &lamps](const vector<int> &coordinates) {
                          // 2D
                          ret.emplace_back(isLightOn(
                              n, lamps,
                              make_coordinate(coordinates[0], coordinates[1])));
                      });
        return ret;
    }
};
// @lc code=end

