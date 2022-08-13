/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        int carry = 0;
        while(l1 && l2){
            int data = l1->val+l2->val+carry;
            tmp->next = new ListNode(data%10);
            tmp = tmp->next;
            carry = data/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l2){
            int data = l2->val+carry;
            tmp->next = new ListNode(data%10);
            tmp = tmp->next;
            carry = data/10;
            l2 = l2->next;
        }
        while(l1){
            int data = l1->val+carry;
            tmp->next = new ListNode(data%10);
            tmp = tmp->next;
            carry = data/10;
            l1 = l1->next;
        }
        while(carry){
            tmp->next = new ListNode(carry%10);
            carry = carry/10;
            tmp = tmp->next;
        }
        return ans->next;
    }
};