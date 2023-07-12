/* Question link: 
https://leetcode.com/problems/max-consecutive-ones/
https://www.codingninjas.com/codestudio/problems/892994?topList=striver-sde-sheet-problems */

/* Solution: Simple count and ans variable as max storage */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1){count++; ans=max(ans,count);}
            else 
            {count=0;}
        }
        return ans;
    }
};
