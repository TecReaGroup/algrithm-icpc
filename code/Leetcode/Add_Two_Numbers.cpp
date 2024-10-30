# include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int last = (l1->val + l2->val)/10;
        ListNode* head = new ListNode((l1->val + l2->val)%10);
        ListNode* pre = head;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr || l2 != nullptr || last != 0){
            if (l1 != nullptr && l2 != nullptr) {
                pre->next = new ListNode(last);
                last = 0;
            }
            else if (l1 == nullptr){
                pre->next = new ListNode((l2->val + last)%10);
                last = (l2->val + last)/10;
                pre = pre->next;
                l2 = l2->next;
            }
            else if (l2 == nullptr){
                pre->next = new ListNode((l1->val + last)%10);
                last = (l1->val + last)/10;
                pre = pre->next;
                l1 = l1->next;
            }
            else{
                pre->next = new ListNode((l1->val + l2->val + last)%10);
                last = (l1->val + l2->val + last)/10;
                pre = pre->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }

        return head;
    }
};

int main(){
    int a[3] = {2, 4, 3};
    int b[3] = {5, 6, 4};
    ListNode* l1 = new ListNode(a[0]);
    ListNode* l2 = new ListNode(b[0]);
    ListNode* pre = l1;
    for (int i = 1; i < 3; i++){
        pre->next = new ListNode(a[i]);
        pre = pre->next;
    }
    pre = l2;
    for (int i = 1; i < 3; i++){
        pre->next = new ListNode(b[i]);
        pre = pre->next;
    }
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}