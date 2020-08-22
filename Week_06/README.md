学习笔记

# Bloom Filter
- hash table 拉链存储重复元素
- Bloom Filter 一个很长的二进制向量和一系列随机映射函数存储，用于检验一个元素是否在一个集合当中
- Bloom filter 空间效率和时间效率都远远超过一般算法，缺点是有一定误识别率和删除困难

## 操作原理
- 每一个元素通过映射函数映射到若干的二进制位，将这些位置置1表示将该元素插入Bloom Filter
- 查询一个元素如果其所映射的二进制位存在0，则其不在Bloom Filter中
- 查询一个元素如果其所映射的二进制位全为1，则其可能在Bloom Filter中
- Bloom Filter通常用于最外层的快速缓存查询

## 案例
- 比特币网络
- 分布式系统(Map-Reduce) -- Handoop, search engine
- Redis 缓存
- 垃圾邮件，评价等的过滤

# LRU Cache

## 特点
- 两个要素 大小，替换策略
- HashTable + DoubleLinkedList
- O(1) 查询，O(1) 修改、更新

### 替换策略
- LFU -- Least Frequently used
- LRU -- Least Recently used

# 排序算法

## 比较类排序
通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(nlongn)，因此也被称为非线性时间比较类排序。
- 交换排序
    - 冒泡排序 O(n^2) 稳定
    - 快速排序 O(nlogn) 不稳定
- 插入排序
    - 简单插入排序 O(n^2) 稳定
    - Shell排序 O(n^1.3) 不稳定
- 选择排序
    - 简单选择排序 O(n^2) 不稳定
    - 堆排序 O(nlongn) 不稳定
- 归并排序
    - 二路归并排序 O(nlongn) 稳定
    - 多路归并排序

## 非比较类排序
不通过比较来决定元素间的相对次序，它可以突破比较排序的时间下限，以线性时间运行，也称为非比较类排序
- 计数排序
- 桶排序
- 基数排序

## 初级排序
- 选择排序
每次找到最小值，然后放到起始位置
```
void selectSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int cur = i;
        for (int j = i; j < n; ++j) {
            cur = nums[cur] < nums[j] ? cur : j;
        }
        swap(nums[i], nums[cur]);
    }
}
```
- 插入排序
从前往后逐步扫描，对于未排序的元素，在已排序元素中找到其位置并插入
```
void insertSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int tmp = nums[i];
        for (int j = i; j >= 1; ++j) {
            if (nums[j - 1] > tmp) {
                nums[j] = nums[j - 1];
            }
            else {
                nums[j] = tmp;
                break;
            }
        }
    }
}
```
- 冒泡排序
嵌套循环，每次查看相邻元素如果逆序则交换
```
void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}
```

## 高级排序
- 快速排序
数组取一个标杆pivot，将小于pivot的元素放在左侧，大于pivot元素放到右侧，然后依次对左右部分进行快排
```
void quickSort(vector<int>& nums, int begin, int end) {
}
int partition(vector<int>& nums, int begin, int end) {
    int index = begin;
    int target = nums[end - 1];

    for (int i = begin; i < end - 1; ++i) {
        if (nums[i] < target) {
            swap(nums[i], nums[index++]);
        }
    }
    swap(nums[end - 1], nums[index]);
    return index;
}
```

- 归并排序
    - 将长度为n的序列分为两个n/2的子序列
    - 分别对这两个子序列归并排序
    - 将两个子序列合并为最终有序序列

- 堆排序
    - 堆 插入删除O(logn), 取堆顶O(1)
    - 数组元素依次建立小顶堆
    - 依次取堆顶元素

# 高级动态规划
复制度来源
- 状态拥有更多维度(二维、三维甚至更多，甚至需要压缩)
- 状态方程更复杂

## 不同路径II的状态转移方程
定义dp[i][j] 为从(0, 0)走到(i, j)的方法数
- dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1]

# 字符串

## 高级字符串算法
基本与动态规划相结合

### 编辑距离

### 最长公共子序列


## 字符串匹配算法

### KMP算法
