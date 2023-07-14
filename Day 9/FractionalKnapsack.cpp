/* Question Link:
https://www.codingninjas.com/studio/problems/fractional-knapsack_975286 */

//Solution: Another Standard problem, found out the ratio between v/wt and then sorted according to it and then simply added and substracted the weight accordingly



#include <bits/stdc++.h> 
bool static cmp(const pair<double,int>&v1 ,const pair<double,int>&v2)
{
    return v1.first>v2.first;
}
double maximumValue (vector<pair<int, int>>& it, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<pair<double,int>> r;
    for(int i=0;i<n;i++)
    {   
        double a = double(it[i].second)/(it[i].first);
        int b = it[i].first;
        //cout<<a<<" "<<b<<endl;
        r.push_back(make_pair(a,b));
    }
    sort(r.begin(),r.end(),cmp);
   /* for(int i=0;i<n;i++)
    {
        cout<<r[i].first<<" "<<r[i].second<<endl;
    }*/
    double ans=0;
    for(int i=0;i<n;i++)
    {
        if(w==0) break;
        else if(w>=r[i].second)
        {
            w-=r[i].second;
           // cout<<r[i].first<<" "<<r[i].second<<endl;
            ans+=(r[i].first*r[i].second);
            //cout<<ans<<endl;
        }
        else
        {
            ans+=r[i].first*w;
            w-=w;
        }
    }
    return ans;
}
