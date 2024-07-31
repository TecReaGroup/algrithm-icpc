# 算法

[Questions](./questions.md)

## 数学基础

### 快速幂

point: 将求积的过程由递增改为倍增

```cpp
// 快速幂函数
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // exp & 1 = 1
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;  // exp >>= 1
    }
    return result;
}
```

### 组合数

point: 杨辉三角 C(n, m) = C(n - 1, m - 1) + C(n - 1, m), 迭代

```cpp
// 计算组合数C(n, k)
void combination(vector<vector<int>>& a, int mod, int n) {
    for (int i = 0; i <= n; ++i) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % mod;
        }
    }
}
```

### 大数加法/阶乘

point: 利用数组存储每一位数据, 注意需要临时变量存储进位值

## 基础算法

### 双向指针

- 前后缀分解 接雨水: 由"短板"决定其周围的水高度

- 两/三数之和

### 同向双指针(滑动窗口)

main point: 某端点延伸，另一端点不断缩小至条件状态

- 最短/长方案数

  代码样例:

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), ans = n + 1, sum = 0, left = 0;
        for (int right = 0; right < n; right++) { // 枚举子数组右端点
            sum += nums[right];
            while (sum - nums[left] >= target) { // 尽量缩小子数组长度
                sum -= nums[left++]; // 左端点右移
            }
            if (sum >= target) {
                ans = min(ans, right - left + 1);
            }
        }
        return ans <= n ? ans : 0;
    }
};
```

题目:

- [滑动窗口题单](https://leetcode.cn/circle/discuss/0viNMK/)

- [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/solution/biao-ti-xia-biao-zong-suan-cuo-qing-kan-k81nh/)

- [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/xia-biao-zong-suan-cuo-qing-kan-zhe-by-e-iaks/)

- [713. 乘积小于 K 的子数组](https://leetcode.cn/problems/subarray-product-less-than-k/solution/xia-biao-zong-suan-cuo-qing-kan-zhe-by-e-jebq/)

- [2962. 统计最大元素出现至少 K 次的子数组](https://leetcode.cn/submissions/detail/546720221/)

- [2401. 最长优雅子数组](https://leetcode.cn/submissions/detail/546775567/)

### 二分查找

point: 根据二分法不断缩小范围直至符合条件, 确定二分范围和染色规则

数据特性: 子(原)序列具有单调性

常见题目问法:"最小化最大值"就是二分答案的代名词

- 红蓝染色法

  point:

  - 以红蓝区间区分比 `target` 大 / 小的数, 不断更新维护区间

  - `<`, `>`, `<=`, `>=` 条件之间的转换: 以 `>=` 为基准, `<` 则可以转化为 `>=` 点左侧元素(数组升序), 这样便转换为求 `>=` 的问题

题目:

- [二分题单](https://leetcode.cn/circle/discuss/SqopEo/)

- [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-zong-shi-xie-bu-dui-yi-g-t9l9/)

- [2439. 最小化数组中的最大值](https://leetcode.cn/problems/minimize-maximum-of-array/)

- [875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/)

- [162. 寻找峰值](https://leetcode.cn/problems/find-peak-element/solution/by-endlesscheng-9ass/)

- [1901. 寻找峰值 II](https://leetcode.cn/problems/find-a-peak-element-ii/)

- [153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/solution/by-endlesscheng-owgd/)

- [33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/by-endlesscheng-auuh/)

- [154. 寻找旋转排序数组中的最小值 II](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/)

### 单调栈

point: 删除无用元素, 维护栈的单调性和有效性

[739. 每日温度](https://leetcode.cn/problems/daily-temperatures/solution/shi-pin-jiang-qing-chu-wei-shi-yao-yao-y-k0ks/)

[42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/solution/zuo-liao-nbian-huan-bu-hui-yi-ge-shi-pin-ukwm/)

[239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/solution/shi-pin-yi-ge-shi-pin-miao-dong-dan-diao-ezj6/)

### 链表

- 反转链表

- 快慢指针

  - 寻找第 1/n 的节点: fast 移动速度是 slow 的 n 倍

  - 寻找倒数第 n 个节点, 让 fast 先走 short 与其保持 n 个单位距离

- 前后指针

- 删除指针

  - p->next = p->next->next

  - cur->val = cur->next->val; cur->next = cur->next->next;  // copy: 伪装成下一个节点

题目:

[206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/solution/you-xie-cuo-liao-yi-ge-shi-pin-jiang-tou-o5zy/)

[92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/solution/you-xie-cuo-liao-yi-ge-shi-pin-jiang-tou-teqq/)

[25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/solution/you-xie-cuo-liao-yi-ge-shi-pin-jiang-tou-plfs/)

[876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-wzwm/)

[141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-c4sw/)

[142. 环形链表II](https://leetcode.cn/problems/linked-list-cycle-ii/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-nvsq/)

[143. 重排链表](https://leetcode.cn/problems/reorder-list/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-u66q/)

[237. 删除链表中的节点](https://leetcode.cn/problems/delete-node-in-a-linked-list/solution/ru-he-shan-chu-jie-dian-liu-fen-zhong-ga-x3kn/)

[19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/ru-he-shan-chu-jie-dian-liu-fen-zhong-ga-xpfs/)

[83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/solution/ru-he-qu-zhong-yi-ge-shi-pin-jiang-tou-p-98g7/)

[82. 删除排序链表中的重复元素 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/solution/ru-he-qu-zhong-yi-ge-shi-pin-jiang-tou-p-2ddn/)

### 二叉树

- DFS: 递归: 深度优先搜索 数归: 数学正确性 栈: 调用数据结构

- BFS: 利用优先队列: 广度优先搜索

题目:

[104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/solution/kan-wan-zhe-ge-shi-pin-rang-ni-dui-di-gu-44uz/)

[112. 路径总和](https://leetcode.cn/problems/path-sum/)

[100. 相同的树](https://leetcode.cn/problems/same-tree/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-empk/)

[101. 对称二叉树](https://leetcode.cn/problems/symmetric-tree/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-6dq5/)

[110. 平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-c3wj/)

[199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-r1nc/)

[98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/solution/qian-xu-zhong-xu-hou-xu-san-chong-fang-f-yxvh/)

[236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solutions/2023872/fen-lei-tao-lun-luan-ru-ma-yi-ge-shi-pin-2r95/)

[235. 二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/2023873/zui-jin-gong-gong-zu-xian-yi-ge-shi-pin-8h2zc/)

[102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlpz/)

[103. 二叉树的锯齿形层序遍历](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlv3/)

[513. 找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-f34y/)

[102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlpz/)

[103. 二叉树的锯齿形层序遍历](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlv3/)

[513. 找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-f34y/)

### 回溯

point: 增量构造答案

- 回溯三问: 当前操作, 子问题, 下一个子问题

- 回溯类型

  - 子集型回溯: choose or not

  - 组合型回溯:

    - 减枝: 根据题目约束条件, 增加递归限制条件, 跳过不可能的分枝

    - 时间复杂度分析: Sum(叶子节点*高度)

  - 排列型回溯

- 两种思路: 输入视角, 答案视角

题目:

[17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/solutions/2059416/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-3orv/)

[78. 子集](https://leetcode.cn/problems/subsets/solutions/2059409/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-8tkl/)

[131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/solutions/2059414/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-fues/)

[77. 组合](https://leetcode.cn/problems/combinations/solutions/2071017/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-65lh/)

[216. 组合总和 III](https://leetcode.cn/problems/combination-sum-iii/solutions/2071013/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-feme/)

[22. 括号生成](https://leetcode.cn/problems/generate-parentheses/solutions/2071015/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-wcdw/)

[46. 全排列](https://leetcode.cn/problems/permutations/solution/hui-su-bu-hui-xie-tao-lu-zai-ci-jing-que-6hrh/)

[51. N 皇后](https://leetcode.cn/problems/n-queens/solution/hui-su-tao-lu-miao-sha-nhuang-hou-shi-pi-mljv/)

[52. N 皇后 II](https://leetcode.cn/problems/n-queens-ii/solution/hui-su-miao-sha-nhuang-hou-yi-ge-shi-pin-l41l)

### 动态规划

- 动态规划入门：从记忆化搜索到递推

题目:

[198. 打家劫舍](https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/)

[1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/solutions/2133188/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-lbz5/)

[72. 编辑距离](https://leetcode.cn/problems/edit-distance/solutions/2133222/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-uo5q/)

[300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/solution/jiao-ni-yi-bu-bu-si-kao-dpfu-o1-kong-jia-4zma/)

[583. 两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings/)

[712. 两个字符串的最小ASCII删除和](https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/)

[97. 交错字符串](https://leetcode.cn/problems/interleaving-string/)

[1458. 两个子序列的最大点积](https://leetcode.cn/problems/max-dot-product-of-two-subsequences/)

[1092. 最短公共超序列](https://leetcode.cn/problems/shortest-common-supersequence/)

## cpp 语法 / STL

### STL 数据结构

#### unordered_set

`unordered_set<varible_type> varible_name;`

基础操作: insert, erase, count

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, left = 0;
        unordered_set<char> window; // 维护从下标 left 到下标 right 的字符
        for (int right = 0; right < n; right++) {
            char c = s[right];
            // 如果窗口内已经包含 c，那么再加入一个 c 会导致窗口内有重复元素
            // 所以要在加入 c 之前，先移出窗口内的 c
            while (window.count(c)) { // 窗口内有 c
                window.erase(s[left++]); // 缩小窗口
            }
            window.insert(c); // 加入 c
            ans = max(ans, right - left + 1); // 更新窗口长度最大值
        }
        return ans;
    }
};
```

