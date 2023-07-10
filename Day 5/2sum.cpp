/* Question Link
https://leetcode.com/problems/two-sum/
https://www.codingninjas.com/codestudio/problems/reading_6845742 */

/* Solution: create a map and push values in it and check if there exists a number in the map or not such that it value is target-curr_number if yes push their
positions in the answer */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int s=nums.size();
        map<int,int> m;
        vector<int>ans;
        for(int i=0;i<s;i++)
        {
            int t= target-nums[i];
            if(m.find(t)!=m.end())
            {
                cout<<t<<"::"<<m[t]<<endl;
                ans.push_back(m[t]);
                ans.push_back(i);
                break;
            }
         m[nums[i]]=i;
        }
        return ans;
    }
};
