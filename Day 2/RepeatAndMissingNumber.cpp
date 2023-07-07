/* Question Link
https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=1 */

/* Solution: was asked to solve in linear time and constant space, therefore, I thought to use the array index as a map and after this, it was pretty
straightforward */

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int> ans;
	int i=0;
	while(i<n)
	{
		if(arr[i]-1!=i)
		{
			swap(arr[i],arr[arr[i]-1]);
		}
		if(arr[i]==arr[arr[i]-1]) i++;
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]-1!=i)
		{
			ans.first=i+1;
			ans.second=arr[i];
			break;
		}
	}
	return ans;
	
}
