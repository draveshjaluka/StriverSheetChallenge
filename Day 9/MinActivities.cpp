/* Question Link:
https://www.codingninjas.com/studio/problems/1062712?topList=striver-sde-sheet-problems */

/* Solution: Same question as N meetings */

#include<bits/stdc++.h>
struct act
{
    int st;int e;int p;
};
bool static cmp(struct act a1,struct act a2)
{
    if(a1.e<a2.e) return true;
    else if (a1.e>a2.e) return false;
    else if(a1.p<a2.p) return true;
    return false;
}
int maximumActivities(vector<int> &s, vector<int> &f) {
    // Write your code here..
    int n=s.size();
    struct act a[n];
    for(int i=0;i<n;i++)
    {
        a[i].st=s[i];a[i].e=f[i];a[i].p=i+1;
    }
    sort(a,a+n,cmp);
    int end=a[0].e;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(a[i].st>=end)
        {
            ans++;
            end=a[i].e;
        }
    }
    return ans;
}
