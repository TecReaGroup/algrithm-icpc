# cpp 语法 / STL

## Syntax 语法

### Recursion 递归

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

### sturct 构造函数

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

## STL

### STL 数据结构

- **unordered_set**

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

- **vector**

`vector<varible_type> varible_name;`

基础操作: begin, empty, push_back, pop_back, clear, size, erase, front, back, resize

- **stack**

`stack<varible_type> varible_name;`  // FILO: first in, last out

基础操作: push, pop, top, empty, size

- **queue**

`queue<varible_type> varible_name;`  // FIFO: first in, first out

基础操作: push, pop, back, front, empty, size

- **deque 双向队列**

`dequeue<varible_type> vatible_name`

基本操作: front, back, pussh_back, push_front, pop_back, pop_front, empty, size

- **set / multiset**

`set<varible_type> varible_name;`

基础操作: insert, clear, erase, size, empty, swap, find, count

- **map / multimap**

`map<varible_type, varible_type> varible_name;`

基本操作: size, empty, swap, insert, clear, erase, find(key), count(key), varible_name(key)

- **priority_queue**

`priority_queue<int> variable_name;`

基础操作: push, pop, top, size, empty, swap, emplace

优先级设置 - 基本数据类型:  // greater 和 less 为仿函数(是一个类, 使用像函数一样使用)

`priority_queue<Type, Container, Functional>`

`priority_queue <int, vector<int>, less<int> > q;`  // 降序

`priority_queue <int, vector<int>, greater<int> > q;`  // 升序

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

void main(){
    priority_queue<fruit> p;
};
```

### STL 函数

- **lower_bound 与 distance**

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
