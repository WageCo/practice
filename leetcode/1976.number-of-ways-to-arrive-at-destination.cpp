/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */
#include <bits/stdc++.h>
using std::vector;
using std::priority_queue;
// @lc code=start
constexpr int MOD = 1e9 + 7;
#define ll long long
#define pll std::pair<ll, ll>
class Solution {
public:
    int dijkstra(const vector<vector<pll>> &road, int n, int src){
        vector<ll> ways(n, 0);
        vector<ll> dist(n, LONG_MAX);
        priority_queue<pll, vector<pll>, std::greater<>> minHeap; // 小根堆
        dist[src] = 0;
        ways[src] = 1;
        minHeap.push(std::make_pair(0, 0)); // dist src
        while (!minHeap.empty()) {
            auto v1 = minHeap.top();    // 拿出最短路径
            minHeap.pop();
            ll d = v1.first;
            ll v = v1.second;
            if (d > dist[v])
                continue;
            for (auto i = road[v].begin(); i != road[v].end(); ++i) {
                if (dist[i->first] > i->second + d) {
                    dist[i->first] = i->second + d;
                    ways[i->first] = ways[v];
                    minHeap.push(std::make_pair(dist[i->first], i->first));
                } else if (dist[i->first] == i->second + d) {
                    ways[i->first] = (ways[i->first] + ways[v]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> road(n);
        for (auto i : roads) {  // store as 
            road[i[0]].emplace_back(std::make_pair(i[1], i[2]));
            road[i[1]].emplace_back(std::make_pair(i[0], i[2]));
        }
        return dijkstra(road, n, 0);
    }
};
// @lc code=end

