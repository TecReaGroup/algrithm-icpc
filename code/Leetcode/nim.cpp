#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // 292. Nim Game
    bool canWinNim(int n) {
        return n % 4 != 0;
    }

    // 1561. Maximum Number of Coins You Can Get
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int res = 0;
        for (int i = 1; i <= n / 3; i++) {
            res += piles[n - 2*i];
        }
        return res;
    }

    // 877. Stone Game
    /*
    将数组按照索引奇偶性分成两组
    作为先手的 Alice 可以在第一次取走石子时就决定取走哪一组的石子，并全程取走同一组的石子
    则 Bob 只能取走另一组的石子
    故 Alice 只需要选择取走奇数索引组或偶数索引组的石子数量多的一组即可
    */
    bool stoneGame(vector<int>& piles) {
        return true;
    }

    
};