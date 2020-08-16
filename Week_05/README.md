学习笔记

# 字典树Trie和并查集

## 字典树Trie
最大限度地减少无谓的字符串比较，查询效率比哈希表高

### 基本性质
- 节点本身不存储完整单词
- 从根节点到叶子节点的路径存储一个完整的字符串
- 节点的每个子节点存储的字符不同
- 查询次数为单词的长度

### 单词搜索II
- words 遍历 --> board O(m*N^2*4^k)

- trie 
    * all words --> Trie 构建prefix
    * board, DFS

#### 复杂度分析
- 构建Trie需要words个数m乘以word平均长度k，即O(mk)
- 搜索一个单词平均复杂度O(k)
- 需要对board中每个位置都开始一次搜索即O(n^2)
- 每一次board搜索最坏需要O(4^k)时间复杂度
- 总的时间复杂度O(mk + kn^2)
- 空间复杂度主要用于存储Trie，最坏需要mk个节点存储所有的words，空间复杂度O(mk)

## 并查集
解决组团和配对问题

### 基本操作
- 新建一个并查集
- Union(x, y): 把x和y所在的集合合并
- find(x): 找到x所在集合的代表

```
class UnionFind {
private:
    vector<int> _root;
public:
    UnionFind (int n) : _root(vector<int>(n, 0)) {
        for (int i = 0; i < n; ++i) _root[i] = i;
    }

    int find(int x) {
        if (_root[x] == x) return x;
        return _root[x] == find(_root[x]);
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    void Union(int x, int y) {
        _root[find(x)] = find(y);
    }
};
```

# 高级搜索
- 剪枝
- 去重复
- 双向BFS
- 启发式搜索

## 双向BFS
```
int doubleDirectBFS(begin, end, dict) {
    // if end is not in searching space return
    if (dict.find(end) == dict.end()) return -1;

    // using set instead of queue to store levels from begin 
    // and end, which can be more convenient for searching
    set beginSet{begin};
    set endSet{end};

    // using a int to store current level
    int level = 1;

    // using a flag to indicate whethear searching is finished
    int findEnd = 0;
    // using a flag to indicate current searching set is from 
    // begin or end
    int setflag = 0;

    while (!beginSet.empty()) {
        ++level;
        set tmpSet;

        // erase beginSet in dict

        // process beginSet and store branches in tmpSet
        // if any branch show up in endSet we find the 
        // shortest path

        // let the small one in tmpSet and endSet be beginSet
        // decide the setflag

        if (findEnd) break;
    }

    return level;
}
```

## 启发式搜索heuristic search(A*)
```
def AstarSearch(graph, start, end):
    pq = collections.priority_queue()
    pq.append([start])
    visited.add(start)

    while pq:
        node = pq.pop()
        visited.add(node)

        process(node)
        nodes = generate_related_nodes(node)
        unvisited = [node for node in nodes if node not in visited]
        pq.push(unvisited)
```

# 高级树，AVL树，红黑树

## 保证性能的关键
- 保证二维维度 --> 左右子树平衡
- balanced

## AVL树
- G. M. Adelson-Velsky 和 Evgenii Landis
- Balance Factor: 左子树高度减去右子树高度 {-1， 0， 1}
- 通过旋转操作进行平衡

### 旋转操作
- 左旋 a < b < c 右右子树
- 右旋 a > b > c 左左子树
- 左右旋 a > c > b 左右子树
- 右左旋 a < c < b 右左子树

### 带有子树的旋转

### AVL总结
- 平衡二叉树
- 每个节点存balance factor = {-1， 0， 1}
- 四种旋转操作
- 不足：节点需要存储额外信息，调整次数频繁

## 红黑树
红黑树是一种近似平衡二叉树，确保任何一个节点的左右子树高度差小于两倍
- 每个节点要么红色，要么黑色
- 根节点是黑色
- 每个叶子节点(null节点)是黑色
- 不能有相邻的两个红色节点
- 从任一节点到其每个叶子所有路径都包含相同数目黑色节点

# 位运算
- 位运算符
- 算术移位与逻辑移位
- 位运算运用

## 位运算符
- 左移 <<
- 右移 >>
- 按位或 |
- 按位与 &
- 按位取反 ~
- 按位异或 ^

### XOR-异或
- x^0 = x
- x^1s = ~x (1s表示全为1)
- x^(~x) = 1s
- x^x = 0
- c = a^b --> a^c = b, b^c = a (交换两个数)
- a^b^c = a^(b^c) = (a^b)^c (结合律)

## 指定位置的位运算
- 将x最右n位清零： x&(~0 << n)
- 获取x的第n位: (x>>n)&1
- 获取x的第n位的幂值： x&(1 << n)
- 仅将第n位置1：x|(1 << n)
- 仅将第n位置0：x&(~(1 << n))
- 将x最高位至第n位清零：x&((1 << n) - 1)

## 实战要点
- 判断奇偶：(x&1) == 1, (x&1) == 0
- x >> 1 --> x / 2
- x = x&(x - 1) 清零最低位的1
- x&-x --> 得到最低位的1
- x&~x = 0