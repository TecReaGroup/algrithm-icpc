#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
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
};


int main() {


    return 0;
}