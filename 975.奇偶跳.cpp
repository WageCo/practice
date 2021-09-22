/*
 * @lc app=leetcode.cn id=975 lang=cpp
 *
 * [975] 奇偶跳
 */
#include <bits/stdc++.h>
using std::list;
using std::vector;
using std::set;

// @lc code=start
class Solution {
   public:
    int oddEvenJumps(vector<int>& arr) {
        int i = 0, j = 0;
        int step = 0;
        int current = arr[i];
        int temp = current;
        int jj = -1;
        arr_size = arr.size();
        if (arr_size == 1) {
            return 1;
        }
        while (1) {
            ++step;
            current = arr[j];
            temp = current;
            jj = -1;
            if (step % 2 == 0) {
                // operator is even jump
                for (int k = j + 1; k < arr_size; ++k) {
                    if (arr[k] <= current) {
                        if (jj == -1) {
                            temp = arr[k];
                            jj = k;
                            continue;
                        }
                        if (temp < arr[k]) {
                            temp = arr[k];
                            jj = k;
                        }
                    }
                }
            } else {
                // operator is odd jump
                for (int k = j + 1; k < arr_size; ++k) {
                    if (arr[k] >= current) {
                        if (jj == -1) {
                            temp = arr[k];
                            jj = k;
                            continue;
                        }
                        if (temp > arr[k]) {
                            temp = arr[k];
                            jj = k;
                        }
                    }
                }
            }
            if (jj != -1) {
                j = jj;
            } else {
                ++i;
                j = i;
                step = 0;
                if (i == arr_size) {
                    break;
                }
            }
            if (j == arr_size - 1 && i != j) {
                ++i;
                j = i;
                ++count;
                step = 0;
            }
            if (i == arr_size - 1) {
                ++count;
                break;
            }
        }
        return count;
    }

   private:
    int count = 0;
    int arr_size;
};
// @lc code=end
