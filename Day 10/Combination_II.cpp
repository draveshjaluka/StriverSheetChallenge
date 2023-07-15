/* Question Link:
https://leetcode.com/problems/combination-sum-ii/ */

/* Solution: Suggestion striver recursion video */

class Solution {
public:
    void solver(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1])continue;
            if(nums[j]>target) break;
            temp.push_back(nums[j]);
            solver(j+1,nums,temp,ans,target-nums[j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solver(0,nums,temp,ans,target);
        return ans;
    }
};
