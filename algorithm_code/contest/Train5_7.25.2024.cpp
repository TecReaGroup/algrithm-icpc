# include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


// horse drink water
// double water(double x1, double y1, double x2, double y2) {
//     double ans = sqrt((x1 + x2) * (x1 + x2) + (y1 - y2) * (y1 - y2));
//     ans = min(ans, sqrt((x1 - x2) * (x1 - x2) + (y1 + y2) * (y1 + y2)));
//     return ans;
// }


// int main() {
//     int n, m;
//     cin >> n >> m;
//     map<pair<int, int>, bool> a;
//     for (int i = 0; i < m; i++) {
//         int x, y;
//         cin >> x >> y;
//         if (x > y) {
//             swap(x, y);
//         }
//         a[make_pair(x, y)] = true;
//     }
//     long long ans = n;
//     int l = 1, r = 1;

//     for (; r <= n; r++) {
//         if (r == l) {
//             continue;
//         }
//         int i = r - 1;
//         for (; i >= l; i--) {
//             if (a[make_pair(i, r)]) {
//                 ans++;
//             }
//             else break;
//         }
//         l = i + 1;
//     }

//     cout << ans << endl;
//     return 0;
// }


// deceleration
int main() {
    int t;
    cin >> t;
    vector<int> decelaration;
    vector<int> cost_time;
    for (int i = 0; i < t; i++) {
        int o, x;
        cin >> o >> x;
        if (o == 1) {
            // updata decelaration
            if (decelaration.size() == 0){
                decelaration.insert(decelaration.begin(), x);
                cost_time.insert(cost_time.begin(), x);
                continue;
            }

            int j = 0;
            for (; j < decelaration.size(); j++) {
                if (x <= decelaration[j]) {
                    decelaration.insert(decelaration.begin() + j, x);
                    break;
                }
                else if (x > decelaration[j] && j == decelaration.size() - 1) {
                    decelaration.push_back(x);
                    j++;
                    break;
                }
            }

            // updata cost_time
            if (j == 0) {
                cost_time.insert(cost_time.begin(), x);
                cost_time[j + 1] = decelaration[j + 1] - decelaration[j];
            }
            else if (j == decelaration.size() - 1) {
                cost_time.push_back(decelaration[j] - decelaration[j - 1]);

            }
            else {
                cost_time.insert(cost_time.begin() + j, decelaration[j] - decelaration[j - 1]);
                cost_time[j + 1] = decelaration[j + 1] - decelaration[j];
            }
        }
        else {
            long long tmp_time = x;
            long long ans = 0;
            for (int j = 0; j < decelaration.size(); j++) {
                if (tmp_time >= cost_time[j]) {
                    tmp_time = (tmp_time - cost_time[j])*2%mod;
                    ans = (ans + cost_time[j]) % mod;

                    // redecelaration
                    while (j + 1 < decelaration.size() && cost_time[j + 1] == 0) {
                        j++;
                        tmp_time = tmp_time*2%mod;
                    }
                }
                else {
                    break;
                }
            }
            ans = (ans + tmp_time) % mod;
            cout << ans << endl;
        }
    }

    return 0;
}