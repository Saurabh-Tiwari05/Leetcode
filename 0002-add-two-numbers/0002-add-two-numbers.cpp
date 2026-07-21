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
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode *temp1 = l1, *temp2 = l2;
        int carry = 0;
        int a, b;
        while (temp1 || temp2) {
            if (temp1 && temp2) {
                a = temp1->val;
                b = temp2->val;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1) {
                a = temp1->val;
                b = 0;
                temp1 = temp1->next;
            } else {
                b = temp2->val;
                a = 0;
                temp2 = temp2->next;
            }

            int sum = carry + a + b;
            carry = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);
            curr->next = newnode;
            curr = curr->next;
        }
        if(carry){
            ListNode* newnode = new ListNode(carry);
            curr->next=newnode;
        }
        return dummy->next;
    }
};