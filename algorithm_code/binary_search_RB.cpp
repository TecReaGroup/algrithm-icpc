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


    // 162. 寻找峰值
    int findPeakElement(vector<int>& nums) {
        int ans;
        int left = 0, right = nums.size() - 2;  // 防止 right + 1 越界, 且最后一个元素一定染成蓝色(峰顶或者峰顶右侧)
        int mid = left + (right - left) / 2;
        //nums.push_back(INT_MIN);

        while (left <= right) {
            mid = left + (right - left)/2;
            
            if (mid == nums.size() - 1 ) {
                break;
            }
            else if (nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        ans = left;
        return ans;
    }

   // 1901. 寻找峰值 II 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = mat.size() - 2;
        vector<int> ans = {0, 0};

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int max_index = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[mid][j] > mat[mid][max_index]) {
                    max_index = j;
                }
            }
            if (mat[mid][max_index] < mat[mid + 1][max_index]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        ans[0] = left;
        int max_index = 0;
        for (int j = 1; j < mat[left].size(); j++) {
            if (mat[left][j] > mat[left][max_index]) {
                ans[1] = max_index = j;
            }
        }
        
        return ans;
    }

    // 153. 寻找旋转排序数组中的最小值
    int findMin(vector<int>& nums) {
        int ans;
        int left = 0, right = nums.size() - 2, end = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < nums[end]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        ans = left;

        return ans;
    }

    // 33. 搜索旋转排序数组
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int min_index = findMin(nums);

        vector<int> subvector1(nums.begin(), nums.begin() + min_index);
        vector<int> subvector2(nums.begin() + min_index, nums.end());
        int p1 = binary_search_not_less(subvector1, target);
        int p2 = binary_search_not_less(subvector2, target) + min_index;
        if (p1 != min_index && nums[p1] == target) {
            ans = p1;
        }
        else if (p2 != nums.size() && nums[p2] == target) {
            ans = p2;
        }

        return nums[ans];
    }

    // 154. 寻找旋转排序数组中的最小值 II
    int findMin2(vector<int>& nums) {
        int ans;
        int left = 0, right, end = nums.size() - 1;
        while (end != 0 && nums[end] == nums[end - 1]){
            end--;
        }
        right = end - 1;
        
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < nums[end]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        while (left != 0 && nums[left] == nums[left - 1]){
            left--;
        }
        ans = left;

        return nums[ans];
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

    // Solution s;
    // vector<int> piles = {312884470};
    // int h = 8;
    // int ans = s.minEatingSpeed(piles, h);
    // cout << ans << endl;
    // return 0;

    // // 162. 寻找峰值
    // Solution s;
    // vector<int> nums = {2, 1};
    // int ans = s.findPeakElement(nums);
    // cout << ans << endl;
    // return 0;

    // // 1901. 寻找峰值 II
    // Solution s;
    // vector<vector<int>> mat = {{47,30,35,8,25},{6,36,19,41,40},{24,37,13,46,5},{3,43,15,50,19},{6,15,7,25,18}};
    // vector<int> ans = s.findPeakGrid(mat);
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    // return 0;

    // // 33. 搜索旋转排序数组
    // Solution s;
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // int target = 0;
    // int ans = s.search(nums, target);
    // cout << ans << endl;

    // 154. 寻找旋转排序数组中的最小值 II
    Solution s;
    vector<int> nums = {1,3,3,3};
    int ans = s.findMin2(nums);
    cout << ans << endl;



    return 0;
}
