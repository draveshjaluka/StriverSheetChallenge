/* Question Link:
https://leetcode.com/problems/count-and-say/
https://www.codingninjas.com/studio/problems/count-and-say_8230807?challengeSlug=striver-sde-challenge */

/* Solution: When I saw this question, I remembered I have read this question in the past but was unable to solve as I didn't understand the question correctly
But this time I understood and was able to code it as well, used simple resursion call unti n=1, then just appended the count of digits with the digit present */

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string temp = countAndSay(n-1);
        int c=1;
        int l=temp.size();
        string ans="";
        for(int i=0;i<l;i++)
        {
            if(i<l && temp[i]==temp[i+1])
            {
                c++;
            }
            else
            {
                ans+=char(c+int('0'));
                ans+=temp[i];
                c=1;
            }
        }
        return ans;

    }
};
