/* Question Link:
https://bit.ly/3K32lpf
https://leetcode.com/problems/linked-list-cycle-ii/ */

/* Using the two pointer to judge a cycle exist or not and after then set slow pointer to head and then inc both slow & fast pointer both by one the match position
would be the entrance */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *s,*f;
        s=f=head;
        while( f!=nullptr && f->next!=nullptr)
        {
            s=s->next;
            f=f->next->next;
            if(s==f)
            {
                s=head;
                while(s!=f)
                {
                    s=s->next;f=f->next;
                }
                return s;
            }
        }
        return nullptr;
    }
};
