/* Question Link:
https://bit.ly/3fiMQeG
https://leetcode.com/problems/intersection-of-two-linked-lists/ */

/* Very Simple Solution, figure out the longer linked list and traverse it until the size of both lists is equal, after this traverse both of them simultaneously */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sa=0,sb=0;
        ListNode* ta=headA;
        ListNode* tb=headB;
        while(ta){ sa++;ta=ta->next;}
        while(tb){sb++;tb=tb->next;}
        if(sa>sb){
            while(sa-sb!=0){
                headA=headA->next;
                sa--;
            }
        }
        if(sa<sb){
            while(sb-sa!=0){
                headB=headB->next;
                sb--;
            }
        }
        while((headA&&headB)&&(headA!=headB))
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
