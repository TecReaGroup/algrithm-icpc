#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // 2652. Sum Multiples
    int sumOfMultiples(int n) {
        function<int(int, int)> sum = [&](int m, int k) -> int {
            return (1 + k)*k/2*m;
        };

        int ans = sum(3, n/3) + sum(5, n/5) + sum(7, n/7) - sum(15, n/15) - sum(21, n/21) - sum(35, n/35) + sum(105, n/105);
        return ans;
    }

    // 878. Nth Magical Number
    int nthMagicalNumber(int n, int a, int b) {
        int ans = 0;
        long long mudo = 1e9 + 7;
        long long num_lcm = lcm(a, b);

        long long l = 0, r = (long long) min(a, b) * n;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long cnt = mid/a + mid/b - mid/num_lcm;
            if (cnt < n) l = mid + 1;
            else r = mid;
        }

        ans = l % mudo;
        return ans;
    }

    // 1201. Ugly Number III
    int nthUglyNumber(int n, int a, int b, int c) {
        int ans = 0;
        long long l = 0, r = 2e9 + 1;
        while (l < r) {
            long long mid = l + (r - l)/2;
            long long cnt = mid/a + mid/b + mid/c - mid/lcm(a, b) - mid/lcm(a, c) - mid/lcm(b, c) + mid/lcm(lcm(a, b), c);
            if (cnt < n) l = mid + 1;
            else r = mid;
        }

        ans = l;
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.nthUglyNumber(1000000000, 2, 217983653, 336916467) << endl;

    return 0;
}