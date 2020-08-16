struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct cmp {
    bool operator() (pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    }
};

struct myHash {
    size_t operator()(vector<int> _vec) const {
        return static_cast<size_t>(_vec[0] * 10 + _vec[1]);
    }
};

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


// Trie construc
struct node {
    char c;
    vector<node*> children;
    int isEnd;

    node(char _c) : c(_c), isEnd(0), children(vector<node*>(26)) {
    }
};

class Trie {
private:
    node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node('@');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cur->children[index] == nullptr) {
                node *tmp = new node(word[i]);
                cur->children[index] = tmp;
            }
            cur = cur->children[index];
            if (i == word.size() - 1) cur->isEnd = 1;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cur->children[index] == nullptr) {
                return false;
            }
            cur = cur->children[index];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (cur->children[index] == nullptr) {
                return false;
            }
            cur = cur->children[index];
        }
        return true;
    }
};

// Trie by array
class TrieArray {
public:
    /** Initialize your data structure here. */
    TrieArray() : _tr(vector<vector<int>>(1, vector<int>(26, 0))), _ct(0), _end(vector<int>(1, 0)) {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int k = 0;
        for (int i = 0; i < word.size(); ++i) {
            int cur = word[i] - 'a';
            if (!_tr[k][cur]) {
                _tr.push_back(vector<int>(26, 0));
                _end.push_back(0);
                _tr[k][cur] = ++_ct;
            }
            k = _tr[k][cur];
        }
        _end[k] = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int k = 0;
        for (int i = 0; i < word.size(); ++i) {
            int cur = word[i] - 'a';
            k = _tr[k][cur];
            if (!k) return false;
        }

        return _end[k];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int k = 0;
        for (int i = 0; i < prefix.size(); ++i) {
            int cur = prefix[i] - 'a';
            k = _tr[k][cur];
            if (!k) return false;
        }

        return true;
    }
private:
    vector<vector<int>> _tr;
    vector<int> _end;
    int _ct;
};


