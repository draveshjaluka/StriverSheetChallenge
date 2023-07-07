/* Question Link: 
https://leetcode.com/problems/majority-element/ */

/*Solution: Asked to do without using extra space and linear time, looked at it carefully and saw that only one such number is possible hence took a counter
variable and an element variable and applied the logic of canceling out the count if other numbers were seen */

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
