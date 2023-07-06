/* Question Link:
https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_6194560
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ */

//One of the basic question of DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int m=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            ans=max(ans,prices[i]-m);
            m=min(m,prices[i]);
        }
        return ans;
    }
};

//P.S I am always scared of DP
