#include <bits/stdc++.h>
using namespace std;


#include <iostream>
#include <queue>
#include <vector>

// 定义自定义数据结构
class CustomData {
public:
    int key;      // 第一个元素
    int value1;   // 第二个元素
    int value2;   // 第三个元素

    CustomData(int k, int v1, int v2) : key(k), value1(v1), value2(v2) {}

    // 重载小于操作符用于比较
    bool operator>(const CustomData& other) const {
        return this->key > other.key;
    }
};

// 自定义比较函数
struct Compare {
    bool operator()(const CustomData& lhs, const CustomData& rhs) {
        return lhs > rhs; // 使用重载的操作符
    }
};


class Solution {
 public:
    // 42. 接雨水
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 1, right = height.size() - 2;
        int left_max = height[0], right_max = height[height.size() - 1];
        while (left <= right) {
            if (left_max < right_max) {
                ans += max(0, left_max - height[left]);
                left_max = max(left_max, height[left]);
                left++;
            } else {
                ans += max(0, right_max - height[right]);
                right_max = max(right_max, height[right]);
                right--;
            }
        }

        return ans;
    }

    // 407. 接雨水 II
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<char>> visited(200, vector<char>(200, 0));
        priority_queue<CustomData, vector<CustomData>, Compare> minHeap;
        int m = heightMap.size(), n = heightMap[0].size();
        for (int i = 0; i < m; i++) {
            minHeap.push(CustomData(heightMap[i][0], i, 0));
            minHeap.push(CustomData(heightMap[i][n - 1], i, n - 1));
            visited[i][0] = 1;
            visited[i][n - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            minHeap.push(CustomData(heightMap[0][i], 0, i));
            minHeap.push(CustomData(heightMap[m - 1][i], m - 1, i));
            visited[0][i] = 1;
            visited[m - 1][i] = 1;
        }

        int ans = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!minHeap.empty()) {
            CustomData data = minHeap.top();
            minHeap.pop();
            for (auto direction : directions) {
                int x = data.value1 + direction[0];
                int y = data.value2 + direction[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    ans += max(0, data.key - heightMap[x][y]);
                    visited[x][y] = 1;
                    heightMap[x][y] = max(data.key, heightMap[x][y]);
                    minHeap.push(CustomData(heightMap[x][y], x, y));
                }
            }
        }

        return ans;
    }
};



int main() {





    return 0;
}