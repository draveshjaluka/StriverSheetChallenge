/* Question link:
https://bit.ly/3KcRxoG
https://leetcode.com/problems/middle-of-the-linked-list/ */

/* Solution: Simple two pointer solution until the fast pointer reaches the end of the list */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* s=head, *f=head;
        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
};
