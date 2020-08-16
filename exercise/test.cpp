#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<string>
#include<unordered_set>

using namespace std;


class Trie {
private:
    vector<vector<int>> tr;
    vector<int> isEnd;
    int ct;
public:
    Trie() {
        tr = vector<vector<int>> (1, vector<int>(26, 0));
        ct = 0;
        isEnd = vector<int>(1, 0);
    }

    void insert(string word) {
        int k = 0;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!tr[k][index]) {
                tr[k][index] = ++ct;
                tr.push_back(vector<int>(26, 0));
                isEnd.push_back(0);
            }
            k = tr[k][index];
        }
        isEnd[k] = 1;
    }

    bool search(string word) {
        int k = 0;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!tr[k][index]) return false;
            k = tr[k][index];
        }

        return isEnd[k];
    }

    bool startsWith(string prefix) {
        int k = 0;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (!tr[k][index]) return false;
            k = tr[k][index];
        }

        return true;
    }

    int searchLetter(int k, char c) {
        if (k > ct || k < 0) return -1;
        int index = c - 'a';
        return tr[k][index];
    }

    bool searchEnd(int k) {
        if (k > ct || k < 0) return -1;
        return isEnd[k];
    }

    void showEnd() {
        for (int i = 1; i <= ct; ++i) {
            if (isEnd[i]) cout << i << ' ';
        }
        cout << endl;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const auto &word : words) {
            twords.insert(word);
        }

        twords.showEnd();

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                string tmp;
                dfs(board, i, j, 0, tmp);
            }
        }

        vector<string> result;
        for (const auto &s : res) {
            result.push_back(s);
        }

        return result;
    }
private:
    Trie twords;
    unordered_set<string> res;
    vector<vector<int>> d{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    void dfs(vector<vector<char>>& board, int x, int y, int k, string& tmp) {
        cout << "flag1" << x << ' ' << y << endl;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return;
        }
        cout << "flag2" << x << ' ' << y << endl;

        if (board[x][y] == '@') return;
        int nxt = twords.searchLetter(k, board[x][y]);
        cout << x << ' ' << y << endl;
        cout << k << ' ' << board[x][y] << ' ' << nxt << endl;
        cout << "----" << endl;
        if (!nxt) return;
        tmp.push_back(board[x][y]);
        char cur = board[x][y];
        board[x][y] = '@';
        if (twords.searchEnd(nxt)) res.insert(tmp);

        for (int i = 0; i < d.size(); ++i) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            cout << nx << '@' << ny << endl;
            dfs(board, nx, ny, nxt, tmp);
        }

        tmp.pop_back();
        board[x][y] = cur;
    }
};

int main(void) {
    vector<vector<char>> board{
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words{
        "eat", "oath", "pea", "rain"
    };

    vector<vector<char>> board1{
        {'a', 'a'}
    };
    vector<string> words1{
        "aa"
    };

    vector<string> res = Solution().findWords(board1, words1);
    for (const auto &s : res) cout << s << endl;
    return 0;
}