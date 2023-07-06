/* Question Links: 
https://leetcode.com/problems/pascals-triangle/
https://www.codingninjas.com/codestudio/problems/print-pascal-s-triangle_6917910*/

//Pretty Straight forward Solution

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(numRows==0)
            return ans;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1)
            return ans;
        
        for(int i=1;i<numRows;i++)
        {
            vector<int> t;
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)
                {
                    t.push_back(1);

                }
                else
                {
                t.push_back(ans[i-1][j]+ans[i-1][j-1]);
                
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
