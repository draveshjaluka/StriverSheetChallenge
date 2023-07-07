/* Question Link
https://leetcode.com/problems/merge-sorted-array/
https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays_8230835?challengeSlug=striver-sde-challenge&leftPanelTab=1 */

//Solution straigforward merging

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(j>=0)
        {
            if(i>=0 &&  nums1[i]> nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else
                nums1[k--]=nums2[j--];
        }
    }
};
