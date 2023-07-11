/* Question Link:
https://leetcode.com/problems/palindrome-linked-list/
https://bit.ly/3GqRMKv */

/* Solution 1: Linear time and O(n) space, simply use a string and then check if the reverse is equal or not */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s;
        ListNode*temp=head;
        while(temp)
        {
            s+=temp->val;
            temp=temp->next;
        }
        string a=s;
        reverse(s.begin(),s.end());
        if(a==s) return true;
        return false;
    }
};

/* Solution 2: Linear Time and O(1) space, Simple divide the Linked list into two halves and reverse one part in O(1) space and then compare it with the other half*/

class Solution {
public:
    ListNode* reverse(ListNode *nhead)
    {
        ListNode *temp,*prev,*curr;
        prev=nhead;
        curr=nhead->next;
        prev->next=NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
       }
       return prev;
    }
    bool isPalindrome(ListNode* head) {
        int s=0;
        ListNode* temp=head,*prev;
        while(temp!=NULL)
        {
            s++;
            temp=temp->next;
        }
        if(s<=1) return true;
        //cout<<s;
        temp=head;
        bool flag=true;
            if(s%2!=0) flag=false;
            s=floor(s/2);
            while(s>0)
            {
                prev=temp;
                temp=temp->next;
                s--;
            }
            if(flag==false)
            {
                temp=temp->next;
            }
            prev->next=NULL;

            ListNode * nhead=reverse(temp);
            temp=head;
            while(temp!=NULL && nhead!=NULL)
            {
                if(temp->val!=nhead->val)
                 return false;
                 temp=temp->next;
                 nhead=nhead->next;
            }
            return true;
        
    }
};
