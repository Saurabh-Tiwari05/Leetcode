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
    ListNode* partition(ListNode* head, int x) {
        if(!head || head->next==nullptr){
            return head;
        }
        ListNode *t1=new ListNode(),*t2=new ListNode();
        ListNode *t1head=t1,*t2head=t2;
        ListNode *temp=head;
        while(temp){
            if(temp->val <x){
                t1->next=temp;
                t1=t1->next;
            }
            else{
                t2->next=temp;
                t2=t2->next;
            }
            temp=temp->next;
        }
        t2->next=nullptr;
        t1->next=t2head->next;
        return t1head->next;

    }
};