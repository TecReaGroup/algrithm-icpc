#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
    // 739. 每日温度
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<int> stack;
        vector<int> ans(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            // out
            while (!stack.empty() && temperatures[i] >= temperatures[stack.back()]) {
                stack.pop_back();
            }
            // record
            if (!stack.empty()) {
                ans[i] = stack.back() - i;
            }
            // in
            stack.push_back(i);
        }

        return ans;
    }

    // 42. 接雨水
    int trap(vector<int>& height) {
        int ans = 0;
        deque<int> stack;
        for (int i = 0; i < height.size(); i++) {
            if (stack.empty() || height[i] <= height[stack.back()]) {
                stack.push_back(i);
            } 
            else {
                while (!stack.empty() && height[i] > height[stack.back()]) {
                    int bottom = stack.back();
                    stack.pop_back();
                    if (stack.empty()) {
                        break;
                    }
                    ans += (min(height[i], height[stack.back()]) - height[bottom]) * (i - stack.back() - 1);
                }
                stack.push_back(i);
            }
        }

        return ans;
    }

    // 239. 滑动窗口最大值 https://leetcode.cn/problems/sliding-window-maximum/solution/shi-pin-yi-ge-shi-pin-miao-dong-dan-diao-ezj6/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> stack;
        vector<int> ans(nums.size() - k + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            // in
            while (!stack.empty() && nums[i] >= nums[stack.back()]) {
                stack.pop_back();
            }
            stack.push_back(i);
            // out
            if (stack.front() <= i - k) {
                stack.pop_front();
            }
            // record
            if (i >= k - 1) {
                ans[i - k + 1] = nums[stack.front()];
            }
        }

        return ans;
    }
};


int main() {




    return 0;
}