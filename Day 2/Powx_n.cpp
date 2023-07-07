/* Question Link:
https://leetcode.com/problems/powx-n/
https://www.codingninjas.com/studio/problems/find-x-raised-to-power-n-_626560 */

/* Solution: Challenge was do it without using library function and in O(log n), but was able to solve pretty quickly */


class Solution {
public:
    double myPow(double x, int n) {
    if(n==0) return 1;
    if(n==1) return x;
    if(n>0)
    {
        if(n%2==0)
        {
            return myPow(x*x,n/2);
        } else {
          return x * myPow(x * x, n / 2);
        }
    }
    else
    {
        n=abs(n);
        x=1/x;
        if(n%2==0)
        {
            return myPow(x*x,n/2);
        }
        else return x*myPow(x*x,n/2);
    }
    }
};
