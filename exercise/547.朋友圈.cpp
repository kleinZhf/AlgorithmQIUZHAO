/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class UnionFind {
private:
    vector<int> root;
public:
    UnionFind(int n) : root(vector<int>(n, 0)) {
        for (int i = 0; i < n; ++i) root[i] = i;
    }

    int find(int x) {
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    void Union(int x, int y) {
        root[find(x)] = find(y);
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    int returnSize() {
        set<int> st;
        for (int i = 0; i < root.size(); ++i) st.insert(find(i));
        return st.size();
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind uf(n);

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j]) uf.Union(i, j);
            }
        }

        return uf.returnSize();
    }
};
// @lc code=end

