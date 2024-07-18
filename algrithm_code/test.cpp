#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    auto begin1 = begin(arr);
    auto end1 = end(arr);

    for (auto it = begin1; it != end1; ++it) {
        cout << *it << " "; // 通过迭代器访问数组元素
    }
    
}