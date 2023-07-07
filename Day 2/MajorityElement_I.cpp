/* Question Link: 
https://leetcode.com/problems/majority-element/ */

//Solution: Asked to do without using extra space, used a simple ans variable to store answer and a counter/flag variable to take action

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e,c=0;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            if(c==0){c=1; e=nums[i];}
            else if(nums[i]==e) c++;
            else c--;
        }
        c=0;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==e)c++;
            }
        int m= (nums.size()/2) +1;
        if(c>=m) ans=e;
        return ans;
    }
        
};
