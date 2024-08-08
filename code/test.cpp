#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 998244353

using namespace std;

// Function to calculate power with modulo
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

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // dp[i] means the number of subsequences ending at position i
    vector<long long> dp(N, 0);
    vector<long long> count(N + 1, 0); // count[i] means the number of subsequences of length i

    long long result = 0;
    count[0] = 1; // empty subsequence

    for (int i = 0; i < N; ++i) {
        for (int j = N; j >= 1; --j) {
            count[j] = (count[j] + count[j-1]) % MOD;
        }
    }

    for (int i = 1; i <= N; ++i) {
        result = (result + power(i, 3, MOD) * count[i]) % MOD;
    }

    cout << result << endl;
    return 0;
}
