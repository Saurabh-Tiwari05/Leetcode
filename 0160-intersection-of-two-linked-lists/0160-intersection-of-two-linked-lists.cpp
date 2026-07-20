/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* solve(int m, ListNode* headA, int n, ListNode* headB) {
        int diff = m - n;
        int i = 0;
        ListNode* temp1 = headA;
        while (i != diff) {
            temp1 = temp1->next;
            i++;
        }
        ListNode* temp2 = headB;
        ListNode* ans = nullptr;
        bool flg = false;
        while (temp1 && temp2) {
            if (temp1 == temp2 && flg == false) {
                ans = temp1;
                flg = true;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1 == temp2 && flg == true) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else {
                temp1 = temp1->next;
                temp2 = temp2->next;
                flg = false;
            }
        }
        return ans;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int m = 0, n = 0;
        ListNode* temp = headA;
        while (temp) {
            temp = temp->next;
            m++;
        }
        temp = headB;
        while (temp) {
            temp = temp->next;
            n++;
        }
        ListNode* ans;
        if (m >= n) {
            ans = solve(m, headA, n, headB);
        } else {
            ans = solve(n, headB, m, headA);
        }
        return ans;
    }
};