#include <bits/stdc++.h>
using namespace std;

long long kuaisumi(long long a, long long b, long long m) {
    long long ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    long long a = 2, b, m = 998244353;
    for (int i = 0; i < n; i++) {
        cin >> b;
        cout << kuaisumi(a, b, m) << endl;
    }

    return 0;
}