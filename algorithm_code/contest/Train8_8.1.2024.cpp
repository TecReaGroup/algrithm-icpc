// # include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<vector<int>> a(n, vector<int>(2));
//     for (int i = 0; i < n; i++) {
//         cin >> a[i][0];
//         a[i][1] = a[i][0];
//     }
//     vector<int> ans(n, 0);
//     for (int i = n - 2; i >= 0; i--) {
//         int index = 0, tmp = INT_MAX/2, miner, maxer;
//         for (int j = 0; j < a.size() - 1; j++){
//             miner = min(a[j][0], a[j + 1][0]);
//             maxer = max(a[j][1], a[j + 1][1]);
//             int cha = maxer - miner - (a[j][1] - a[j][0]) - (a[j + 1][1] - a[j + 1][0]);
//             if (cha < tmp) {
//                 index = j;
//                 tmp = cha;
//             }
//         }
//         ans[i] = ans[i + 1] + tmp;
//         a[index][0] = min(a[index][0], a[index + 1][0]);
//         a[index][1] = max(a[index][1], a[index + 1][1]);
//         a.erase(a.begin() + index + 1);
//     }   

//     for (int i = 0; i < n; i++) {
//         cout << ans[i] << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // 计算一段区间的最大最小差
// int maxMinDiff(const vector<int>& a, int start, int end) {
//     int maxVal = a[start], minVal = a[start];
//     for (int i = start; i <= end; ++i) {
//         maxVal = max(maxVal, a[i]);
//         minVal = min(minVal, a[i]);
//     }
//     return maxVal - minVal;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX/2));
//     vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));

//     // 计算cost[i][j]表示从第i个到第j个的最大最小差
//     for (int i = 1; i <= n; ++i) {
//         for (int j = i; j <= n; ++j) {
//             cost[i][j] = maxMinDiff(a, i - 1, j - 1);
//         }
//     }

//     // 初始化dp数组
//     dp[0][0] = 0;

//     // 计算dp[i][j]表示将前i个分为j段的最小和
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= i; ++j) {
//             for (int k = 0; k < i; ++k) {
//                 dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost[k + 1][i]);
//             }
//         }
//     }

//     // 输出结果
//     for (int k = 1; k <= n; ++k) {
//         cout << dp[n][k] << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; ++i) {
cin >> a[i];
}

// 预处理前缀最小值和前缀最大值
vector<int> prefixMin(n), prefixMax(n);
prefixMin[0] = a[0];
prefixMax[0] = a[0];
for (int i = 1; i < n; ++i) {
prefixMin[i] = min(prefixMin[i - 1], a[i]);
prefixMax[i] = max(prefixMax[i - 1], a[i]);
}

vector<vector<int>> dp(n + 1, vector<int>(n + 1, 100000));

// 初始化dp数组
dp[0][0] = 0;

// 计算dp[i][j]表示将前i个分为j段的最小和
for (int i = 1; i <= n; ++i) {
for (int j = 1; j <= i; ++j) {
for (int k = 0; k < i; ++k) {
int maxVal = max(prefixMax[i - 1], prefixMax[k]);
int minVal = min(prefixMin[i - 1], prefixMin[k]);
dp[i][j] = min(dp[i][j], dp[k][j - 1] + (maxVal - minVal));
}
}
}

// 输出结果
for (int k = 1; k <= n; ++k) {
cout << dp[n][k] << endl;
}

return 0;
}