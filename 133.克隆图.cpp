/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    void bfs(Node* node, std::function<void(Node* tmp)> f) {
        queue<Node*> bfs_queue;
        set<Node*> lookup_set;
        bfs_queue.push(node);
        lookup_set.insert(node);
        while (!bfs_queue.empty()) {
            auto tmp = bfs_queue.front();
            bfs_queue.pop();
            std::for_each(tmp->neighbors.begin(), tmp->neighbors.end(),
                          [&](Node* i) {
                              if (lookup_set.count(i) == 0) {
                                  bfs_queue.push(i);
                                  lookup_set.insert(i);
                              }
                          });
            f(tmp);
        }
    }
    Node* cloneGraph(Node* node) {
        Node* ret = nullptr;
        if (node == nullptr) return ret;
        vector<Node*> v;
        bfs(node, std::bind(
                      [&](Node* tmp) {
                          auto clone_node = new Node(tmp->val);
                          v.push_back(clone_node);
                      },
                      std::placeholders::_1));
        std::sort(v.begin(), v.end(), [](const Node* v1, const Node* v2) {
            return v1->val < v2->val;
        });
        bfs(node,
            std::bind(
                [&](Node* tmp) {
                    std::for_each(
                        tmp->neighbors.cbegin(), tmp->neighbors.cend(),
                        [&](const Node* i) {
                            v[tmp->val - 1]->neighbors.push_back(v[i->val - 1]);
                        });
                },
                std::placeholders::_1));
        ret = v.front();
        return ret;
    }
};
// @lc code=end
