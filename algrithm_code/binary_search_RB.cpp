// Copyright 2024 Await
#include <bits/stdc++.h>
using namespace std;


class Solution {
 public:
    // 模板
    int binary_search_not_less(const vector<int>& nums, int target) {
        int ans;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right)/2;

            if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        ans = left;

        return ans;
    }

    // 34. 在排序数组中查找元素的第一个和最后一个位置
    vector<int> searchRange(const vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        ans[0] = binary_search_not_less(nums, target);
        if (ans[0] == -1 || ans[0] == nums.size() || nums[ans[0]] != target){
            return {-1, -1};
        }
        ans[1] = binary_search_not_less(nums, target + 1) - 1;

        return ans;
    }

    // 2439. 最小化数组中的最大值
    int minimizeArrayValue(const vector<int>& nums) {
        int ans;
        const long long MAX = 1e9 + 7;
        long long left = 0, right = MAX;

        while (left <= right) {
            int mid = (left + right) / 2;
            long long extra = 0;
            for (int i = nums.size() - 1; i >= 0; i--){
                extra = max((long long) 0, nums[i] + extra - mid);
            }
            if (extra == 0) {
                ans = right = mid;
                if (right == left) {
                    break;
                }
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    // 875. 爱吃香蕉的珂珂  // 1. t[i] = ceil(piles[i] / speed) 2. sum(t) <= h
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans;
        const long long MAX = 1e9 + 7;
        long long left = 1, right = MAX;

        if (piles.size() == 0) {
            return piles[0];
        }

        while (left <= right) {
            int mid = (left + right) / 2;
            long long time_sum = 0;

            for (int i = piles.size() - 1; i >= 0; i--){
                time_sum += (piles[i] + mid - 1) / mid;  // equal to ceil(1.0*piles[i]/mid);
            }
            if (time_sum <= h) {
                ans = right = mid;
                if (right == left) {
                    break;
                }
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }


};


int main() {
    // Solution s;
    // vector<int> nums = {5, 7, 7, 8, 8, 10};
    // int target = 8;
    // vector<int> ans = s.searchRange(nums, target);
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }

    // Solution s;
    // vector<int> nums = {3, 7, 1, 6};
    // int ans = s.minimizeArrayValue(nums);
    // cout << ans << endl;

    Solution s;
    vector<int> piles = {312884470};
    int h = 8;
    int ans = s.minEatingSpeed(piles, h);
    cout << ans << endl;
    return 0;
}
