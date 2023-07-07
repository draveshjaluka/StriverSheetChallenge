/* Question Link
https://leetcode.com/problems/merge-intervals/description/
https://www.codingninjas.com/studio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge */

/* Was asked to provide in-place solution and in O(n) brute force would have been simple traversing of O(n*n), took a bit of time to think about
the solution but got in 3-4 mins Intuition was first sort the given array with reference to the first member of the row and then checking the last
member of the current position with the first member of the next position then merge accordingly and update ans when the criteria do not meet */

class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int s=in.size();
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(in[0][0]);
        temp.push_back(in[0][1]);
        for(int i=1;i<s;i++)
        {
            
            if(temp[1]>=in[i][0])
            {
                if(temp[1]<=in[i][1])
                    temp[1]=in[i][1];
            }
            else
            {
            ans.push_back(temp);
            temp[0]=in[i][0];
            temp[1]=in[i][1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
