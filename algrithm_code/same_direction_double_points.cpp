#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 2962. 统计最大元素出现至少k次的子数组数目
    long long countSubarrays(vector<int>& nums, int k) {
        int maxnum = 0, count = 0, tmp = 0, max_cnt = 0; 
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxnum = max(maxnum, nums[i]);
        }

        int l = 0, r = 0;
        while (count < k) {
            if (r + 1 > nums.size()) return 0;
            if (nums[r] == maxnum) {
                if (count == 0) l = r;
                count++;
            }
            r++;
        }
        ans += l+1;

        for (; r < nums.size(); r++) {
            if (nums[r] == maxnum) {
                l++;
                while (nums[l] != maxnum)  l++;
            }
            ans += l+1;
        }

        return ans;

    }

    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;

        for (int right = 0, left = 0; right < nums.size(); right++){
            for (int i = left; i < right; i++){
                if ((nums[i] & nums[right]) == 0) continue;
                else left = i + 1;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {338970160,525086042,19212931,213753017,321613307,553272419,190837185,548628106,793546945,243936947};
    cout << s.longestNiceSubarray(nums) << endl;

    return 0;
}