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

- 前后缀分解 接雨水

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

point: 根据二分法不断缩小范围直至符合条件

- 常见题目问法:
  - 「最小化最大值」就是二分答案的代名词

- 红蓝染色法

  point:

  - 以红蓝区间区分比 `target` 大 / 小的数, 不断更新维护区间

  - `<`, `>`, `<=`, `>=` 条件之间的转换: 以 `>=` 为基准, `<` 则可以转化为 `>=` 点左侧元素(数组升序), 这样便转换为求 `>=` 的问题

题目:

- [二分题单](https://leetcode.cn/circle/discuss/SqopEo/)

- [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-zong-shi-xie-bu-dui-yi-g-t9l9/)

- [2439. 最小化数组中的最大值](https://leetcode.cn/problems/minimize-maximum-of-array/)

- [875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/)

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

优先级设置 - 自定义类型：  // 重载 `<` 运算符

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

## Tricks

- 平均数防止溢出: (x + y)/2 -> x + (x - y)/2
