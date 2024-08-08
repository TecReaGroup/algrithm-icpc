#include <iostream>
#include <vector>
using namespace std;

// 快速幂函数
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

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

int main() {
    long long n, m, mod;
    cin >> n >> m >> mod;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));

    // 计算公式的和
    long long result = 0;
    combination(a, mod, n);

    for (int k = 0; k < n; ++k) {
        long long Cnk = a[n][k];
        long long term = Cnk * power(power(2, m - 1, mod), k, mod) % mod * power(power(2, n - k, mod) - 1, m - 1, mod) % mod;
        result = (result + term) % mod;
    }
    cout << result << endl;
    return 0;
}