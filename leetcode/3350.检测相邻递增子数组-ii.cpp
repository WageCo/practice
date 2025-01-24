/*
 * @lc app=leetcode.cn id=3350 lang=cpp
 *
 * [3350] 检测相邻递增子数组 II
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        auto max = 1; // 单次严格递增的长度
        auto pre_max = max;
        auto k = 1; 
        auto min = 0;

        // 遍历一次
        for (auto i = 0; i < nums.size(); ++i)
        {
            if ((i < nums.size() - 1) && nums[i+1] > nums[i])
            {
                ++max;
            }
            else 
            {
                // 不是严格递增
                if (k < max / 2)
                {
                    // 单个数组内部最大可以拆分成2个
                    k = max / 2;
                }

                // 数组间符合题意
                min = max > pre_max ? pre_max : max;
                if (k < min)
                {
                    k = min;
                }
                
                // // 判断是否需要提前退出
                // if (k == nums.size() / 2)
                // {
                //     break;
                // }

                // 记录当前最长数组
                pre_max = max;
                
                // 初始化下一个数组的长度
                max = 1;
            }
            // cout << "[" << i << "]" << " k:" << k << ", pre_max:" << pre_max << ", max:" << max << endl;
        }

        return k;
    }
};
// @lc code=end

