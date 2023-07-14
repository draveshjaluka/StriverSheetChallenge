/* Question link:
https://www.codingninjas.com/studio/problems/job-sequencing-problem_1169460 */

// Solution: Standard Greedy problem sort the array in descending order as profits as criteria 


#include <bits/stdc++.h> 
bool static cmp(const vector<int>& v1,const vector<int>& v2 )
{
    return v1[1]>v2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int k=jobs[0][0];
    int n=jobs.size();
    for(int i=0;i<n;i++)
    {
        k=max(k,jobs[i][0]);
    }
    int profit=0;
    sort(jobs.begin(),jobs.end(),cmp);
    vector<int> slot(k+1,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i][0];j>0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j] =i;
                profit+=jobs[i][1];
                break;
            }

        }
    }
    return profit;
}
