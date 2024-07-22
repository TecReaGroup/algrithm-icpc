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

    // 876. 链表的中间结点 https://leetcode.cn/problems/middle-of-the-linked-list/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-wzwm/
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 141. 环形链表 https://leetcode.cn/problems/linked-list-cycle/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-c4sw/
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // 142. 环形链表 II https://leetcode.cn/problems/linked-list-cycle-ii/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-nvsq/
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *index1 = head;
                ListNode *index2 = slow;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }

    // 143. 重排链表 https://leetcode.cn/problems/reorder-list/solution/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-u66q/
    void reorderList(ListNode* head) {
        ListNode *middle = middleNode(head);
        ListNode *pre = nullptr;
        ListNode *cur = middle;
        while (cur != nullptr) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        ListNode *p1 = head;
        ListNode *p2 = pre;
        while (p2->next != nullptr) {
            ListNode *tmp1 = p1->next;
            ListNode *tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
    }

    // 237. 删除链表中的节点 https://leetcode.cn/problems/delete-node-in-a-linked-list/solution/ru-he-shan-chu-jie-dian-liu-fen-zhong-ga-x3kn/
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    
    // 19. 删除链表的倒数第 N 个结点 https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/ru-he-shan-chu-jie-dian-liu-fen-zhong-ga-xpfs/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }

    
    // 83. 删除排序链表中的重复元素 https://leetcode.cn/problems/remove-duplicates-from-sorted-list/solution/ru-he-qu-zhong-yi-ge-shi-pin-jiang-tou-p-98g7/
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *cur = head;
        while (cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }
    
    // 82. 删除排序链表中的重复元素 II https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/solution/ru-he-qu-zhong-yi-ge-shi-pin-jiang-tou-p-2ddn/
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            int val = cur->next->val;
            if (cur->next->next->val == val) {
                while (cur->next != nullptr && cur->next->val == val) {
                    cur->next = cur->next->next;
                }
            }
            else cur = cur->next;
        }

        return dummy->next;
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