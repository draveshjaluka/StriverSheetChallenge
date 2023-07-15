/*Question Link:
https://leetcode.com/problems/subsets-ii/ */

/* Solution: Storing non duplicate subset, would recommend to watch striver */

class Solution {
public:
    void solver(int i, vector<int> &nums,vector<int>&temp,vector<vector<int>> &ans)
    {
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++)
        {
            if( j!=i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            solver(j+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solver(0,nums,temp,ans);
        return ans;
    }
};