#### vector

`vector<varible_type> varible_name;`

基础操作: begin, empty, push_back, pop_back, clear, size, erase, front, back, resize

#### stack

`stack<varible_type> varible_name;`  // FILO: first in, last out

基础操作: push, pop, top, empty, size

#### queue

`queue<varible_type> varible_name;`  // FIFO: first in, first out

基础操作: push, pop, back, front, empty, size

#### deque 双向队列

`dequeue<varible_type> vatible_name`

基本操作: front, back, pussh_back, push_front, pop_back, pop_front, empty, size

#### set / multiset

`set<varible_type> varible_name;`

基础操作: insert, clear, erase, size, empty, swap, find, count

#### map / multimap

`map<varible_type, varible_type> varible_name;`

基本操作: size, empty, swap, insert, clear, erase, find(key), count(key), varible_name(key)

#### priority_queue

`priority_queue<int> variable_name;`

基础操作: push, pop, top, size, empty, swap, emplace

优先级设置 - 基本数据类型:  // greater 和 less 为仿函数(是一个类, 使用像函数一样使用)

`priority_queue<Type, Container, Functional>`

- `priority_queue <int, vector<int>, less<int> > q;`  // 降序

- `priority_queue <int, vector<int>, greater<int> > q;`  // 升序

优先级设置 - 自定义类型:   // 重载 `<` 运算符

