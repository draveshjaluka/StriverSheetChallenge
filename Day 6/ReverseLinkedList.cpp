/* Question Link:
https://leetcode.com/problems/reverse-linked-list/ 
https://bit.ly/3qoE6K6 */

/* Solution: Simple next pointer changer in the Linked List */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* prev;
        ListNode* curr;
        if(head==nullptr || head->next==nullptr) return head;
        curr=head->next;
   
        prev=head;
        prev->next=NULL;
        while(curr!=nullptr)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;        
        }
    return prev;
    }
};
