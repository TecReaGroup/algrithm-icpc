#include <bits/stdc++.h>
using namespace std;


// A Bridging the Gap 2
int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int people_send = r - l;

    do {
        if (a.size() >= l && a.size() <= r) {
            cout << "Yes" << endl;
            return 0;
        }
        if (a[l - 1] <= 3) {
            cout << "No" << endl;
            return 0;
        }
        for (int i = 0; i < people_send; ++i) {
            a.pop_back();
        }
        for (int i = 0; i < l; ++i) {
            a[i]--;
        }
        sort(a.begin(), a.end(), greater<int>());
    } while (true);

    cout << "No" << endl;
    return 0;
}