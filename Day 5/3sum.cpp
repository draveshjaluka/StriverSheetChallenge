/* Question link
https://leetcode.com/problems/3sum/  
https://bit.ly/33wlWxk */

/* Solution: pretty simple by taking inspiration from 2sum, i used simple loops to find the triplets, fixed one number and find suitable othe two numbers such that
they add up to the target, needed to sort the data in order to do so*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; int n=nums.size();
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || nums[i-1]!=nums[i]) 
            {
                int j=i+1,k=n-1;
                int s=-nums[i];
                while(j<k)
                {
                    if(nums[j]+nums[k]== s)
                    {
                        ans.push_back({nums[i],nums[j],nums[k]});
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[k]==nums[k-1]) k--;
                        j++;k--;
                    }
                else if(nums[j]+nums[k]<s) j++;
                else k--;
                }
            }
        }
        return ans;
    }
};  
