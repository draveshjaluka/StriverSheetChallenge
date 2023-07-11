/* Question Link
https://leetcode.com/problems/linked-list-cycle/
https://bit.ly/3I2fmxh */

/* Use Two pointer the fast pointer will catch up with slow if there is a cycle */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* f=head;
        ListNode* s=head;
        while(f!=nullptr && f->next!=nullptr)
        {
            f=f->next->next;
            s=s->next;
            if(s==f)
            {
                return true;
            }
        }
        return false;
    }
};
