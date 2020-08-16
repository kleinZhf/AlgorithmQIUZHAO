/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

