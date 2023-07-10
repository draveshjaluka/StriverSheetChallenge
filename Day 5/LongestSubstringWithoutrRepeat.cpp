/* Question link:
https://bit.ly/3no44fb
https://leetcode.com/problems/longest-substring-without-repeating-characters/ */

/* Solution: Used a map to store the character with its index and checked if is already there in the sequence or not is yes then move otherwise increase the
second pointer and continue; */

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
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
