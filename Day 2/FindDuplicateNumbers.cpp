/* Question link:
https://leetcode.com/problems/find-the-duplicate-number/
https://www.codingninjas.com/studio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge&leftPanelTab=1 */

/* Solution: Was asked do it in one pass(i.e. O(n*n) not allowed) and using constant space, therefore used two pointers approach and found out cycle forming while doing dry run hence was clear to go ahead with the solution */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        //return fast;
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
    
}; 
