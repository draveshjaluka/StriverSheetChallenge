/* Question link:
https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277 */

/* Solution simple created and array to store the value of coins availabel in increasing order and then used lower bound to find the position of required coin */

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>arr({1,2,5,10,20,50,100,500,1000});
    int m=amount;
    int ans=0;
    while(m>0)
    { 
        int pos= lower_bound(arr.begin(),arr.end(),m) - arr.begin();
        if(arr[pos]!=m) pos--;
        ans++;
        m=m%arr[pos];
    }
        
    return ans;
}
