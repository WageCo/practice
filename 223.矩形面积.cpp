/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aArea = (ax1 - ax2) * (ay1 - ay2);
        int bArea = (bx1 - bx2) * (by1 - by2);
        /* 公式为 一维向量 重叠, 拓展到二维图形 重叠  */
        int X = std::max(0, std::min(bx2, ax2) - std::max(bx1, ax1));
        int Y = std::max(0, std::min(by2, ay2) - std::max(by1, ay1));
        int crossArea = X*Y;
        return aArea - crossArea + bArea;
    }
};
// @lc code=end

