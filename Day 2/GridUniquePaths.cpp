/* Question Link:
https://leetcode.com/problems/unique-paths/
https://www.codingninjas.com/studio/problems/unique-paths_8230802?challengeSlug=striver-sde-challenge */

/* Solution 1: used math PnC and deduce the formula to (m+n-2)C min(m-1,n-1), now in order to  reach this formula I knew at max I can take m-1 down steps or n-1 
right step so total available steps m+n-2, now to choose when I am taking which step I could have gone with any option but for sake of calculation I took
min of (m-1,n-1) */

#include <bits/stdc++.h> 
#define ull unsigned long long
ull fact(int a,int b)
{
	ull f=1;
	for(ull i=a;i>b;i--)
	{
		f*=i;
	}
	return f;
}
ull fact(int a)
{
	ull f=1;
	for(ull i=2;i<=a;i++)
	{
		f*=i;
	}
	return f;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	
	ull a=fact(m+n-2,n-1);
	ull b=fact(m-1);

	int ans=a/b;
	return ans;
}

/*Solution 2: The above solution is good but still saw the tag on LeetCode that it was DP and started thinking about it but failed, finally my small brother helped
me to figure it out, this solution is DP based on Pascals Triangle Concept */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int arr[m][n];
        for(int i=0;i<n;i++)
        {
            arr[0][i]=1;
        }
        for(int i=0;i<m;i++)
        {
            arr[i][0]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[m-1][n-1];
    }
};
