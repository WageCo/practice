/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */
#include <bits/stdc++.h>
using std::string;
using std::vector;
using std::set;
// @lc code=start
class Solution {
public:
    bool isPathCrossing(string path) {
        if (path.size() <=1 ) return false;
        set<vector<int> > visited;
        int x = 0;
        int y = 0;
        visited.insert({x, y});
        for (auto i : path){
            switch (i)
            {
            case 'N':
                ++y;
                break;
            case 'W':
                --x;
                break;
            case 'E':
                ++x;
                break;
            case 'S':
                --y;
                break;
            default:
                return false;
            }
            if (visited.find({x, y}) != visited.end()){
                return true;
            }else{
                visited.insert({x, y});
            }
        }
        return false;
    }
};
// @lc code=end