```cpp
class fruit{
public:
    string name;
    int price;
    // friend bool operator < (fruit f1, fruit f2) {  // 重载 > 大于号会编译报错
    friend bool operator < (fruit f1, fruit f2){
        return f1.price < f2.price;  // 相当于默认大根堆, 就是没改变 < 的含义, 那就相当于是优先队列默认模式那就是大根堆
        // return f1.price > f2.price;  // 相当于小根堆, 就是改变 < 的含义, 那就相当于改变优先队列默认模式那就是小根堆
    }
};

...

priority_queue<fruit> p;
```

### STL 函数

#### lower_bound 与 distance

lower_bound: 二分查找

distance: 将迭代器转换为目标的索引

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1); // Initialize with -1 to indicate not found
        vector<int>::iterator lower = lower_bound(nums.begin(), nums.end(), target);
        vector<int>::iterator upper = lower_bound(nums.begin(), nums.end(), target + 1);
        if (lower != nums.end() && *lower == target) {
            ans[0] = distance(nums.begin(), lower);
            ans[1] = distance(nums.begin(), upper) - 1;
        }
        return ans;
    }
};
```

### Syntax

#### Recursion

匿名函数 - 函数内部递归调用:

```cpp
class Solution{
public:
    // 记忆化搜索
    int zero_one_knapsack(int capacity, vector<int> &w, vector<int> &v){
        // capacity is the capacity of the knapsack
        // w[i] is the weight of the i-th item
        // v[i] is the value of the i-th item
        // n is the number of items
        int n = w.size();
        vector<vector<int>> cache(n, vector<int>(capacity + 1, -1));
        function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0 || c == 0) return 0;    // no item left
            int &tmp = cache[i][c];
            if (tmp != -1) return tmp;
            if (c < w[i]) return tmp = dfs(i-1, c); // cannot put the i-th item into the knapsack
            return tmp = max(dfs(i-1, c), dfs(i-1, c-w[i]) + v[i]);
        };
        return dfs(n-1, capacity);
    }
}
```

#### sturct构造函数

构造函数: 是一个特殊的成员函数, 用于在创建对象时初始化对象的成员变量. 构造函数的名称与类名相同, 并且没有返回类型. 构造函数可以有参数, 也可以没有参数(即默认构造函数)

```cpp
// 使用成员初始化列表
struct ListNode {
    int val;
    ListNode* next;

