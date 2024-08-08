# include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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
    // 利用dp的结果, 从而有方向性的回溯构造答案
    string shortestCommonSupersequence(string str1, string str2) {
        int i = str1.size(), j = str2.size();
        vector<vector<int>> a(i, vector<int>(j, -1));

        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i == -1 || j == -1) return i + j + 2;
            int &res = a[i][j];
            if (res != -1) return res;
            if (str1[i] == str2[j]) return res = dp(i - 1, j - 1) + 1;
            return res = min(dp(i - 1, j), dp(i, j - 1)) + 1;
        };

        function<string(int, int)> make_ans = [&](int i, int j) -> string {
            if (i == -1) return str2.substr(0, j + 1);
            if (j == -1) return str1.substr(0, i + 1);
            if (str1[i] == str2[j]) return make_ans(i - 1, j - 1) + str1[i];
            if (dp(i, j) == dp(i - 1, j) + 1) return make_ans(i - 1, j) + str1[i];
            return make_ans(i, j - 1) + str2[j];
        };

        return make_ans(i - 1, j - 1);
    }

    // 122. 买卖股票的最佳时机 II
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));

        function<int(int, int)> dp = [&](int i, int status) -> int {
            if (i == -1 && status == 0) return 0;
            else if (i == -1 && status == 1) return INT_MIN;
            int &res = memo[i][status];
            if (res != -1) return memo[i][status];

            if (status == 1) {
                int a = dp(i - 1, 0);
                int b = dp(i - 1, 1);
                return res = max(a - prices[i], b);
            }
            else {
                int a = dp(i - 1, 1);
                int b = dp(i - 1, 0);
                return res = max(a + prices[i], b);
            }
        };

        return dp(n - 1, 0);
    }

    // 309. 最佳买卖股票时机含冷冻期
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));

        function<int(int, int)> dp = [&](int i, int status) -> int {
            if (i == -1 && status == 0) return 0;
            else if (i == -1 && status == 1) return INT_MIN;
            int &res = memo[i][status];
            if (res != -1) return memo[i][status];

            if (status == 1) {
                int a = dp(max(i - 2, -1), 0);
                int b = dp(i - 1, 1);
                return res = max(a - prices[i], b);
            }
            else {
                int a = dp(i - 1, 1);
                int b = dp(i - 1, 0);
                return res = max(a + prices[i], b);
            }
        };

        return dp(n - 1, 0);
    }

    // 188. 买卖股票的最佳时机 IV
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        function<int(int, int, int)> dp = [&](int i, int status, int times) -> int {
            if (i == -1 ) return status ? INT_MIN/2 : 0;
            if (times == 0) return 0;
            int &res = memo[i][status][times];
            if (res != -1) return res;

            if (status == 1) {
                int a = dp(i - 1, 0, times - 1) - prices[i];
                int b = dp(i - 1, 1, times);
                return res = max(a, b);
            }
            else {
                int a = dp(i - 1, 1, times) + prices[i];
                int b = dp(i - 1, 0, times);
                return res = max(a , b);
            }
        };

        return dp(n - 1, 0 , k);
    }

    // 516. 最长回文子序列
    int longestPalindromeSubseq(string s) {
        int left = 0, right = s.size() - 1;
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        function<int(int, int)> dp = [&] (int l, int r) -> int {
            if (l > r) return 0;
            if (l == r) return 1;
            int &res = memo[l][r];
            if (res != -1) return res;
            if (s[l] == s[r]) return res = dp(l + 1, r - 1) + 2;
            return res = max(dp(l + 1, r), dp(l, r - 1));
        };
        return dp(left, right);
    }


    // 1039. 多边形三角剖分的最低得分
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int)> dp = [&] (int i, int j) -> int {
            if (j - i < 2) return 0;
            int &res = memo[i][j];
            if (res != -1) return res;
            int tmp = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                tmp = min(tmp, dp(i, k) + dp(k, j) + values[i] * values[j] * values[k]);
            }
            return res = tmp;
        };

        return dp(0, n - 1);
    }

    // 543. 二叉树的直径
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dp = [&] (TreeNode *root) -> int {
            if (root == nullptr) return -1;
            int left = dp(root->left) + 1;
            int right = dp(root->right) + 1;
            ans = max(ans, left + right);
            return max(left, right);
        };
        dp(root);
        return ans;
    }

    // 124. 二叉树中的最大路径和
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN/2;
        function<int(TreeNode*)> dp = [&] (TreeNode *root) -> int {
            if (root == nullptr) return 0;
            int left = dp(root->left);
            int right = dp(root->right);
            ans = max(ans, left + right + root->val);
            return max({left + root->val, right + root->val, 0});
        };
        dp(root);
        return ans;
    }

    // 2246. 相邻字符不同的最长路径
    int longestPath(vector<int> &parent, string &s) {
        int ans = 0;
        vector<vector<int>> g(parent.size());
        for (int i = 1; i < parent.size(); i++) {
            g[parent[i]].push_back(i);
        }
        function<int(int)> dp = [&] (int i) -> int {
            int maxlen = 0;
            for (int v : g[i]) {
                int len = dp(v) + 1;
                if (s[i] == s[v]) continue;
                ans = max(ans, maxlen + len);
                maxlen = max(maxlen, len);
            }
            return maxlen;
        };
        dp(0);
        return ans + 1;
    }

    // 337. 打家劫舍 III
    int rob(TreeNode* root) {
        map<TreeNode*, int> memo;
        function<int(TreeNode*, int)> dp = [&] (TreeNode *root, int status) -> int {
            if (root == nullptr) return 0;
            int ans = 0;
            if (status == 1) {
                if (memo.find(root) != memo.end()) ans = memo[root];
                else {
                    ans = dp(root->left, 0) + dp(root->right, 0) + root->val;
                    memo[root] = ans;
                }
            }
            ans = max(ans, dp(root->left, 1) + dp(root->right, 1));

            return ans;
        };

        return dp(root, 1);
    }

    // 968. 监控二叉树
    int minCameraCover(TreeNode* root) {
        map<TreeNode*, int> memo;
        function<int(TreeNode*, int)> dp = [&] (TreeNode *root, int status) -> int {
            if (root == nullptr) return 0;
            int ans = INT_MAX/2;
            if (status == 1) {  // 父节点已经监控
                return min(dp(root->left, 0) + dp(root->right, 0), dp(root->left, 1) + dp(root->right, 1) + 1);
            }
            if (status == 2) return dp(root->left, 1) + dp(root->right, 1) + 1;  // 当前节点必须监控
            if (memo.find(root) != memo.end()) return memo[root];  // 记忆化搜索
            else {
                ans = dp(root->left, 1) + dp(root->right, 1) + 1;  // 当前节点监控
                if (root->left != nullptr) ans = min(ans, dp(root->left, 2) + dp(root->right, 0));  // 左节点监控
                if (root->right != nullptr) ans = min(ans, dp(root->left, 0) + dp(root->right, 2));  // 右节点监控
                if (root->left != nullptr && root->right != nullptr) ans = min(ans, dp(root->left, 2) + dp(root->right, 2));  // 左右节点监控
                return memo[root] = ans;
            }
        };
        return dp(root, 0);
    }

    // 
};



int main() {
    return 0;
}