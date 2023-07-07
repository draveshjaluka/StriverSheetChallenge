/* Question Link:
https://www.codingninjas.com/studio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge&leftPanelTab=1 */

/* Solution: According to constraints O(n*n) was not allowed, and a big hint was given in the question heading(present in StriversSheet), but still was not
able to crack it thanks to Striver and his videos I was able to understand the concept of merge sort even better */

#include <bits/stdc++.h> 
#define ll long long
long long merge(ll *arr,int low,int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right =mid+1;
    ll ans=0;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
            ans+=(mid-left)+1;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);right++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return ans;
}
long long mergesort(ll *arr,int low, int high )
{
    ll ans=0;
    if(low>=high) return ans;
    int mid=(low+high)/2;
    ans+=mergesort(arr, low, mid);
    ans+=mergesort(arr,mid+1,high);
    ans+=merge(arr,low,mid,high);
    return ans;
}
long long getInversions(long long *arr, int n){ //main function
    // Write your code here.
    long long ans=0;
    ans=mergesort(arr,0,n-1);
    return ans;
}
