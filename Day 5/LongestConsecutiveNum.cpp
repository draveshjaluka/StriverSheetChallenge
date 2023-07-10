/* Question Link: 
https://bit.ly/34EoAS0
https://leetcode.com/problems/longest-consecutive-sequence/ */


/*Solution: used a map to set the count of all present integer as one, now went to find the smallest possible integer in the list and then find the longest consecutive
sequence of number in it */

#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]=1;
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i]-1)==m.end())
        {
            int count=1;
            int num=arr[i]+1;
            while(m.find(num)!=m.end())
            {
                count++;
                num++;
            }
            ans=max(ans,count);
        }
    }
    return ans;
}