    // 默认构造函数，将节点值初始化为0，指针初始化为nullptr
    ListNode() : val(0), next(nullptr) {}

    // 构造函数，接受一个整数参数，将节点值初始化为该参数，指针初始化为nullptr
    ListNode(int x) : val(x), next(nullptr) {}

    // 构造函数，接受一个整数参数和一个指向下一个节点的指针，将节点值和指针分别初始化为这两个参数
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}

// 在构造函数体内赋值
struct ListNode() {
    int val = 0;
    ListNode* next = nullptr;
}
```

## Tricks

- 防止溢出(先减后加, 先除后乘):
  - 平均数: (x + y)/2 -> x + (x - y)/2

- 在C++中, 有许多预定义的常数用于表示不同类型的最小值和最大值

```cpp
/*
<climits> 中定义的常数
CHAR_MIN 和 CHAR_MAX: 字符类型的最小值和最大值
SCHAR_MIN 和 SCHAR_MAX: 有符号字符类型的最小值和最大值
UCHAR_MAX: 无符号字符类型的最大值
SHRT_MIN 和 SHRT_MAX: 短整型的最小值和最大值
USHRT_MAX: 无符号短整型的最大值
INT_MIN 和 INT_MAX: 整型的最小值和最大值
UINT_MAX: 无符号整型的最大值
LONG_MIN 和 LONG_MAX: 长整型的最小值和最大值
ULONG_MAX: 无符号长整型的最大值
LLONG_MIN 和 LLONG_MAX: 长长整型（长长整数）的最小值和最大值
ULLONG_MAX: 无符号长长整型的最大值
<cfloat> 中定义的常数
FLT_MIN 和 FLT_MAX: 单精度浮点数的最小正值和最大值
DBL_MIN 和 DBL_MAX: 双精度浮点数的最小正值和最大值
LDBL_MIN 和 LDBL_MAX: 长双精度浮点数的最小正值和最大值
FLT_EPSILON: 单精度浮点数能够表示的最小的正数
DBL_EPSILON: 双精度浮点数能够表示的最小的正数
LDBL_EPSILON: 长双精度浮点数能够表示的最小的正数
*/
```
