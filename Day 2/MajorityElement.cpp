/* Question Link: 
https://leetcode.com/problems/majority-element/ */

//Solution: Asked to do without using extra space, used a simple ans variable to store answer and a counter/flag variable to take action

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(c==0) e=nums[i];
            if(nums[i]==e) c++;
            else c--;
        }
        return e;
    }
};
