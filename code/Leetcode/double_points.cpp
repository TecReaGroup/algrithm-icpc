#include <bits/stdc++.h>
using namespace std;

//main: get O(n) information for O(1) time
class Solution{
public:
    // 167. 两数之和 II - 输入有序数组
    // firstly bigger: p--; then smaller: q++ -> answer
    vector<int> twoSum(vector<int>& numbers, int target) {
        int q = 0, p = numbers.size() - 1;
        while(q < p){
            if(numbers[q] + numbers[p] == target) return {q+1, p+1};
            else if(numbers[q] + numbers[p] < target) q++;
            else p--;
        }
        return {0};
    }

    // 15. 三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        int k = nums.size() - 1;
        while (true){
            int i = 0, j = k - 1;
            while(i < j){
                if (nums[k] + nums[k - 1] + nums[k - 2] < 0 || nums[i] + nums[i + 1] + nums[k] > 0) break;  //剪枝
                if(nums[i] + nums[j] == -nums[k]){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(i < j && nums[i] == nums[i + 1]) i++; //答案去重 （其他题型：容器元素去重）
                    i++;
                }
                else if(nums[i] + nums[j] < -nums[k]) i++;
                else j--;
            }
            while(k >= 1 && nums[k] == nums[k -1]) k--; //答案去重
            k--;
            if (k < 2) break;
        }
        return ans;
    }


};




int main(){
    Solution s;
    // vector<int> numbers = {2,7,11,15};
    // int target = 9;
    // vector<int> res = s.twoSum(numbers, target);
    // for(auto i : res) cout << i << " ";

    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<vector<int>> res = s.threeSum(nums);
    // for(auto i : res){
    //     for(auto j : i) cout << j << " ";
    //     cout << endl;
    // }

    return 0;
}