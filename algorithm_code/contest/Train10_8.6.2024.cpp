#include <bits/stdc++.h>
using namespace std;

long long modul = 1e9 + 7;

int find_inx(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int ans = -1;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[j]) {
            j++;
            if (j == m) {
                ans = i;
                break;
            }
        }
    }
    return ans;
}


int sub_num(string s) {
    int n = s.size();
    vector<long long> dp(n + 1, 0); // dp[i] 表示前 i 个字符的不重复子序列数量
    dp[0] = 1; // 空子序列

    unordered_map<char, int> lastOccurrence; // 记录每个字符上一次出现的位置

    for (int i = 1; i <= n; ++i) {
        char currentChar = s[i - 1];
        dp[i] = (2 * dp[i - 1]) % modul;

        if (lastOccurrence.find(currentChar) != lastOccurrence.end()) {
            int lastPos = lastOccurrence[currentChar];
            dp[i] = (dp[i] - dp[lastPos - 1] + modul) % modul; // 防止出现负数
        }

        lastOccurrence[currentChar] = i; // 更新当前字符的最后出现位置
    }

    return (dp[n] - 1 + modul) % modul; // 减去空子序列
}


long long huiwen(const string& s) {
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (n < m) {
        cout << 0 << endl;
        return 0;
    }

    string s_rev = s.substr(0, n);
    reverse(s_rev.begin(), s_rev.end());
    int l_start = s.find(t[0]);
    int r_start = n - s_rev.find(t[0]) - 1;
    int l = find_inx(s, t);
    int r = n - find_inx(s_rev, t) - 1;

    long long ans = 1;
    if (l < r) {
        string sub_str = s.substr(l + 1, r - l - 1);
        ans += sub_num(sub_str);
    }

    if (l > r_start || r < l_start) {
        cout << 0 << endl;
        return 0;
    }

    if (l != r && l <= r_start && r >= l_start) {
        int chongdieshu = 0;
        if (l > r) {
            for (int i = r; i <= l; i++) {
                if (s[i] == s_rev[i]) {
                    chongdieshu++;
                }
            }
        }
        for (int i = m - 1 - chongdieshu; i >= 0; i--) {
            string str_huiwen = t.substr(i, m - i);
            ans += huiwen(str_huiwen);
        }
    }
    ans %= modul;

    cout << ans << endl;
    return 0;
}