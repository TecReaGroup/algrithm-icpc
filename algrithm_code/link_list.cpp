#include <bits/stdc++.h>
using namespace std;

/*
struct
构造函数: 是一个特殊的成员函数, 用于在创建对象时初始化对象的成员变量.
         构造函数的名称与类名相同, 并且没有返回类型. 构造函数可以有参数, 也可以没有参数(即默认构造函数)

使用成员初始化列表
ListNode() : val(0), next(nullptr) {}

在构造函数体内赋值
ListNode() {
    val = 0;
    next = nullptr;
}
*/

// Definition for singly-linked list.
struct ListNode {
    int val;                // 节点的值
    ListNode *next;         // 指向下一个节点的指针

    // 默认构造函数，将节点值初始化为0，指针初始化为nullptr
    ListNode() : val(0), next(nullptr) {}

    // 构造函数，接受一个整数参数，将节点值初始化为该参数，指针初始化为nullptr
    ListNode(int x) : val(x), next(nullptr) {}

    // 构造函数，接受一个整数参数和一个指向下一个节点的指针，将节点值和指针分别初始化为这两个参数
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
    // 206. 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        head = pre;
        return head;
    }

    // 92. 反转链表 II
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode node_tmp(0, head);
        ListNode *head_re = &node_tmp;
        for (int i = 0; i < left - 1; i++) {
            head_re = head_re->next;
        }
        
        ListNode *pre = nullptr;
        ListNode *cur = head_re->next;
        ListNode *nxt;
        int i = left;
        while(i <= right) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            i++;
        }

        if (left == 1) head = pre;
        head_re->next->next = cur;
        head_re->next = pre;

        return head;
    }

    //25. K 个一组翻转链表
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode node_tmp(0, head);
        ListNode *head_re = &node_tmp;
        int n;
        for (n = 0; head != nullptr; n++) {
            head = head->next;
        }
        
        ListNode *pre = nullptr;
        ListNode *cur = head_re->next;
        ListNode *nxt;
        int left = 0, right = k - 1;
        while (right <= n - 1) {
            ListNode *tmp = cur;
            while(left <= right) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
                left++;
            }
            if (right == k - 1) head = pre;
            head_re->next = pre;
            head_re = tmp;
            tmp->next = cur;
            right += k;
        }

        return head;
    }

};


int main(){
    // // 206. 反转链表
    // ListNode *node1 = new ListNode(1);
    // ListNode *node2 = new ListNode(2);
    // ListNode *node3 = new ListNode(3);
    // ListNode *node4 = new ListNode(4);
    // ListNode *head = node1;
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = nullptr;
    // Solution solution;
    // ListNode *cur = solution.reverseList(head);;
    // while (cur != nullptr) {
    //     cout << cur->val << " ";
    //     cur = cur->next;
    // }

    // 92. 反转链表 II
    int n;
    cin >> n;
    vector<ListNode> nums(n);
    ListNode *head = &nums[0];
    for (int i = 0; i < n - 1; i++) {
        nums[i] = ListNode(i + 1, &nums[i + 1]);
    }
    nums[n - 1] = ListNode(n);

    Solution solution;
    ListNode *cur = solution.reverseKGroup(head, 2);
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }


    return 0;
}