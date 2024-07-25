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
        string path_str;
        function<void(int)> backtrack = [&] (int index) -> void {
            if (index == s.size()) {
                if (path_str.empty()) ans.push_back(path);
                return;
            }
            path_str.push_back(s[index]);
            if (isPalindrome(path_str)) {
                path.push_back(path_str);
                backtrack(index + 1);
                path.pop_back();
            }
            backtrack(index + 1);
        };
        backtrack(0);

        return ans;
    }
        

};


int main(){




    return 0;
}