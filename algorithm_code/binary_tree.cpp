#include <bits/stdc++.h>
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
    // 104. 二叉树的最大深度
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // 112. 路径总和
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (targetSum - root->val == 0 && root->left == nullptr && root->right == nullptr) return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }

    // 100. 相同的树 https://leetcode.cn/problems/same-tree/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-empk/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    // 101. 对称二叉树 https://leetcode.cn/problems/symmetric-tree/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-6dq5/
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        function<bool(TreeNode*, TreeNode*)> isMirror = [&] (TreeNode* p, TreeNode* q) -> bool {
            if (p == nullptr && q == nullptr) return true;
            if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
            if (p->val != q->val) return false;

            return isMirror(p->left, q->right) && isMirror(p->right, q->left);
        };
        return isMirror(root->left, root->right);
    }
    
    // 110. 平衡二叉树 https://leetcode.cn/problems/balanced-binary-tree/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-c3wj/
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> height = [&] (TreeNode* root) -> int {
            if (root == nullptr) return 0;

            int left = height(root->left);
            if (left == -1) return -1;

            int right = height(root->right);
            if (right == -1) return -1;

            return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
        };
        return height(root) != -1;
    }
    
    // 199. 二叉树的右视图 https://leetcode.cn/problems/binary-tree-right-side-view/solution/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-r1nc/
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*, int)> dfs = [&] (TreeNode* root, int depth) -> void{
            if (root == nullptr) return ;
            if (depth == res.size()) res.push_back(root->val);
            dfs(root->right, depth + 1);
            dfs(root->left, depth + 1);
        };

        dfs(root, 0);
        return res;
    }

    // 98. 验证二叉搜索树
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, long long, long long)> presearch = [&] (TreeNode* root, long long lower, long long upper){
            if (root == nullptr) return true;
            if (root->val <= lower || root->val >= upper) return false;
            return presearch(root->left, lower, root->val) && presearch(root->right, root->val, upper);
        };

        long long pre = LLONG_MIN;
        function<bool(TreeNode*, long long, long long)> midsearch = [&] (TreeNode* root, long long lower, long long upper){
            if (root == nullptr) return true;
            if (!midsearch(root->left, lower, root->val)) return false;
            if (root->val <= pre) return false;
            pre = root->val;
            return midsearch(root->right, root->val, upper);
        };

        function<vector<long long>(TreeNode*)> postsearch = [&] (TreeNode* root) -> vector<long long>{
            vector<long long> ans = {LLONG_MAX, LLONG_MIN};
            if (root == nullptr) return ans;
            long long l_min = postsearch(root->left)[0], l_max = postsearch(root->left)[1];
            long long r_min = postsearch(root->right)[0], r_max = postsearch(root->right)[1];
            long long x = root->val;
            if (x <= l_max || x >= r_min) {
                ans[0] = LLONG_MIN;
                ans[1] = LLONG_MAX;
                return ans;
            }
            ans[0] = min(x, l_min);
            ans[1] = max(x, r_max);
            return ans;
        };

        return postsearch(root)[0] != LLONG_MAX;
    }

    // 236. 二叉树的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) return right;
        return left;
    }

    // 235. 二叉搜索树的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p, q);
        TreeNode *left, *right;
        if (root == nullptr || root == p || root == q  || (root->val > p->val && root->val < q->val)) return root;
        if (q->val < root->val ) return left = lowestCommonAncestor(root->left, p, q);
        return right = lowestCommonAncestor(root->right, p, q);
    }

    // 102. 二叉树的层序遍历 https://leetcode.cn/problems/binary-tree-level-order-traversal/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlpz/
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            for (int i = q.size(); i--;) {  // q.size is changing, so we need to store the size of q, not compare it in the loop
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.emplace_back(level);
        }

        return res;
    }

    // 103. 二叉树的锯齿形层序遍历 https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlv3/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            vector<int> level;
            for (int i = q.size(); i--;) {  // q.size is changing, so we need to store the size of q, not compare it in the loop
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (flag) res.push_back(level);
            else {
                reverse(level.begin(), level.end());
                res.push_back(level);
            }
            flag = !flag;
        }

        return res;
    }


    // 513. 找树左下角的值 https://leetcode.cn/problems/find-bottom-left-tree-value/solution/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-f34y/
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return {};
        TreeNode* node = nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = q.size(); i--;) {  // q.size is changing, so we need to store the size of q, not compare it in the loop
                node = q.front();
                q.pop();
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }

        return node->val;
    }

};


int main() {
    vector<int> a = {0};
    TreeNode* root = new TreeNode(a[0]);
    for (int i = 0; 2*i+2 < a.size(); ++i) {
        root->left = new TreeNode(a[2*i+1]);
        root->right = new TreeNode(a[2*i+2]);
    }

    Solution s;
    cout << s.isValidBST(root) << endl;

    return 0;
}