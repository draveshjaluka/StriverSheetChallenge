/* Question Link:
https://leetcode.com/problems/copy-list-with-random-pointer/
https://www.codingninjas.com/studio/problems/clone-a-linked-list-with-random-pointers_983604 */

/* First copied the List and there next pointers to a new list then created a map to store a relation between old list and new list, use this relation to point the 
random pointer in the respective address */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* t=head;
        Node* nh=NULL;
        Node* temp=nh;
        while(t)
        {
            if(nh==NULL)
            {
                nh=new Node(t->val);
                temp=nh;
                t=t->next;
                continue;
            }
            temp->next= new Node(t->val);
            t=t->next;
            temp=temp->next;
        }
        temp=nh;
        t=head;
        while(t)
        {
            m[t]=temp;
            t=t->next;
            temp=temp->next;
        }
        temp=nh;
        t=head;
        while(t)
        {
            Node* a=t->random;
            temp->random=m[a];
            temp=temp->next;
            t=t->next;
        }
        return nh;

    }
};
