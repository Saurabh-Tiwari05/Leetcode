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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* temp = head;
        int i = 1, flg = 0;
        ListNode *t1,*t2;

        while (temp) {
            if (i % 2 != 0 && flg == 0) {
                t1 = temp;
                flg = 1;
                i++;
                temp = temp->next;
                continue;
            } else if (i % 2 == 0 && flg == 1) {
                t2 = temp;
                temp = temp->next;
                flg = 0;
                i++;
                 swap(t1->val,t2->val);
            } 
            // else {
            //     temp = temp->next;
            //     i++;
            //     continue;
            // }
           
        }
        return head;
    }
};