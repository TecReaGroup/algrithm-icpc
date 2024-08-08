# Tricks

## 数学技巧

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

## 代码技巧

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
