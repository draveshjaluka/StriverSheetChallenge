/* Question link:
https://leetcode.com/problems/sort-colors/
https://bit.ly/3tlM60B */

//Solution 1: used simple couting technique to achieve the result not an efficient solution since I needed to traverse the arrray twice
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)  c0++;
            else if(nums[i]==1) c1++;
            else if(nums[i]==2) c2++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(c0>0)
            {
                nums[i]=0;c0--;
            }

            else if(c1>0)
            {
                nums[i]=1;c1--;
            }

            else
            {
                nums[i]=2;c2--;
            }

        }

        return ;
    }
};

/*Solution 2: In Conding Ninjas it was directed to do this in one pass and in place, then used two pointer approach to solve the problem, used one pointer L 
and 0 will always behind this pointer, now second pointer H and 2 will always be after this pointer, and 1 would lie in between them*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h)
        {
            if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                l++;m++;
            }
            else if(nums[m]==1){m++;}
            else
            {
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};
