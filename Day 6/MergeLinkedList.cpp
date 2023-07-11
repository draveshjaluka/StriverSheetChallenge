/* Question Link:
https://bit.ly/3qnbSj8
https://leetcode.com/problems/merge-two-sorted-lists/ */

/* Simple Merging algorithm */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=NULL;ListNode *ptr=NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val) {head=ptr=list1; list1=list1->next;}
        else {head=ptr=list2;list2=list2->next;}
        while(list1 && list2)
        {
            if(list1->val< list2->val ) {ptr->next=list1; ptr=list1; list1=list1->next;}
            else
            {
                ptr->next=list2;ptr=list2;list2=list2->next;
            }
        }
        if(list1) ptr->next=list1;
        if(list2) ptr->next=list2;

        return head;
    }
};
