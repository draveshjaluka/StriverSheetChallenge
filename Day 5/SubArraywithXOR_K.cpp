/*Question Link: 
https://www.codingninjas.com/codestudio/problems/subarrays-with-xor-k_6826258
https://www.interviewbit.com/problems/subarray-with-given-xor/ */

/* Solution: Using a map which prefix xor mapped to number of time that xor appreared */

#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int k) {
    // Write your code here
    map<int,int> m;
    int xr=0;
    m[xr]++;
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        xr=xr^a[i];
        int x=xr^k;
        if(m.find(x)!=m.end())
        {
            count+=m[x];
        }
        m[xr]++;
    }
    return count;
}
