# include <bits/stdc++.h>

using namespace std;




int main(){
    int times = 0;
    int n;
    cin >> n;
    vector<vector<int>> bound(4, vector<int>(5, 0));
    vector<vector<int>> w;
    vector<vector<int>> s;
    vector<vector<int>> a;
    vector<vector<int>> d;
    map<char, int> m = {{'W', 0}, {'S', 1}, {'A', 2}, {'D', 3}};
    for (int i = 0; i < n; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        int index = m[c];
        if (index == 0) w.push_back({x, y});
        else if (index == 1) s.push_back({x, y});
        else if (index == 2) a.push_back({x, y});
        else d.push_back({x, y});

        if (bound[index][4] == 0) {
            bound[index][4] = 1;
            bound[index][0] = x;
            bound[index][1] = x;
            bound[index][2] = y;
            bound[index][3] = y;
        } 
        else {
            bound[index][0] = min(bound[index][0], x);
            bound[index][1] = max(bound[index][1], x);
            bound[index][2] = min(bound[index][2], y);
            bound[index][3] = max(bound[index][3], y);
        }

    }

    vector<vector<int>> t(4, vector<int>(2, 0));
    t[0][0] = t[0][0] = max(max(0, bound[0][3] - bound[1][3]), max(bound[0][3] - bound[2][3], bound[0][3] - bound[3][3]));
    t[0][1] = ;


    return 0;
}