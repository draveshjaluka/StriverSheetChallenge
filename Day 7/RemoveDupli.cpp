/* Question Link: 
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
https://bit.ly/33bNQPo */

/* Solution: Was asked to solve simple question inplace and O(n) */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]) {
            nums[k]=nums[i];k++;}
        }
        return k;
    }
};
