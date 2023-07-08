/* Question Link
https://www.codingninjas.com/studio/problems/longest-common-prefix_628874
https://leetcode.com/problems/longest-common-prefix/ */

/*Solution 1: Simple solution was to sort the given string array to get the smallest word and then compare it with the largest word to get the prefix */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        if(!strs.size())
        {
            return ans;
        }
        sort(strs.begin(),strs.end());
        string f=strs[0],e=strs[strs.size()-1];
        
        for(int i=0;i<f.size();i++)
        {
            if(f[i]==e[i])
            {
                ans+=f[i];
            }
            else break;
        }
        return ans;
    }
};
