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
    void reorderList(ListNode* head) {
        if (!head || head->next == nullptr) {
            return;
        }
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<ListNode*> stk;
        ListNode* temp = slow->next;
        slow->next = nullptr;
        while (temp) {
            stk.push(temp);
            temp = temp->next;
        }
        temp = head;
        while (!stk.empty()) {
            ListNode* node = stk.top();
            stk.pop();

            ListNode* nxt = temp->next;
            temp->next = node;
            node->next = nxt;

            temp = nxt;
        }
    }
};