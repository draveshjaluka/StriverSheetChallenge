/* Question Link:
https://bit.ly/3Gsfk1u
https://leetcode.com/problems/reverse-nodes-in-k-group/ */

/* Solution: segregate the k group and then call reverse function and then do a recursive call to the fucntion for the next group */

class Solution {
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* tail=head;
        for(int i=0;i<k;i++)
        {
            if(tail==nullptr)return head;
            tail=tail->next;
        }
        ListNode* nhead=reverse(head,tail);
        head->next=reverseKGroup(tail,k);
        return nhead;
    }
    private:
    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev=nullptr;
        ListNode* cur=head;
        while(cur!=tail)
        {
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
};
