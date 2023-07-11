/* Question Link: 
https://bit.ly/3tm5PgF
https://leetcode.com/problems/reverse-pairs/ */

/* Solution: using merge sort as a divide and conquer method (if you don't understand the code I recommend to watch "Strivers Explanation"(Take U Forward) */

#include <bits/stdc++.h> 
void merge(vector<int> &nums,int low,int mid,int high)
{
	int left=low;
	int right=mid+1;
	vector<int>temp;
	while(left<=mid && right<=high)
	{
		if(nums[left]<=nums[right])
		{
			temp.push_back(nums[left++]);
		}
		else
		{
			temp.push_back(nums[right++]);
		}
	}
	while(left<=mid)
	{
		temp.push_back(nums[left++]);
	}
	while(right<=high)
	{
		temp.push_back(nums[right++]);
	}
	for(int i=low;i<=high;i++)
	{
		nums[i]=temp[i-low];
	}
}
int counter(vector<int> &nums,int low,int mid,int high)
{
	int count=0;
	int right=mid+1;
	for(int i=low;i<=mid;i++)
	{
		while(right<=high && nums[i]>2*(long long)nums[right])right++;
		count+=right-(mid+1);
	}
	return count;
}
int mergesort(vector<int> &nums,int low,int high)
{
	int count=0;
	if(low>=high) return count;
	int mid=(low+high)/2;
	count+=mergesort(nums,low,mid);
	count+=mergesort(nums,mid+1,high);
	count+=counter(nums,low,mid,high);
	merge(nums,low,mid,high);
	return count;
}
int makecall(vector<int>& nums,int n)
{
	int count=0;
	count=mergesort(nums,0,n-1);
	return count;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return makecall(arr,n);
}
