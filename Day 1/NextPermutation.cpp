/* Question Link:
https://leetcode.com/problems/next-permutation/
https://www.codingninjas.com/codestudio/problems/next-greater-permutation_6929564 */

//This question was the toughest of this day, if you are attempting it
//Refer to this link: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
//Changed the algo to write better code

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k=-1,l=-1;
        int s=nums.size();
        for(int i=s-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                k=i;
                break;
            }
        }
        
        if(k==-1) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
      
        else
        {
        for(int i=s-1;i>=0;i--)
        {
            
            if(nums[i]>nums[k])
            {
                l=i;
                break;
            }
        }
        
        swap(nums[k],nums[l]);
        
        reverse(nums.begin()+k+1,nums.end());}
    }
};
