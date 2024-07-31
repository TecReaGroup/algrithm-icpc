# include <bits/stdc++.h>
using namespace std;


class Solution {
 public:
    // 198. House Robber
    int rob(vector<int>& nums) {
        vector<int> a(nums.size() + 1, -1);
        function<int(int)> dp = [&](int n) {
            if (n < 0) return 0;
            if (a[n] != -1) return a[n];
            return a[n] = max(dp(n - 1), dp(n - 2) + nums[n]);
        };
        return dp(nums.size() - 1);
    }


    // 1143. Longest Common Subsequence
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size() - 1, j = text2.size() - 1;
        vector<vector<int>> a(i + 1, vector<int>(j + 1, -1));
        function<int(int, int)> dp = [&] (int i, int j) -> int {
            if (i == -1 || j == -1) return 0;
            if (a[i][j] != -1) return a[i][j];
            if (text1[i] == text2[j]) return dp(i - 1, j - 1) + 1;
            return a[i][j] = max(dp(i - 1, j), dp(i, j - 1));
        };

        return dp(i, j);
    }


    // 72. Edit Distance
    int minDistance(string word1, string word2) {
        int i = word1.size() - 1, j = word2.size() - 1;
        vector<vector<int>> a(i + 1, vector<int>(j + 1, -1));
        function<int(int, int)> dp = [&] (int i, int j) -> int {
            if (i == -1 || j == -1) return j + i + 2;
            if (a[i][j] != -1) return a[i][j];
            if (word1[i] == word2[j]) return dp(i - 1, j - 1);
            return a[i][j] = min({dp(i - 1, j), dp(i, j - 1), dp(i - 1, j - 1)}) + 1;
        };

        return dp(i, j);
    }


    // 300. Longest Increasing Subsequence
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 0) return 0;

        int n = nums.size(), ans = 1;
        vector<int> a(n, -1);
        function<int(int)> dp = [&](int n) -> int {
            int tmp = 1;
            if (n == 0) return 1;
            if (a[n] != -1) return a[n];
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[n]) tmp = max(tmp, dp(i) + 1);
            }

            return a[n] = tmp;
        };
        
        for (int i = 0; i < n; i++) ans = max(ans, dp(i));
        return ans;
    }


    // 583. 两个字符串的删除操作 https://leetcode.cn/problems/delete-operation-for-two-strings/
    int minDistance(string word1, string word2) {
        int i = word1.size() - 1, j = word2.size() - 1;
        vector<vector<int>> a(i + 1, vector<int>(j + 1, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i == -1 || j == -1) return j + i + 2;
            if (a[i][j] != -1) return a[i][j];
            return a[i][j] = word1[i] == word2[j] ? dp(i - 1, j - 1) : min(dp(i - 1, j), dp(i, j - 1)) + 1;
        };
        
        return dp(i, j);
    }
    
    // 712. 两个字符串的最小ASCII删除和 https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
    int minimumDeleteSum(string s1, string s2) {
        int i = s1.size(), j = s2.size();
        vector<vector<int>> a(i + 1, vector<int>(j + 1, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            int index1 = i - 1, index2 = j - 1;
            if (a[i][j] != -1) return a[i][j];
            if (i == 0) {
                int sum = 0;
                for (int k = 0; k <= index2; k++) sum += s2[k];
                a[i][j] = sum;
                return sum;
            }
            if (j == 0) {
                int sum = 0;
                for (int k = 0; k <= index1; k++) sum += s1[k];
                a[i][j] = sum;
                return sum;
            }
            return a[i][j] = s1[index1] == s2[index2] ? dp(i - 1, j - 1) : min(dp(i - 1, j) + (int)s1[index1], dp(i, j - 1) + (int)s2[index2]);
        };
        
        return dp(i, j);
    }

    // 97. 交错字符串 https://leetcode.cn/problems/interleaving-string/
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        if (s1.size() == 0) return s2 == s3;
        if (s2.size() == 0) return s1 == s3;

        int i = 0, j = 0, k = 0;
        vector<vector<int>> a(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        function<bool(int, int, int)> dp = [&](int i, int j, int k) -> bool {
            if (a[i][j] != -1) return a[i][j];
            if (k == s3.size()) return a[i][j] = true;
            if (s1[i] != s3[k] && s2[j] != s3[k]) return a[i][j] = false;

            if (s1[i] == s3[k] && s2[j] == s3[k]) return a[i][j] = dp(i + 1, j, k + 1) || dp(i, j + 1, k + 1);
            if (s1[i] == s3[k]) return a[i][j] = dp(i + 1, j, k + 1);
            return a[i][j] = dp(i, j + 1, k + 1);
        };

        return dp(i, j, k);
    }

    // 1458. 两个子序列的最大点积 https://leetcode.cn/problems/max-dot-product-of-two-subsequences/
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size(), j = nums2.size();
        vector<vector<int>> a(i, vector<int>(j, INT_MIN));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i == -1 || j == -1) return INT_MIN;
            if (a[i][j] != INT_MIN) return a[i][j];
            long long tmp = nums1[i] * nums2[j];
            return a[i][j] = max({tmp, tmp + dp(i - 1, j - 1), (long long)dp(i - 1, j), (long long)dp(i, j - 1)});
        };
        
        return dp(i - 1, j - 1);
    }

    // 1092. 最短公共超序列 https://leetcode.cn/problems/shortest-common-supersequence/
    string shortestCommonSupersequence(string str1, string str2) {
        vector<string> ans;
        int i = 0, j = 0;

        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i == str1.size() && j == str2.size()) return 0;
            if (i == str1.size()) {
                
            }
            if (j == str2.size()) {
                return str1.size() - i;
            }
            if (str1[i] == str2[j]) {
                return 1 + dp(i + 1, j + 1);
            }
            return 1 + min(dp(i + 1, j), dp(i, j + 1));
        };


        return ;
    }
};

