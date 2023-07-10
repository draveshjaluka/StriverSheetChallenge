/* Question Link 
https://bit.ly/31UHoeM 
https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1 */

/* Solution: In a loop calculate the sum and if the current sum == target then store its length, if not check if the remaining sum is there in the map which is being
used to store the sum on that position, if you find it you need to calculate the length from the current pointer to that pointer and check if that is the max one 
or not */

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  unordered_map<int,int> m;
  int sum=0;
  int maxlen=0;
  int n=arr.size();
  for(int i=0;i<arr.size();i++)
  {
    sum+=arr[i];
    if(sum==k)
    {
      maxlen=max(maxlen,i+1);
    }
    int rem=sum-0;
    if(m.find(rem)!=m.end())
    {
      int len=i-m[rem];
      maxlen=max(maxlen,len);
    }
    else
      m[sum]=i;
  }
return maxlen;
}
