/*
 * @lc app=leetcode.cn id=975 lang=cpp
 *
 * [975] 奇偶跳
 */
#include <bits/stdc++.h>
/** 来源
 * https://leetcode.com/problems/odd-even-jump/discuss/1415400/s%2B%2B-64ms-26mb.-O(N*logN)-mem-O9N)
 * dp[i].odd = dp[odd_jump_index[i]].even
 * dp[i].even = dp[even_jump_index[i]].odd
 * */
// @lc code=start
class Solution {
   public:
    int oddEvenJumps(vector<int>& arr) {
        std::map<int, std::pair<bool, bool>> dp;  // 数组+每个节点的奇偶跳状态
        int arr_size = arr.size();
        int count = 1;
        if (arr_size <= 1) return arr_size;
        dp[arr[arr_size - 1]] =
            std::make_pair(true, true);  // 最后一位设置为最佳起始点
        for (auto i = arr_size - 2; i >= 0; --i) {  // 从后向前
            int temp = arr[i];
            auto curstatus = std::make_pair(false, false);
            auto it = dp.lower_bound(temp); // 查找 >= temp 的key
            if (it != dp.end()) {
                curstatus.first =
                    it->second.second;  // dp[i].odd = dp[odd_jump_index[i]].even
            }
            if (it != dp.end() && it->first == temp) {  // 偶跳是指 小于等于的最大值 
                curstatus.second =
                    it->second.first;  // dp[i].even = dp[even_jump_index[i]].odd
            } else if (it != dp.begin()) {  // --it是确保小于当前值的最大值
                --it;
                curstatus.second = it->second.first;
            }
            count += (curstatus.first == true);  //因为第一次为奇跳
            dp[temp] = curstatus;
        }
        return count;
    }
};
// @lc code=end
