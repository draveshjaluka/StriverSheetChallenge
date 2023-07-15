/* Question Link 
https://www.codingninjas.com/studio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems */

/* Solution using take and not take approach to calculate sum and then push in an array */

#include<bits/stdc++.h>
void solved(int i,vector<int>&arr,int n,vector<int>&ans,int sum)
{
	if(i==n)
	{
		ans.push_back(sum);
		return;
	}
	solved(i+1,arr,n,ans,sum+arr[i]);
	solved(i+1,arr,n,ans,sum);
}
vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	solved(0,num,num.size(),ans,0);
	sort(ans.begin(),ans.end());
	return ans;	
}
