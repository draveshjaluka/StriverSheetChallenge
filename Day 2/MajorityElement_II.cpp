/* Question Link: 
https://leetcode.com/problems/majority-element-ii/
https://www.codingninjas.com/studio/problems/majority-element-ii_8230738?challengeSlug=striver-sde-challenge */

/* Solution: was stuck a bit in this question, I was trying to apply the concept of Majority Element_I but was failing as missed one pont i.e. to find out max elements
that fits in the given criteria, after figuring that it was straight forward logic transformation */

#include <bits/stdc++.h>

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    if(n==1) return {arr[0]};
    int c1=0,c2=0,e1,e2;
    for(int i=0;i<n;i++)
    {
        if(c1==0 && arr[i]!=e2) {c1=1;e1=arr[i];}
        else if(c2==0 && arr[i]!=e1){c2=1;e2=arr[i];}
        else if(e1==arr[i]) c1++;
        else if(e2==arr[i]) c2++;
        else {c1--;c2--;}
    }
    int m= (int) n/3 +1;
    c1=0;c2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==e1)c1++;
        if(arr[i]==e2)c2++;
    }
    vector<int> ans;
    if(c1>=m) ans.push_back(e1);
    if(c2>=m) ans.push_back(e2);
    return ans;

}
