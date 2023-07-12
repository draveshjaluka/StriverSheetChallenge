/* Question Link: 
https://bit.ly/33bNQPo
https://leetcode.com/problems/rotate-list/description/ */

/* Solution: Simply used a two-pointer approach to reach the two different heads of the linked list and then joined them but changing nullptr position */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int s=0;
        ListNode *temp=head;
        if(head==NULL || head->next==NULL || k==0) return head;
        while(temp!=NULL)
        {
            s++;
            temp=temp->next;
        }
        temp=head;
        k=k%s;
        if(k)
        {while(s-k>1)
        {
            temp=temp->next;
            s--;
        }
        ListNode *nhead=temp->next;
        temp->next=NULL;
        temp=nhead;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        head=nhead;}
        return head;
    }
};
