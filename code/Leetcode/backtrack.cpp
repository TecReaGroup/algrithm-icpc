# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // 17. 电话号码的字母组合
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) {
            return {};
        }
        vector<string> ans;
        string a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;

        function<void(int)> backtrack = [&] (int index) -> void {
            if (index == n) {
                ans.push_back(path);
                return;
            }
            for (char c : a[digits[index] - '0']) {
                path.push_back(c);
                backtrack(index + 1);
                path.pop_back();
            }
        };
        backtrack(0);

        return ans;
    }

    // 78. 子集
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> backtrack = [&] (int index) -> void {
            if (index == nums.size()) {
                ans.push_back(path);
                return;
            }
            path.push_back(nums[index]);
            backtrack(index + 1);
            path.pop_back();
            backtrack(index + 1);
        };
        backtrack(0);

        return ans;
    }


    // 131. 分割回文串
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        function<void(int)> backtrack = [&] (int index) -> void {
            if (index == s.size()) {
                ans.push_back(path);
                return;
            }

            for (int i = index; i < s.size(); i++) {
                string path_str = s.substr(index, i - index + 1);  // substr(start, length) not substr(start, end)
                if (isPalindrome(path_str)) {
                    path.push_back(path_str);
                    backtrack(i + 1);
                    path.pop_back();
                }
            }
            backtrack(index + 1);
        };
        backtrack(0);

        return ans;
    }

    
    // 77. 组合
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int)> backtrack = [&] (int index) -> void {
            int d = k - path.size();
            if (!d) {
                ans.push_back(path);
                return;
            }

            for (int i = index; i > d - 1; i--) {
                path.push_back(i);
                backtrack(i - 1);
                path.pop_back();
            }
        };
        backtrack(n);

        return ans;
    }


    // 216. 组合总和 III
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> backtrack = [&] (int index, int val) -> void {
            int d = k - path.size();
            if (val < 0 || val > (index + index - d + 1) * d / 2) {
                return;
            }
            if (!d) {
                ans.push_back(path);
                return;
            }

            for (int i = index; i > d - 1; i--) {
                path.push_back(i);
                backtrack(i - 1, val - i);
                path.pop_back();
            }
        };
        backtrack(9, n);

        return ans;
    }

    // 22. 括号生成
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(n*2, ' ');

        function<void(int, int)> backtrack = [&] (int index, int n_left) -> void {
            if (index == 2*n){
                ans.push_back(path);
                return;
            }
            if (n_left < n) {
                path[index] = '(';
                backtrack(index + 1, n_left + 1);
            }
            if (index - n_left < n_left){
                path[index] = ')';
                backtrack(index + 1, n_left);
            }
        };
        backtrack(0, 0);

        return ans;
    }

    // 46. 全排列 https://leetcode.cn/problems/permutations/solution/hui-su-bu-hui-xie-tao-lu-zai-ci-jing-que-6hrh/
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        
        function<void()> backtrack = [&] () -> void {
            if (path.size() == nums.size()) {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                backtrack();
                path.pop_back();
                used[i] = false;
            }
        };
        backtrack();

        return ans;
    }
    
    // 51. N 皇后 https://leetcode.cn/problems/n-queens/solution/hui-su-tao-lu-miao-sha-nhuang-hou-shi-pi-mljv/
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path;
        vector<bool> col(n, false), dg(2*n, false), udg(2*n, false);

        function<void(int)> backtrack = [&] (int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            for (int j = 0; j < n; j++){
                if (!col[j] && !dg[i+j] && !udg[i-j+n]){
                    string s(n, '.');
                    s[j] = 'Q';
                    path.push_back(s);
                    col[j] = dg[i+j] = udg[i-j+n] = true;
                    backtrack(i + 1);
                    path.pop_back();
                    col[j] = dg[i+j] = udg[i-j+n] = false;
                }
            } 
        };
        backtrack(0);

        return ans;
    }
    
    
    // 52. N 皇后 II https://leetcode.cn/problems/n-queens-ii/solution/hui-su-miao-sha-nhuang-hou-yi-ge-shi-pin-l41l
    // 46. 全排列 https://leetcode.cn/problems/permutations/solution/hui-su-bu-hui-xie-tao-lu-zai-ci-jing-que-6hrh/
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        
        function<void()> backtrack = [&] () -> void {
            if (path.size() == nums.size()) {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                backtrack();
                path.pop_back();
                used[i] = false;
            }
        };
        backtrack();

        return ans;
    }
    
    // 51. N 皇后 https://leetcode.cn/problems/n-queens/solution/hui-su-tao-lu-miao-sha-nhuang-hou-shi-pi-mljv/
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path;
        vector<bool> col(n, false), dg(2*n, false), udg(2*n, false);

        function<void(int)> backtrack = [&] (int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            for (int j = 0; j < n; j++){
                if (!col[j] && !dg[i+j] && !udg[i-j+n]){
                    string s(n, '.');
                    s[j] = 'Q';
                    path.push_back(s);
                    col[j] = dg[i+j] = udg[i-j+n] = true;
                    backtrack(i + 1);
                    path.pop_back();
                    col[j] = dg[i+j] = udg[i-j+n] = false;
                }
            } 
        };
        backtrack(0);

        return ans.size();
    }

};


int main(){




    return 0;
}