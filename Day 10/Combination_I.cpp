/* Question Link:
https://leetcode.com/problems/combination-sum/  */

/* Solution: Suggestion watch striver recursion playlist to understand better */

class Solution {
public:
    void solver(int i,vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,int target)
    {
        if(i==nums.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(nums[i]<=target)
        {
            temp.push_back(nums[i]);
            solver(i,nums,ans,temp,target-nums[i]);
            temp.pop_back();
        }
        solver(i+1,nums,ans,temp,target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solver(0,nums,ans,temp,target);
        return ans;
    }
};
