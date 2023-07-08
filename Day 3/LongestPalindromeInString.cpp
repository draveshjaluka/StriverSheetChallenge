/* Question Link: 
https://leetcode.com/problems/longest-palindromic-substring/
https://www.codingninjas.com/studio/problems/day-12-:-longest-palindromic-substring_758900?leftPanelTab=1 */

/* Solution: after reading the question thought to use two pointer approach and was confident it would work looking O(n*n) is allowed but at first I tried an inward
approach i.e. pointer 1 at start and then pointer 2 at the end but found this is not an efficient approach, better would be to go for an outward approach and then
found out there should be different condition in case of size of even plaindrome and odd plaindrome finally did the change and solved it */

class Solution {
public:
    string ans="";
    void solver(string &s,int l,int r)
    {
        while(l>=0 && r<s.size() && s[l]==s[r] )
        {
            l--;r++;
        }
        if(ans.size()< r-l) ans=s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string t1,t2;
        for( int i=0;i<n;i++)
        {
            solver(s,i,i);
            solver(s,i,i+1);
        }
        return ans;
    }
};
