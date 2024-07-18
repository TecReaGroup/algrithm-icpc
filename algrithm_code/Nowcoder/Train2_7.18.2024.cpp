// H. Instructions Substring
// error: 数据结构选取: 数组维护麻烦, 应该使用 map
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x_p, y_p;
    cin >> n >> x_p >> y_p;
    string s;
    getchar();
    getline(cin, s);
    int x = 0, y = 0;
    int ans = 0;
    
    if (x_p == 0 && y_p == 0) {
        ans = n * (n + 1) / 2;
        cout << ans << endl;
        return 0;
    }
    else if (abs(x_p) + abs(y_p) > n) {
        cout << ans << endl;
        return 0;
    }

    int x_min = 0, x_max = 0, y_min = 0, y_max = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') y++;
        else if (s[i] == 'S') y--;
        else if (s[i] == 'A') x--;
        else if (s[i] == 'D') x++;
        x_min = min(x_min, x);
        x_max = max(x_max, x);
        y_min = min(y_min, y);
        y_max = max(y_max, y);
    }
    vector<vector<bool>> a(abs(x_min) + abs(x_max) + 1, vector<bool>(abs(y_min) + abs(y_max) + 1, false));
    x = abs(x_min), y = abs(y_min);
    a[x][y] = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') y++;
        else if (s[i] == 'S') y--;
        else if (s[i] == 'A') x--;
        else if (s[i] == 'D') x++;
        a[x][y] = true;
    }

    x = abs(x_min), y = abs(y_min);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') y++;
        else if (s[i] == 'S') y--;
        else if (s[i] == 'A') x--;
        else if (s[i] == 'D') x++;

        if ((x_p + x >= 0 && x_p + x <= abs(x_min) + abs(x_max) && y_p + y >= 0 && y_p + y <= abs(y_min) + abs(y_max)) && !a[x_p + x][y_p + y]) {
            continue;
        }
        else {
            int x_j = 0, y_j = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'W') y_j++;
                else if (s[j] == 'S') y_j--;
                else if (s[j] == 'A') x_j--;
                else if (s[j] == 'D') x_j++;
                if (x_j == x_p && y_j == y_p) {
                    ans += n - j;
                    break;
                }
            }
        }

    }

    cout << ans << endl;
    return 0;
}

// correct solution
#include<bits/stdc++.h>
#define x first
#define y second
#define endl "\n"
using namespace std;
 
using pii = pair<int,int>;  // *
using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
 
const int N = 200010,M = 200010,mod = 1e9+7,INF = 0X3f3f3f3f;
 
mt19937_64 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());
 
int n,x,y;
map<pii,vector<int>> mp;  // *
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> x >> y;
    string s;
    cin >> s;
    s = " " + s;
 
    if (x == 0 && y == 0) {
        cout << (i64)n*(n+1)/2;
        return 0;
    }
 
    int nx = 0,ny = 0;
 
    for (int i = 1;i<=n;i++) {
        if (s[i] == 'A') nx--;
        else if (s[i] == 'D') nx++;
        else if (s[i] == 'W') ny++;
        else if (s[i] == 'S') ny--;
        mp[{nx,ny}].push_back(i);  // *
        // cout << nx << ' ' << ny << endl;
    }
    // cout << endl;
    // for (auto T : mp) {
    //  cout << T.x.x << ' ' << T.x.y << endl;
    // }
    // cout << endl;
    i64 ans = 0;
    for (int i = 1;i<=n;i++) {
        // cout << x << ' ' << y << endl;
        if (mp.count({x,y}) == 0) {
            // cout << "here\n";
            if (s[i] == 'A') x--;
            else if (s[i] == 'D') x++;
            else if (s[i] == 'W') y++;
            else if (s[i] == 'S') y--;
            continue;
        }
 
        auto &it = mp[{x,y}];
        int v = 0;
        auto iter = lower_bound(it.begin(),it.end(),i);  // *
        if (iter != it.end()) {
            v = *iter;
            ans += n - v + 1;
        } 
        if (s[i] == 'A') x--;
        else if (s[i] == 'D') x++;
        else if (s[i] == 'W') y++;
        else if (s[i] == 'S') y--;
    }
 
    cout << ans << endl;
 
    return 0;
}
