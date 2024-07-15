#include <bits/stdc++.h>
using namespace std;

/* 
    01背包：choose or not questions
    完全背包： 可以重复选，即第选了第i个物品后，还处于第i个物品进行判定，不选第i个物品，才进入第i-1个物品的判定，
            递归表达：dfs(i, c) = max(dfs(i-1, c), dfs(i, c-w[i]) + v[i])
    常见变形:1.至多型
            2.恰好型 dfs(i, c) = dfs(i-1, c) + dfs(i-1, c-w[i]) // 前i-1个物品的组合，第i个物品（必选）与前i-1个物品的组合
            3.至少型 
*/

/* 
    01背包问题
    有N件物品和一个容量为V的背包。第i件物品的体积是w[i]，价值是v[i]。
    求解价值总和最大指。
    限制条件：
    1 <= N <= 100
    1 <= V <= 1000
    1 <= w[i], v[i] <= 1000

    Analysis 回溯思考:
    回溯三问：1.题目所给的操作及结果 2.题目问题的表述 3.题目的子问题（不同情况的考虑）

    dfs(i, c) = max(dfs(i-1, c), dfs(i-1, c-w[i]) + v[i])
*/
class Solution{
public:
    // 记忆化搜索
    int zero_one_knapsack(int capacity, vector<int> &w, vector<int> &v){
        // capacity is the capacity of the knapsack
        // w[i] is the weight of the i-th item
        // v[i] is the value of the i-th item
        // n is the number of items
        int n = w.size();
        vector<vector<int>> cache(n, vector<int>(capacity + 1, -1));
        function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0 || c == 0) return 0;    // no item left
            int &tmp = cache[i][c];
            if (tmp != -1) return tmp;
            if (c < w[i]) return tmp = dfs(i-1, c); // cannot put the i-th item into the knapsack
            return tmp = max(dfs(i-1, c), dfs(i-1, c-w[i]) + v[i]);
        };
        return dfs(n-1, capacity);
    }

    //目标和问题 leetcode494
    //dfs(i, c) = dfs(i-1, c) + dfs(i-1, c-w[i]) // i num, c target_now
    //算法复杂度 O(n*terget)
    int findTargetSumWays(vector<int> &nums, int target) {
        // p 正数和
        // sum - p 负数和（绝对值）
        // p - (sum - p) = target
        // p = (target + sum) / 2 // so (target + sum must) be double and positive
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2 == 1) return 0;
        else target /= 2;
        int n = nums.size();
        vector<vector<int>> cache(n, vector<int>(target + 1, -1));
        function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0) return c == 0 ? 1 : 0; 
            int &tmp = cache[i][c];
            if (tmp != -1) return tmp;
            if (c < nums[i]) return tmp = dfs(i-1, c); // cannot put the i-th item into the knapsack
            return tmp = dfs(i-1, c) + dfs(i-1, c-nums[i]);
        };
        return dfs(n-1, target);
    }

    // 递推：记忆化搜索可以1：1地转化为递推，把dfs改成f数组，再把递归改成循环
    // 双数组：
    // f[i][c] = f[i-1][c] + f[i-1][c - w[i]] 防止越界-> f[i + 1][c] = f[i][c] + f[i][c - w[i]]
    int findTargetSumWays_nv(vector<int> &nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2 == 1) return 0;
        else target /= 2;
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(target + 1, 0));
        f[0][0] = 1;

        for (int i = 0; i < n; i++){
            for (int j = 0; j <= target; j++){  // 由于需要将上一轮状态复制下来，所以j从0开始
                f[i + 1][j] = f[i][j];
                if (j - nums[i] >= 0) f[i + 1][j] += f[i][j - nums[i]];
            }
        }

        return f[n][target];
    }
    // 双单数组：f[(i+1)%2][c] = f[i%2][c] + f[i%2][c - w[i]] // %2 点睛之笔
    // 单数组：
    int findTargetSumWays_1v(vector<int> &nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2 == 1) return 0;
        else target /= 2;
        int n = nums.size();
        vector<int> f(target + 1, 0);
        f[0] = 1;

        for (int i = 0; i < n; i++){
            for (int j = target; j >= nums[i]; j--){    // 由于每个元素需要用到前一次的状态和自身的状态，所以从后往前迭代
                f[j] += f[j - nums[i]];
            }
        }

        return f[target];
    }

    // f[i][c] = min(f[i-1][c], f[i-1][c - w[i]] + 1)
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<int> f(amount + 1, 1000000);
        f[0] = 0;

        for (int i = 0; i < n; i++){
            for (int j = coins[i]; j <= amount; j++){    // 由于每个元素需要用到前面的结果状态和自身的状态，所以从前往后迭代
                f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }

        return f[amount] != 1000000 ? f[amount] : -1;
    }

    // f[i][c] = f[i-1][c] + f[i][c - w[i]]
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<int> f(amount + 1, 0);
        f[0] = 1;

        for (int i = 0; i < n; i++){
            for (int j = coins[i]; j <= amount; j++){    // 由于每个元素需要用到前面的结果状态和自身的状态，所以从前往后迭代
                f[j] += f[j - coins[i]];
            }
        }

        return f[amount];
    }

    // dfs(i, c) = max(dfs(i-1, c), dfs(i-1, c-w[i]) + 1)
    // dfs(0, 0) = 0
    // f[i][c] = max(f[i-1][c], f[i-1][c - w[i]] + 1)
    // f[0][0] = 
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(target + 1, -1);
        f[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = target; j >= nums[i]; j--){
                if (f[j - nums[i]] != -1) f[j] = max(f[j], f[j - nums[i]] + 1);
            }
        }
        return f[target];
    }

    // 416分割等和子集
    // dfs(i, c) = dfs(i-1, c) || dfs(i-1, c - nums[i]) //choose or not
    // dfs(0, 0) = true
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        sum /= 2;
        int n = nums.size();
        vector<int> f(sum + 1, 0);
        f[0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = sum; j >= nums[i]; j--){
                f[j] = f[j] || f[j - nums[i]];
            }
        }
        return f[sum];
    }

    // 279 完全平方数
    // ans must be present
    // dfs(i, c) = min(dfs(i-1, c), dfs(i, c - nums[i]) + 1)
    int numSquares(int n) {
        int tmp = sqrt(n);
        vector<int> nums(tmp + 1, 0);
        for (int i = 1; i <= tmp; i++) nums[i] = i * i;
        vector<int> f(n + 1, 1000000);
        f[0] = 0;
        for (int i = 1; i <= tmp; i++){
            for (int j = nums[i]; j <= n; j++){
                f[j] = min(f[j], f[j - nums[i]] + 1);
            }
        }

        return f[n];
    }

    /*  2787. 将一个数字表示成幂的和的方案数
        1 <= n <= 300
        1 <= x <= 5
    */
   // dfs(n, c) = dfs(n - 1, c) + dfs(n - 1, c - nums[n])
   // dfs(0, 0) = 1; 
    int numberOfWays(int n, int x) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++){
            long long tmp = pow(i, x);
            for (int j = n; j >= tmp; j--){
                f[j] = (f[j]+f[j - tmp])%1000000007;
            }
        }
        return f[n];
    }

    // 1049. 最后一块石头的重量 II
    // function<int(int, int)> dfs = [&](int i, int c) -> int {}
    // 求2/sum内能装的最大值
    /*    int lastStoneWeightII(std::vector<int>& stones) {
        int n = stones.size();
        int S = 0;
        for (int stone : stones) {
            S += stone;
        }

        unordered_map<int, unordered_map<int, int>> memo;
        
        // 使用 lambda 表达式定义辅助函数
        function<int(int, int)> dfs = [&](int i, int s) -> int {
            if (i == stones.size()) { // 遍历完后，返回两堆石头和的绝对值之差
                return abs(S - 2 * s);
            }
            if (memo[i].count(s)) {
                return memo[i][s];
            }
            // 第 i 个石头 选 / 不选，取最小值
            int res = min(dfs(i + 1, s), dfs(i + 1, s + stones[i]));
            memo[i][s] = res;
            return res;
        };

        return dfs(0, 0);
    }*/
    // f[j] = max(f[j], f[j - i] + i);
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int t = sum/2;
        vector<int> f(t + 1, 0);
        for (int i : stones){
            for (int j = t; j >= i; j--){
                f[j] = max(f[j], f[j - i] + i);
            }
        }
        return sum - 2*f[t];
    }
};

int main(void){
    Solution sol;
    vector<int> stones = {31, 26, 33, 21, 40};
    cout << sol.lastStoneWeightII(stones) << endl;
    return 0;
}