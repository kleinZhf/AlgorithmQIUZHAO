/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class UnionFind {
private:
    vector<int> root;
public:
    UnionFind(int n) : root(vector<int>(n, 0)) {
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (root[x] == x) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    bool isConnected(int x, int y) {
        return find[x] == find[y];
    }

    void Union(int x, int y) {
        root[find(x)] = find(y);
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n <= 2) return true;

        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            for (const auto &e : graph[i])  {
                if (uf.isConnected(e, i)) return false;
                uf.Union(e, graph[i][0]);
            }
        }

        return true;
    }
};
// @lc code=end

