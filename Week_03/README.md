学习笔记

# 分治回溯
## 递归模板
```
void recursion(level, param1, param2, ...) {
    //terminator
    if (level > MAX_LEVEL) {
        process_result
        return
    }

    //process logic in current level
    process(level, data...)

    //drill down
    recursion(level+1, p1, ...)

    //reverse the current level status if needed
}
```

## 分治模板
```
void divide_conquer(problem, p1, p2, ...) {
    //recursion terminator
    if (problem == NULL) {
        process_result;
        return;
    }

    //prepare data
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)

    //conquer subproblems
    subresult1 = divide_conquer(subproblems[0], p1, ...)
    subresult2 = divide_conquer(subproblems[0], p1, ...)
    subresult3 = divide_conquer(subproblems[0], p1, ...)

    //process and generate the final result
    result = process_result(subresult1, subresult2, ...)
}
```

## 回溯

# 习题
## Pow(x, n)
- 暴力法 O(n)
- 分治法 递归
    Pow(x, n) --> Pow(x, n) * Pow(x, n) * (n % 2 ? x : 1)
- 快速幂 迭代
```
while(n) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
}

## 子集
- 二分递归
- 列出 1 << n 所代表的所有子集

## 电话号码字母组合
- 分治 递归

## N皇后
- 每一行可能的位置进行拆分子问题
- 递归每一行合法的位置
- 利用bitmask存储每一行可能的位置，利用位运算确定合法的状态

# DFS和BFS

## DFS

### 递归写法
```
void dfs(node) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;

    for (auto &next : node->edge) {
        dfs(next);
    }
}
```

### 迭代写法
```
void dfs(node) {
    stack<Node*> S;
    S.push(node);
    visited[node] = true;

    while (!S.empty()) {
        root = S.top();
        S.pop();
        process(root);
        for (const auto &next : root->edge) {
            if (visited[next]) continue;
            visited[next] = true;
            S.push(next);
        }
    }
}
```

## BFS
```
void bfs(root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        root = q.front();
        q.pop();
        process(root);
        for (auto &next : root->edge) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
}
```

# 贪心算法
每一步都采取当前状态下的最优解从而希望达成全局最优解的算法

# 二分查找
```
int binarySearch(nums, target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return -1;
}

## 求sqrt(x)
- 二分查找求解

## 使用二分查找，寻找旋转排序数组的旋转点
- 选择排序数组特点[ai < ai+1 < ... < an > a0 < a1 < ... ai-1]
- ai > ai-1, a0 < ai
```
int findRot(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < a[right]) {
            right = mid - 1;
        }
        else {
            left = mid;
        }
    }
    return left;
}
```