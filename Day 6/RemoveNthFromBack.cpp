/* Question Link: 
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
https://bit.ly/3riZ4JB */

/* Simple solution calculated the length of the original list and then traversed till I found the node before the node to be deleted, then change
its next pointer to the next pointer of the node to be deleted */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s=0;
        ListNode* temp=head;
        while(temp)
        {
            s++;
            temp=temp->next;
        }
        if(s==n) return head->next;
        temp=head;
        while(s-n-1)
        {
            temp=temp->next;
            s--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
