/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */
#include <bits/stdc++.h>
using std::vector;
// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size <= 2)
            return 0;
        vector<int> diff;
        diff.reserve(nums_size - 1); // Diff between the numbers
        int temp = -1;
        for (auto i = nums.cbegin(); i != nums.cend(); ++i) {
            if (i == nums.cbegin()) {
                temp = *i;
                continue;
            }
            diff.emplace_back(*i - temp);
            temp = *i; // temp is value of previous one
        }
        vector<int> counts;
        int count = 1;
        for (auto i = diff.cbegin(); i != diff.cend(); ++i) {
            if (i == diff.cbegin()) {
                temp = *i;
                continue;
            }
            if (*i == temp) {
                ++count;
            } else {
                if (count != 1) {
                    counts.emplace_back(count); // count
                }
                count = 1;
                temp = *i;
            }
        }
        if (count != 1) {               // last one
            counts.emplace_back(count); // count
        }
        int sum = 0;
        auto recursivefunc =
            std::make_shared<std::unique_ptr<std::function<int(int)>>>();
        *recursivefunc =
            std::make_unique<std::function<int(int)>>([&](int count) -> int {
                return (count == 3) ? 1 : (**recursivefunc)(count - 1) + count - 2;
                /* f(count) = f(count - 1) + count - 2; */
            });
        std::for_each(counts.begin(), counts.end(), [&](int &count) {
            ++count; // count -> nums
            sum += (**recursivefunc)(count);
        });
        return sum;
    }
};
// @lc code=end

