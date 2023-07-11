/* Question link:
https://leetcode.com/problems/delete-node-in-a-linked-list/
https://bit.ly/3GqW4kN */


class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
        //cout<<node->val;
        
    }
};
