/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */
#include <bits/stdc++.h>
using std::queue;
using std::unordered_map;
using std::vector;
// @lc code=start
class Solution {
 public:
  int minJumps(vector<int>& arr) {
    // BFS
    // Like A Tree
    const int arr_size = arr.size();
    vector<int> counts(arr_size, -1);               // depth
    unordered_map<int, vector<int> > indexOfValue;  // store duplicate nums
    for (int i = 0; i < arr_size; i++) indexOfValue[arr[i]].emplace_back(i);
    queue<int> bfs_queue;
    vector<bool> visited(arr_size, false);
    bfs_queue.push(0);  // first index
    ++counts[0];
    visited[0] = true;
    while (!bfs_queue.empty()) {
      int it = bfs_queue.front();
      bfs_queue.pop();
      for (int i = it - 1; i <= std::min(arr_size - 1, it + 1); ++i) {
        if (i < 0 || visited[i]) continue;
        // if the index were visited, the next jump's depth will be larger.
        if (i == it - 1 || i == it + 1) {
          // jump to it+1 or it-1
          if (i == arr_size - 1) {
            return counts[it] + 1;
          }
          bfs_queue.push(i);
          counts[i] = counts[it] + 1;  // depth add 1
          visited[i] = true;           // mark
        }
      }
      for (auto i : indexOfValue[arr[it]]) {
        // jump to j (arr[j]==arr[it]) but j!=it
        if (i != it && visited[i] != true) {
          if (i == arr_size - 1) {
            return counts[it] + 1;
          }
          bfs_queue.push(i);
          counts[i] = counts[it] + 1;  // depth add 1
          visited[i] = true;           // mark
        }
      }
      indexOfValue[arr[it]].clear();
    }
    return counts[arr_size - 1];
  }
};
// @lc code=end
