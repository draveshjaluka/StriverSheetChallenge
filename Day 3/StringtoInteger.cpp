/* Question Link: 
https://leetcode.com/problems/string-to-integer-atoi/
https://www.codingninjas.com/studio/problems/981270?topList=striver-sde-sheet-problems */

/* Solution: some continuous integer present in the given string needed to find that number and return it as an integer with using built in conversion, hence first got
rid of the spaces and store the "sign(+,-)" of the number using flag value and when got the integer used simple multiplication of 10 storing it, only trick here was
string can store more data than integer hence it was important to break the loop of storing integer before the integer got overflowed, 
to check I use if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]-'0'>7) break the loop*/

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int num=0;
        while(i<s.size() && s[i]==' ') i++;
        int flag=1;
        if(s[i]=='+' || s[i]=='-')
        {
            s[i]=='+'?flag=1:flag=-1;
            i++;
        }

        if(s[i]-'0'<0 && s[i]-'0'>9) return 0;

        while(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]-'0'>7))
            {
                return flag==1?INT_MAX:INT_MIN;
            }
            num=num*10+ (s[i]-'0');
            i++;
        }
 

        return flag==1?num:num*flag;

    }
};
