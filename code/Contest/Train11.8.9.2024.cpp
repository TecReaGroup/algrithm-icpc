#include <bits/stdc++.h>
using namespace std;

/*
草莓 2*n*x, 蛋糕 2*m*y
要求 2*n*x % 2*m*y == 0
求 n_min, 然后再是 m_min
*/

long long gcd(long long a, long long b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        long long lcm_xy = lcm(x, y);
        long long j;
        if (x % y == 0) j = x/y;
        else j = lcm(lcm_xy/x, 2)*x / y;
        cout << y << " " << j << endl;
    }

    return 0;
}