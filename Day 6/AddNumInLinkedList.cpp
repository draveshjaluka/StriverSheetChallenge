/* Question link:
https://leetcode.com/problems/add-two-numbers/
https://bit.ly/3qqbgcq */

/* Solution used the simple logic of adding a number and applied it in the algorithm */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* head=new ListNode();
        ListNode* temp=head;
        int c=0;
        int a=0;
        while(t1 && t2)
        {
            a=c;
            a+=t1->val+t2->val;
            if(a>9){  c=1;a=a%10;}
            else c=0;
            temp->val=a;
            temp->next=new ListNode();
            t1=t1->next;
            t2=t2->next;
            temp=temp->next;
        }
        if( t1 || t2)
        {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        ListNode* t=temp->next;
        temp->next=new ListNode();
        temp=temp->next;}
        while(t1)
        {
            a=c;
            a+=t1->val;
            if(a>9){c=1;a=a%10;}
            else c=0;
            temp->val=a;
            temp->next=new ListNode();
            temp=temp->next;
            t1=t1->next;
        }
        while(t2)
        {
            a=c;
            a+=t2->val;
            if(a>9){c=1;a=a%10;}
            else c=0;
            temp->val=a;
            temp->next=new ListNode();
            temp=temp->next;
            t2=t2->next;
        }
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        ListNode* t=temp->next;
        temp->next=nullptr;
        if(c==1)
        {
            temp->next=new ListNode();
            temp=temp->next;
            temp->val=c;
            temp->next=nullptr;
        }
       // free(t);
        return head;
    }
};
