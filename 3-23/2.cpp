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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=NULL,*pre=head;
        while(pre!=NULL){
            ListNode* t=pre->next;
            pre->next=cur;
            cur=pre;
            pre=t;
        } 
        return cur;
    }
};