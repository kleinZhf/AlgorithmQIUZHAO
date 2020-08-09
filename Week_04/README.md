学习笔记

# 动态规划
带有最优子结构的分治问题，通过最优子结构提前减少重复问题计算

## 递归模板
```
void recursion(int level, int parm) {
    terminator

    process current level

    drill down

    backtrack
}
```

## 分治模板
```
void divid_conquer(int level, int parm) {
    terminator

    prepare subproblems 

    conquer subproblems

    process curent logic and generate final results

    backtrack
}
```

## 解题感触
- 人肉递归低效、易出错
- 寻找最近最简子问题，拆分为可重复解决的问题
- 建立数学归纳法思维

## DP关键点
- 动态规划与递归分治没有本质区别（主要是最优子结构）
- 共性： 找到重复子问题
- 差异： DP有最优子结构，中途可以淘汰次优解

## DP模板
- 找到最优子结构
- 找到合适的中间状态存储
- 找到DP方程