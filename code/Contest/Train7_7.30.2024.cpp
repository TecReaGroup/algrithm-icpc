# include <bits/stdc++.h>
using namespace std;


// maximum probability
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int flag = 1;
        while (flag) {
            int l = n - 1, r = n - 1;
            flag = 0;
            while (r > 0) {
                int sum = 0, level = 0;
                sum += nums[r];
                level = sum/(r - l + 1);
                while (l > 0 && nums[l - 1] <= level) {
                    l--;
                    sum += nums[l];
                    level = sum/(r - l + 1);
                }
                int yu = sum - level * (r - l + 1);
                for (int i = l; i <= r; i++) {
                    int tmp = nums[i];
                    nums[i] = level;
                    if (i - l < yu) nums[i]++;
                    if (nums[i] != tmp) {
                        flag = 1;
                    }
                }
                l = r = l - 1;
            }
        }

        long long ans = nums[0];
        for (int i = 1; i < n; i++) {
            ans = ans * nums[i] % 998244353;
        }
        cout << ans << endl;
    }


}
