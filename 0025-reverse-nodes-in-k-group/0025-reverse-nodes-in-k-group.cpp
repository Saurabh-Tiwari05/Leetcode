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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next == nullptr || k == 1) {
            return head;
        }
        ListNode *dummy=new ListNode();
        ListNode *prev=dummy;
        ListNode *prevhead=dummy,*prevend=dummy;


        ListNode *temp=head;

        while(temp){
            ListNode *kthnode=temp;
            int count=0;
            while(kthnode && count<k){
                count++;
                kthnode=kthnode->next;
            }
            if(count<k){
                break;
            }
            ListNode *curr=temp;
            while(count--){
                ListNode* nextnode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextnode;
            }
            temp->next=kthnode;
            prevhead->next=prev;
            prevhead=temp;
            temp=kthnode;
        }
        return dummy->next;
    }
};