class Solution {
public:
    string shortestCommonSupersequence(string &s, string &t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        // dfs(i,j) 返回 s 的前 i 个字母和 t 的前 j 个字母的最短公共超序列的长度
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0) return j + 1; // s 是空串，返回剩余的 t 的长度
            if (j < 0) return i + 1; // t 是空串，返回剩余的 s 的长度
            int &res = memo[i][j];
            if (res != -1) return res; // 避免重复计算 dfs 的结果
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return res = dfs(i - 1, j - 1) + 1;
            return res = min(dfs(i - 1, j), dfs(i, j - 1)) + 1;
        };

        // make_ans(i,j) 返回 s 的前 i 个字母和 t 的前 j 个字母的最短公共超序列
        // 看上去和 dfs 没啥区别，但是末尾的递归是 if-else
        // make_ans(i-1,j) 和 make_ans(i,j-1) 不会都调用
        // 所以 make_ans 的递归树仅仅是一条链
        function<string(int, int)> make_ans = [&](int i, int j) -> string {
            if (i < 0) return t.substr(0, j + 1); // s 是空串，返回剩余的 t
            if (j < 0) return s.substr(0, i + 1); // t 是空串，返回剩余的 s
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return make_ans(i - 1, j - 1) + s[i];
            // 如果下面 if 成立，说明上面 dfs 中的 min 取的是 dfs(i - 1, j)
            // 说明 dfs(i - 1, j) 对应的公共超序列更短
            // 那么就在 make_ans(i - 1, j) 的结果后面加上 s[i]
            // 否则说明 dfs(i, j - 1) 对应的公共超序列更短
            // 那么就在 make_ans(i, j - 1) 的结果后面加上 t[j]
            if (dfs(i, j) == dfs(i - 1, j) + 1)
                return make_ans(i - 1, j) + s[i];
            return make_ans(i, j - 1) + t[j];
        };

        return make_ans(n - 1, m - 1);
    }
};

// 能通过的测试数据更多，但仍然超时（超内存），还需要进一步优化
class Solution {
public:
    string shortestCommonSupersequence(string &s, string &t) {
        int n = s.length(), m = t.length();
        vector<vector<string>> memo(n, vector<string>(m));
        // dfs(i,j) 返回 s 的前 i 个字母和 t 的前 j 个字母的最短公共超序列
        function<string(int, int)> dfs = [&](int i, int j) -> string {
            if (i < 0) return t.substr(0, j + 1); // s 是空串，返回剩余的 t
            if (j < 0) return s.substr(0, i + 1); // t 是空串，返回剩余的 s
            string &res = memo[i][j];
            if (!res.empty()) return res; // 避免重复计算 dfs 的结果
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return res = dfs(i - 1, j - 1) + s[i];
            auto ans1 = dfs(i - 1, j);
            auto ans2 = dfs(i, j - 1);
            if (ans1.length() < ans2.length()) // 取 ans1 和 ans2 中更短的组成答案
                return res = ans1 + s[i];
            return res = ans2 + t[j];
        };
        return dfs(n - 1, m - 1);
    }
};


int main() {
    return 0;
}