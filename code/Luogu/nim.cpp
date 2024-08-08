#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, ans;
        cin >> n;
        cin >> ans;
        for (int j = 1; j < n; j++) {
            int tmp;
            cin >> tmp;
            ans ^= tmp;
        }

        cout << (ans != 0 ? "Yes" : "No") << endl;
    }

    return 0;
}